--- src/display.cc.orig	2015-04-15 08:00:23 UTC
+++ src/display.cc
@@ -20,7 +20,7 @@ void StackTracesPrinter::PrintStackTrace
     if (traces[i].count != 0) {
       total += traces[i].count;
       count++;
-      fprintf(file_, "%"PRIdPTR" ", traces[i].count);
+      fprintf(file_, "%" PRIdPTR" ", traces[i].count);
       PrintStackTrace(&traces[i]);
       fprintf(file_, "\n");
     }
