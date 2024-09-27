# Allow fake device file to use with fstab(5)

--- src/simple-mtpfs-fuse.cpp.orig	2015-08-24 11:34:39 UTC
+++ src/simple-mtpfs-fuse.cpp
@@ -309,12 +309,6 @@ bool SMTPFileSystem::parseOptions(int ar
 
     --m_options.m_device_no;
 
-    // device file and -- device are mutually exclusive, fail if both set
-    if (m_options.m_device_no && m_options.m_device_file) {
-        m_options.m_good = false;
-        return false;
-    }
-
     m_options.m_good = true;
     return true;
 }
@@ -379,11 +373,9 @@ bool SMTPFileSystem::exec()
         return false;
     }
 
-    if (m_options.m_device_file) {
-        // Try to use device file first, if provided
-        if (!m_device.connect(m_options.m_device_file))
-            return false;
-    } else {
+    // Try to use device file first, ignore otherwise
+    if (!m_options.m_device_file ||
+        !m_device.connect(m_options.m_device_file)) {
         // Connect to MTP device by order number, if no device file supplied
         if (!m_device.connect(m_options.m_device_no))
             return false;
