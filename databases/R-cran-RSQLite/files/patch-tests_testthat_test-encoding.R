Fix to skip a windows only test that does not exclude FreeBSD.
https://github.com/r-dbi/RSQLite/pull/504

--- tests/testthat/test-encoding.R.orig	2024-01-20 09:56:34 UTC
+++ tests/testthat/test-encoding.R
@@ -34,9 +34,7 @@ test_that("list the field of tables whose colnames are
 })
 
 test_that("list the field of tables whose colnames are BIG5 encoded (#277)", {
-  skip_on_os("linux")
-  skip_on_os("mac")
-  skip_on_os("solaris")
+  skip_if_not(.Platform$OS.type == "windows")
   if (.Platform$OS.type == "windows") {
     withr::local_collate("cht")
   } else {
@@ -133,9 +131,7 @@ test_that("write tables whose colnames or contents are
 })
 
 test_that("write tables whose colnames or contents are BIG5 encoded (#277)", {
-  skip_on_os("linux")
-  skip_on_os("mac")
-  skip_on_os("solaris")
+  skip_if_not(.Platform$OS.type == "windows")
 
   .loc <- Sys.getlocale("LC_COLLATE")
   suppressWarnings(Sys.setlocale(locale = "cht"))
