--- ./platform/emulator/libdp/comObj.cc.orig	Mon Apr 28 08:32:28 2003
+++ ./platform/emulator/libdp/comObj.cc	Sat Sep  3 18:46:09 2005
@@ -7,8 +7,8 @@
  *  Copyright:
  * 
  *  Last change:
- *    $Date: 2003/04/28 12:32:28 $ by $Author: glynn $
- *    $Revision: 1.56 $
+ *    $Date: 2005/02/22 14:25:31 $ by $Author: valentin $
+ *    $Revision: 1.56.8.2 $
  * 
  *  This file is part of Mozart, an implementation 
  *  of Oz 3:
@@ -376,8 +376,15 @@
   localRef=FALSE;
   if(hasNeed()) 
     return FALSE;
-  else if(remoteRef)
+  else if(remoteRef) {
+    if(!sentclearref && (state == WORKING)) {
+      MsgContainer *msgC=msgContainerManager->newMsgContainer(NULL);
+      msgC->put_C_CLEAR_REFERENCE();
+      send(msgC);
+      sentclearref=TRUE;
+    }
     return FALSE;
+  }
   else {
     switch(state) {
     case WORKING: {
