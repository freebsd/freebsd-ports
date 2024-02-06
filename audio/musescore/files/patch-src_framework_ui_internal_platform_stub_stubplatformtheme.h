--- src/framework/ui/internal/platform/stub/stubplatformtheme.h.orig	2024-02-08 19:49:29 UTC
+++ src/framework/ui/internal/platform/stub/stubplatformtheme.h
@@ -29,6 +29,7 @@ namespace mu::ui {
 class StubPlatformTheme : public IPlatformTheme
 {
 public:
+    ~StubPlatformTheme() override;
     void startListening() override;
     void stopListening() override;
 
