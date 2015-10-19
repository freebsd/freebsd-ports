--- src/appwin_base.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/appwin_base.cpp
@@ -25,6 +25,7 @@
 #include "prefs.h"
 #include "lang.h"
 
+#include "compat.h"
 #include "scidoc.h"
 #include "filer.h"
 #include "toolmgr.h"
@@ -45,7 +46,6 @@
 #include "cmd_utils.h"
 #include "scidoc_util.h"
 #include "foreachtab.h"
-#include "compat.h"
 
 #include "intl.h"
 #include "appwin_base.h"
@@ -405,7 +405,14 @@ long TopWindowBase::onTimer(FXObject*o, 
 long TopWindowBase::onCloseWait(FXObject*o, FXSelector sel, void*p)
 {
   if (FXSELTYPE(sel)==SEL_CHORE) {
-    getApp()->addTimeout(this,ID_CLOSEWAIT, ONE_SECOND/10, NULL);
+    static FXint CloseWaitChoreCount=10;
+    if (CloseWaitChoreCount>0) {
+      CloseWaitChoreCount--;
+      getApp()->addChore(this,ID_CLOSEWAIT, NULL);
+    } else {
+      CloseWaitChoreCount=10;
+      getApp()->addTimeout(this,ID_CLOSEWAIT, ONE_SECOND/10, NULL);
+    }
   } else {
     close();
   }
@@ -1246,7 +1253,12 @@ void TopWindowBase::ParseCommands(FXStri
             FXString filename=sect.text();
             if (rowcol.empty()) {
               FXint beg,end;
-              if (rx_rowcol.match(filename,&beg,&end)) {
+#ifdef FOX_1_7_50_OR_NEWER
+              if (rx_rowcol.search(filename,0,filename.length(),Normal,&beg,&end,1)>=0)
+#else
+              if (rx_rowcol.match(filename,&beg,&end))
+#endif
+              {
                 if (!FXStat::isFile(filename)) {
                   rowcol=filename.mid(beg,end-beg).text();
                   filename=filename.left(beg).text();
