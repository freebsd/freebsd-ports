--- subcommander/DiffSummarizeLvi.cpp.orig	2007-08-04 16:22:10.000000000 +0900
+++ subcommander/DiffSummarizeLvi.cpp	2012-05-10 05:41:05.000000000 +0900
@@ -13,7 +13,7 @@
 #include "svn/DiffSummarize.h"
 
 
-static char* getSummarizeCode( svn::DiffSummarizeKind kind )
+static char* const getSummarizeCode( svn::DiffSummarizeKind kind )
 {
   switch( kind )
   {
@@ -25,7 +25,7 @@
   }
 }
 
-static char* getNodCode( svn::NodeKind kind )
+static char* const getNodCode( svn::NodeKind kind )
 {
   switch( kind )
   {
