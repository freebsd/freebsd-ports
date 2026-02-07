--- src/framework/ui/internal/platform/stub/stubplatformtheme.cpp.orig	2025-01-16 06:38:51 UTC
+++ src/framework/ui/internal/platform/stub/stubplatformtheme.cpp
@@ -25,6 +25,8 @@ using namespace muse::async;
 using namespace muse::ui;
 using namespace muse::async;
 
+StubPlatformTheme::~StubPlatformTheme() = default;
+
 void StubPlatformTheme::startListening()
 {
 }
