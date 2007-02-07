--- plugins/vidinput_v4l/vidinput_v4l.cxx.orig	Wed Jan  3 23:37:37 2007
+++ plugins/vidinput_v4l/vidinput_v4l.cxx	Wed Feb  7 01:30:50 2007
@@ -484,6 +484,15 @@
         struct stat s;
         if (lstat(devname, &s) == 0) {
  
+#if defined(P_FREEBSD)
+	  // device numbers are irrelevant here, so we match on names instead.
+          if (filename.GetLength() <= 5 || filename.Left(5) != "video")
+		continue;
+	  int num = atoi(filename.Mid(6));
+	  if (num < 0 || num > 63)
+		continue;
+          vid.SetAt(num, devname);
+#else
           static const int deviceNumbers[] = { 81 };
           for (PINDEX i = 0; i < PARRAYSIZE(deviceNumbers); i++) {
             if (MAJOR(s.st_rdev) == deviceNumbers[i]) {
@@ -493,6 +502,7 @@
               }
             }
           }
+#endif
         }
       }
     }
