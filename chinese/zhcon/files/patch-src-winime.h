--- src/winime.h.orig	Tue Apr 25 00:38:26 2006
+++ src/winime.h	Wed Jul 19 22:27:58 2006
@@ -68,6 +68,12 @@
         bool IsGB2312_2(char c) const {
             return c >= 0xA1 && c <= 0xFE;
         }
+        bool IsBIG5_1(char c) const {
+            return c >= 0xA1 && c <= 0xFE;
+        }
+        bool IsBIG5_2(char c) const {
+            return c >= 0x40 && c <= 0x7E;
+        }
 
         void AddCandilist(char*& p,unsigned& buflen);
         void SkipNext(char*& rp);
