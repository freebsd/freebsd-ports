--- Framework/PCAddFilesPanel.m.orig	2008-12-30 14:47:27.000000000 +0100
+++ Framework/PCAddFilesPanel.m	2012-06-08 21:48:32.000000000 +0200
@@ -1,9 +1,10 @@
 /*
    GNUstep ProjectCenter - http://www.gnustep.org/experience/ProjectCenter.html
 
-   Copyright (C) 2004 Free Software Foundation
+   Copyright (C) 2004-2011 Free Software Foundation
 
    Authors: Serg Stoyan
+            Riccardo Mottola
 
    This file is part of GNUstep.
 
@@ -93,7 +94,7 @@
 {
   NSString  *path = nil;
 
-  ASSIGN(_fileTypes, fileTypes);
+  [super setAllowedFileTypes: fileTypes];
 
   path = [_browser path];
   [self validateVisibleColumns];
