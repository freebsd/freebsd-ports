$FreeBSD$

--- ../../j2se/src/solaris/classes/sun/tools/attach/BSDAttachProvider.java	10 May 2007 05:38:51 -0000	1.1
+++ ../../j2se/src/solaris/classes/sun/tools/attach/BSDAttachProvider.java	2 Feb 2009 00:27:30 -0000
@@ -14,7 +14,7 @@
 import java.io.IOException;
 
 /*
- * An AttachProvider implementation for Linux that uses a UNIX domain
+ * An AttachProvider implementation for BSD that uses a UNIX domain
  * socket.
  */
 public class BSDAttachProvider extends HotSpotAttachProvider {
@@ -36,12 +36,28 @@
     public VirtualMachine attachVirtualMachine(String vmid)
 	throws AttachNotSupportedException, IOException
     {
-        throw new AttachNotSupportedException("Attach not yet supported on BSD");
+        if (isNotAttachable(vmid)) {
+            throw new AttachNotSupportedException("can only attach to Java SE 6.0 or newer");
+        }
+        return new BSDVirtualMachine(this, vmid);
     }
 
     public VirtualMachine attachVirtualMachine(VirtualMachineDescriptor vmd)
         throws AttachNotSupportedException, IOException
     {
-        throw new AttachNotSupportedException("Attach not yet supported on BSD");
+        if (vmd.provider() != this) {
+             throw new AttachNotSupportedException("provider mismatch");
+        }
+        // To avoid re-checking if the VM if attachable, we check if the descriptor
+        // is for a hotspot VM - these descriptors are created by the listVirtualMachines
+        // implementation which only returns a list of attachable VMs.
+        if (vmd instanceof HotSpotVirtualMachineDescriptor) {
+            assert ((HotSpotVirtualMachineDescriptor)vmd).isAttachable();
+            checkAttachPermission();
+            return new BSDVirtualMachine(this, vmd.id());
+        } else {
+            return attachVirtualMachine(vmd.id());
+        }
     }
+
 }
