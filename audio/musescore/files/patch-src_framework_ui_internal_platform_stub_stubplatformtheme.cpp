--- src/framework/ui/internal/platform/stub/stubplatformtheme.cpp.orig	2024-02-08 19:49:06 UTC
+++ src/framework/ui/internal/platform/stub/stubplatformtheme.cpp
@@ -25,6 +25,8 @@
 using namespace mu::ui;
 using namespace mu::async;
 
+namespace mu::ui {
+StubPlatformTheme::~StubPlatformTheme() = default;
 void StubPlatformTheme::startListening()
 {
 }
@@ -59,4 +61,5 @@ void StubPlatformTheme::applyPlatformStyleOnAppForThem
 
 void StubPlatformTheme::applyPlatformStyleOnWindowForTheme(QWindow*, const ThemeCode&)
 {
+}
 }
