--- src/VBox/Frontends/VBoxManage/VBoxManageHelp.cpp.orig	2020-05-13 19:43:27 UTC
+++ src/VBox/Frontends/VBoxManage/VBoxManageHelp.cpp
@@ -622,7 +622,7 @@ void printUsage(USAGECATEGORY fCategory, uint32_t fSub
             RTStrmPrintf(pStrm, "|dsound");
 #endif
         }
-        if (fLinux || fSolaris)
+        if (fLinux || fFreeBSD || fSolaris)
         {
             RTStrmPrintf(pStrm, ""
 #ifdef VBOX_WITH_AUDIO_OSS
@@ -635,22 +635,6 @@ void printUsage(USAGECATEGORY fCategory, uint32_t fSub
                                 "|pulse"
 #endif
                         );
-        }
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
         }
         if (fDarwin)
         {
