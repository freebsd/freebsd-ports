--- src/VBox/Frontends/VBoxManage/VBoxManageHelp.cpp.orig	2016-08-16 19:59:52 UTC
+++ src/VBox/Frontends/VBoxManage/VBoxManageHelp.cpp
@@ -797,7 +797,7 @@ void printUsage(USAGECATEGORY fCategory,
             RTStrmPrintf(pStrm, "|dsound");
 #endif
         }
-        if (fLinux || fSolaris)
+        if (fLinux || fFreeBSD || fSolaris)
         {
             RTStrmPrintf(pStrm, ""
 #ifdef VBOX_WITH_AUDIO_OSS
@@ -811,22 +811,6 @@ void printUsage(USAGECATEGORY fCategory,
 #endif
                         );
         }
-        if (fFreeBSD)
-        {
-#ifdef VBOX_WITH_AUDIO_OSS
-            /* Get the line break sorted when dumping all option variants. */
-            if (fDumpOpts)
-            {
-                RTStrmPrintf(pStrm, "|\n"
-                     "                                     oss");
-            }
-            else
-                RTStrmPrintf(pStrm, "|oss");
-#endif
-#ifdef VBOX_WITH_AUDIO_PULSE
-            RTStrmPrintf(pStrm, "|pulse");
-#endif
-        }
         if (fDarwin)
         {
             RTStrmPrintf(pStrm, "|coreaudio");
