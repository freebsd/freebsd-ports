--- src/VBox/Frontends/VBoxManage/VBoxManageHelp.cpp.orig	2009-12-15 15:16:21.000000000 +0900
+++ src/VBox/Frontends/VBoxManage/VBoxManageHelp.cpp	2009-12-15 15:14:01.000000000 +0900
@@ -41,6 +41,11 @@
 #else
     bool fSolaris = false;
 #endif
+#ifdef RT_OS_FREEBSD
+    bool fFreeBSD = true;
+#else
+    bool fFreeBSD = false;
+#endif
 #ifdef RT_OS_DARWIN
     bool fDarwin = true;
 #else
@@ -62,6 +67,7 @@
         fLinux = true;
         fWin = true;
         fSolaris = true;
+	fFreeBSD = true;
         fDarwin = true;
         fVRDP = true;
         fVBoxSDL = true;
@@ -227,6 +233,14 @@
 #endif
                                              );
         }
+        if (fFreeBSD)
+        {
+            RTPrintf(                        "|oss"
+#ifdef VBOX_WITH_PULSE
+                                             "|pulse"
+#endif
+                                             );
+        }
         if (fDarwin)
         {
             RTPrintf(                        "|coreaudio");
