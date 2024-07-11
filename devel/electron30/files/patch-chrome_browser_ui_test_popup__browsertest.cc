--- chrome/browser/ui/test/popup_browsertest.cc.orig	2023-08-10 01:48:36 UTC
+++ chrome/browser/ui/test/popup_browsertest.cc
@@ -74,7 +74,7 @@ IN_PROC_BROWSER_TEST_F(PopupTest, OpenLeftAndTopZeroCo
   const display::Display display = GetDisplayNearestBrowser(popup);
   gfx::Rect expected(popup->window()->GetBounds().size());
   expected.AdjustToFit(display.work_area());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/1286870) Desktop Linux window bounds are inaccurate.
   expected.Outset(50);
   EXPECT_TRUE(expected.Contains(popup->window()->GetBounds()))
@@ -106,7 +106,7 @@ IN_PROC_BROWSER_TEST_F(PopupTest, OpenClampedToCurrent
     // The popup should be constrained to the opener's available display space.
     EXPECT_EQ(display, GetDisplayNearestBrowser(popup));
     gfx::Rect work_area(display.work_area());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/1286870) Desktop Linux bounds flakily extend outside the
     // work area on trybots, when opening with excessive width and height, e.g.:
     // width=${screen.availWidth+300},height=${screen.availHeight+300} yields:
