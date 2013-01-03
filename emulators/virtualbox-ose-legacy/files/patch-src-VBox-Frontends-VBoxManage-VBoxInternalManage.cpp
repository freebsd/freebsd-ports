- Add support for files to VBoxManage createrawvmdk. Currently
it only supports character devices so it failes like this:

VBoxManage internalcommands createrawvmdk -filename test.vmdk -rawdisk /vbox/HardDisks/test.img
VBoxManage: error: File '/vbox/HardDisks/test.img' is no character device
VBoxManage: error: The raw disk vmdk file was not created

Submitted by:	Pawel Jakub Dawidek <pjd@FreeBSD.org>
--- src/VBox/Frontends/VBoxManage/VBoxInternalManage.cpp.orig	2011-12-13 11:18:43.424439415 +0100
+++ src/VBox/Frontends/VBoxManage/VBoxInternalManage.cpp	2011-12-13 11:22:01.554438862 +0100
@@ -1140,9 +1140,13 @@
             goto out;
         }
     }
+    else if (S_ISREG(DevStat.st_mode))
+    {
+        cbSize = DevStat.st_size;
+    }
     else
     {
-        RTMsgError("File '%s' is no character device", rawdisk.c_str());
+        RTMsgError("File '%s' is neither character device nor regular file", rawdisk.c_str());
         vrc = VERR_INVALID_PARAMETER;
         goto out;
     }
