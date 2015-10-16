--- src/fxasq.h.orig	2013-10-03 09:22:51 UTC
+++ src/fxasq.h
@@ -17,8 +17,11 @@
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
 
+#ifndef FXASQ_H
+#define FXASQ_H
 
 #include "fxasq_c.h"
+#include "compat.h"
 
 
 class FxAsqWin: public FXObject {
@@ -33,7 +36,7 @@ class FxAsqWin: public FXObject {
     void AppendResult(const char*key, const char*value);
     void PutResults();
   protected:
-    FXDict keylist;
+    Dictionary keylist;
     FXVerticalFrame *userbox;
   public:
 
@@ -55,4 +58,5 @@ class FxAsqWin: public FXObject {
     void Color(    const char*key, const char*value, const char*label);
     void Font(     const char*key, const char*value, const char*label);
 };
+#endif
 
