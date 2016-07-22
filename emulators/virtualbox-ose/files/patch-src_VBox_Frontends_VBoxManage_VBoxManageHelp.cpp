--- src/VBox/Frontends/VBoxManage/VBoxManageHelp.cpp.orig	2016-07-18 11:55:55 UTC
+++ src/VBox/Frontends/VBoxManage/VBoxManageHelp.cpp
@@ -791,7 +791,7 @@ void printUsage(USAGECATEGORY fCategory,
             RTStrmPrintf(pStrm, "|dsound");
 #endif
         }
-        if (fLinux || fSolaris)
+        if (fLinux || fFreeBSD || fSolaris)
         {
             RTStrmPrintf(pStrm, ""
 #ifdef VBOX_WITH_OSS
@@ -805,22 +805,6 @@ void printUsage(USAGECATEGORY fCategory,
 #endif
                         );
         }
-        if (fFreeBSD)
-        {
-#ifdef VBOX_WITH_OSS
-            /* Get the line break sorted when dumping all option variants. */
-            if (fDumpOpts)
-            {
-                RTStrmPrintf(pStrm, "|\n"
-                     "                                     oss");
-            }
-            else
-                RTStrmPrintf(pStrm, "|oss");
-#endif
-#ifdef VBOX_WITH_PULSE
-            RTStrmPrintf(pStrm, "|pulse");
-#endif
-        }
         if (fDarwin)
         {
             RTStrmPrintf(pStrm, "|coreaudio");
