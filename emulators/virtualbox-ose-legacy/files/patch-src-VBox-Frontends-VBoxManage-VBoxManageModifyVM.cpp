--- src/VBox/Frontends/VBoxManage/VBoxManageModifyVM.cpp.orig	2009-09-09 23:39:46.000000000 +0900
+++ src/VBox/Frontends/VBoxManage/VBoxManageModifyVM.cpp	2009-12-15 15:22:27.000000000 +0900
@@ -1478,6 +1478,20 @@
 # endif
 
 #endif /* !RT_OS_SOLARIS */
+#ifdef RT_OS_FREEBSD
+                else if (!strcmp(ValueUnion.psz, "oss"))
+                {
+                    CHECK_ERROR(audioAdapter, COMSETTER(AudioDriver)(AudioDriverType_OSS));
+                    CHECK_ERROR(audioAdapter, COMSETTER(Enabled)(true));
+                }
+# ifdef VBOX_WITH_PULSE
+                else if (!strcmp(ValueUnion.psz, "pulse"))
+                {
+                    CHECK_ERROR(audioAdapter, COMSETTER(AudioDriver)(AudioDriverType_Pulse));
+                    CHECK_ERROR(audioAdapter, COMSETTER(Enabled)(true));
+                }
+# endif
+#endif /* !RT_OS_FREEBSD */
 #ifdef RT_OS_DARWIN
                 else if (!strcmp(ValueUnion.psz, "coreaudio"))
                 {
