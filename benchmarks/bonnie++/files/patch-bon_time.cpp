--- bon_time.cpp.orig	2019-09-02 11:43:11 UTC
+++ bon_time.cpp
@@ -146,7 +146,7 @@ int BonTimer::print_stat(tests_t test, i
         }
         else
         {
-          fprintf(m_fp, " %5d", stat);
+          fprintf(m_fp, " %5f", stat);
         }
       }
       else
