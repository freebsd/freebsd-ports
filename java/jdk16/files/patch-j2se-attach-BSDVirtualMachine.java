$FreeBSD$

--- ../../j2se/src/solaris/classes/sun/tools/attach/BSDVirtualMachine.java	2 Feb 2009 00:28:15 -0000
+++ ../../j2se/src/solaris/classes/sun/tools/attach/BSDVirtualMachine.java	2 Feb 2009 00:28:15 -0000
@@ -0,0 +1,292 @@
+/*
+ * @(#)BSDVirtualMachine.java        1.8 06/03/05
+ *
+ * Copyright 2006 Sun Microsystems, Inc. All rights reserved.
+ * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
+ */
+package sun.tools.attach;
+
+import com.sun.tools.attach.VirtualMachine;
+import com.sun.tools.attach.AgentLoadException;
+import com.sun.tools.attach.AttachNotSupportedException;
+import com.sun.tools.attach.spi.AttachProvider;
+import java.io.InputStream;
+import java.io.IOException;
+import java.io.File;
+import java.util.Properties;
+
+/*
+ * BSD implementation of HotSpotVirtualMachine
+ */
+public class BSDVirtualMachine extends HotSpotVirtualMachine {
+
+    /**
+     * Hard-coded "/tmp" to match the hotspot bsd implementation
+     * hotspot/src/os/bsd/vm/os_bsd.cpp:
+     * const char* os::get_temp_directory() { return "/tmp/"; }
+     */
+    private static String getTmpDir() {
+        return "/tmp/";
+    }
+
+
+    String path;
+
+    /**
+     * Attaches to the target VM 
+     */
+    BSDVirtualMachine(AttachProvider provider, String vmid) 
+        throws AttachNotSupportedException, IOException
+    {
+        super(provider, vmid);
+
+        // This provider only understands pids 
+        int pid;
+        try {
+            pid = Integer.parseInt(vmid);
+        } catch (NumberFormatException x) {
+            throw new AttachNotSupportedException("Invalid process identifier");
+        }
+
+        // Find the socket file. If not found then we attempt to start the
+        // attach mechanism in the target VM by sending it a QUIT signal.
+        // Then we attempt to find the socket file again.
+        path = findSocketFile(pid);
+        if (path == null) {
+
+            String fn = ".attach_pid" + pid;
+            path = getTmpDir() + fn;
+            File attachFile = new File(path);
+            createAttachFile(path);
+            try {
+                sendQuitTo(pid);
+
+                // give the target VM time to start the attach mechanism
+                int i = 0;
+                long delay = 200;
+                int retries = (int)(attachTimeout() / delay);
+                do {
+                    try {
+                        Thread.sleep(delay);
+                    } catch (InterruptedException x) { }
+                    path = findSocketFile(pid);
+                    i++;
+                } while (i <= retries && path == null);
+                if (path == null) {
+                    throw new AttachNotSupportedException(
+                        "Unable to open socket file: target process not responding " +
+                        "or HotSpot VM not loaded");
+                }
+            } finally {
+                attachFile.delete();
+            }
+        }
+
+        // Check that the file owner/permission to avoid attaching to
+        // bogus process
+        checkPermissions(path);
+
+        // Check that we can connect to the process
+        // - this ensures we throw the permission denied error now rather than
+        // later when we attempt to enqueue a command.
+        int s = socket();
+        try {
+            connect(s, path);
+        } finally {
+            close(s);
+        }
+    }
+
+    /**
+     * Detach from the target VM
+     */
+    public void detach() throws IOException {
+        synchronized (this) {
+            if (this.path != null) {
+                this.path = null;
+            }
+        }
+    }
+
+    // protocol version
+    private final static String PROTOCOL_VERSION = "1";
+
+    // known errors
+    private final static int ATTACH_ERROR_BADVERSION = 101;
+      
+    /**
+     * Execute the given command in the target VM.
+     */ 
+    InputStream execute(String cmd, Object ... args) throws AgentLoadException, IOException {
+        assert args.length <= 3;                // includes null
+
+        // did we detach?
+        String p;
+        synchronized (this) {
+            if (this.path == null) {
+                throw new IOException("Detached from target VM");
+            }
+            p = this.path;
+        }
+
+        // create UNIX socket
+        int s = socket();
+
+        // connect to target VM
+        try {
+            connect(s, p);
+        } catch (IOException x) {
+            close(s);
+            throw x;
+        }
+
+        IOException ioe = null;
+
+        // connected - write request
+           // <ver> <cmd> <args...>
+        try {
+            writeString(s, PROTOCOL_VERSION);
+            writeString(s, cmd);
+
+            for (int i=0; i<3; i++) {
+                if (i < args.length && args[i] != null) {
+                    writeString(s, (String)args[i]);
+                } else {
+                    writeString(s, "");
+                }
+            }
+        } catch (IOException x) {
+            ioe = x;
+        }
+        
+
+        // Create an input stream to read reply
+        SocketInputStream sis = new SocketInputStream(s);
+
+        // Read the command completion status
+        int completionStatus;
+        try {
+            completionStatus = readInt(sis);
+        } catch (IOException x) {
+            sis.close();
+            if (ioe != null) {
+                throw ioe;
+            } else {
+                throw x;
+            }
+        }
+
+        if (completionStatus != 0) {
+            sis.close();
+
+            // In the event of a protocol mismatch then the target VM
+            // returns a known error so that we can throw a reasonable
+            // error.
+            if (completionStatus == ATTACH_ERROR_BADVERSION) {
+                throw new IOException("Protocol mismatch with target VM");
+            }
+
+            // Special-case the "load" command so that the right exception is
+            // thrown.
+            if (cmd.equals("load")) {
+                throw new AgentLoadException("Failed to load agent library");
+            } else {
+                throw new IOException("Command failed in target VM");
+            }
+        }
+
+        // Return the input stream so that the command output can be read
+        return sis;
+    }
+
+    /*
+     * InputStream for the socket connection to get target VM
+     */
+    private class SocketInputStream extends InputStream {
+        int s;
+
+        public SocketInputStream(int s) {
+            this.s = s;
+        }
+
+        public synchronized int read() throws IOException {
+            byte b[] = new byte[1];
+            int n = this.read(b, 0, 1);
+            if (n == 1) {
+                return b[0] & 0xff;
+            } else {
+                return -1;
+            }
+        }
+
+        public synchronized int read(byte[] bs, int off, int len) throws IOException {
+            if ((off < 0) || (off > bs.length) || (len < 0) ||
+                ((off + len) > bs.length) || ((off + len) < 0)) {
+                throw new IndexOutOfBoundsException();
+            } else if (len == 0)
+                return 0;
+
+            return BSDVirtualMachine.read(s, bs, off, len);
+        }
+
+        public void close() throws IOException {
+            BSDVirtualMachine.close(s);
+        }
+    }
+
+
+    // Return the socket file for the given process.
+    // Checks working directory of process for .java_pid<pid>. If not
+    // found it looks in /tmp.
+    private String findSocketFile(int pid) {
+        // First check for a .java_pid<pid> file in the working directory
+        // of the target process
+        String fn = ".java_pid" + pid;
+        String path = getTmpDir() + fn;
+        File f = new File(path);
+
+        if (!f.exists()) {
+            return null;            // not found
+        }
+        return path;
+    }
+
+    /*
+     * Write/sends the given to the target VM. String is transmitted in
+     * UTF-8 encoding.
+     */
+    private void writeString(int fd, String s) throws IOException {
+        if (s.length() > 0) {
+            byte b[];
+            try {
+                b = s.getBytes("UTF-8");
+            } catch (java.io.UnsupportedEncodingException x) { 
+                throw new InternalError();
+            }        
+            BSDVirtualMachine.write(fd, b, 0, b.length);
+        }
+        byte b[] = new byte[1];
+        b[0] = 0;
+        write(fd, b, 0, 1);
+    }
+
+
+    static native void sendQuitTo(int pid) throws IOException;
+
+    static native void checkPermissions(String path) throws IOException;
+
+    static native int socket() throws IOException;
+
+    static native void connect(int fd, String path) throws IOException;
+
+    static native void close(int fd) throws IOException;
+
+    static native int read(int fd, byte buf[], int off, int bufLen) throws IOException;
+
+    static native void write(int fd, byte buf[], int off, int bufLen) throws IOException;
+    static native void createAttachFile(String path);
+
+    static {
+        System.loadLibrary("attach");
+    }
+}
