--- ui/base/cursor/cursor_unittest.cc.orig	2026-08-14 04:06:34 UTC
+++ ui/base/cursor/cursor_unittest.cc
@@ -72,7 +72,7 @@ TEST(CursorTest, ClampHotspot) {
   EXPECT_EQ(gfx::Point(4, 6), cursor.custom_hotspot());
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 TEST(CursorTest, IsValidCursorThemeName) {
   EXPECT_TRUE(IsValidCursorThemeName("Adwaita"));
   EXPECT_TRUE(IsValidCursorThemeName("DMZ-White"));
