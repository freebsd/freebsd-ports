Fix build with Qt 6.9. QChar constructors no longer perform implicit
conversions.

--- core/libs/widgets/text/localizeselector.cpp.orig	2025-03-15 14:01:45 UTC
+++ core/libs/widgets/text/localizeselector.cpp
@@ -326,7 +326,7 @@ bool s_inlineTranslateString(const QString& text, cons
     }
     else
     {
-        error = QChar(trengine->error());
+        error = QChar(static_cast<int>(trengine->error()));
     }
 
     return false;
