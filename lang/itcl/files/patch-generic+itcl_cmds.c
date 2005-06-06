===================================================================
RCS file: /cvsroot/incrtcl/incrTcl/itcl/generic/itcl_cmds.c,v
retrieving revision 1.13
retrieving revision 1.15
diff -u -r1.13 -r1.15
--- generic/itcl_cmds.c	2001/05/22 01:50:21	1.13
+++ generic/itcl_cmds.c	2002/01/10 11:43:37	1.15
@@ -21,7 +21,7 @@
  *           mmclennan@lucent.com
  *           http://www.tcltk.com/itcl
  *
- *     RCS:  $Id: itcl_cmds.c,v 1.13 2001/05/22 01:50:21 davygrvy Exp $
+ *     RCS:  $Id: itcl_cmds.c,v 1.15 2002/01/10 11:43:37 davygrvy Exp $
  * ========================================================================
  *           Copyright (c) 1993-1998  Lucent Technologies, Inc.
  * ------------------------------------------------------------------------
@@ -469,7 +469,7 @@
     int forceFullNames = 0;
 
     char *pattern;
-    CONST char *name;
+    CONST char *cmdName;
     int newEntry, handledActiveNs;
     Tcl_HashTable unique;
     Tcl_HashEntry *entry;
@@ -477,7 +477,7 @@
     Itcl_Stack search;
     Tcl_Command cmd, originalCmd;
     Namespace *nsPtr;
-    Tcl_Obj *listPtr, *objPtr;
+    Tcl_Obj *objPtr;
 
     if (objc > 2) {
         Tcl_WrongNumArgs(interp, 1, objv, "?pattern?");
@@ -485,7 +485,7 @@
     }
 
     if (objc == 2) {
-        pattern = Tcl_GetStringFromObj(objv[1], (int*)NULL);
+        pattern = Tcl_GetString(objv[1]);
         forceFullNames = (strstr(pattern, "::") != NULL);
     } else {
         pattern = NULL;
@@ -497,7 +497,6 @@
      *  in this interpreter.  If we find any commands that
      *  represent classes, report them.
      */
-    listPtr = Tcl_NewListObj(0, (Tcl_Obj* CONST*)NULL);
 
     Itcl_InitStack(&search);
     Itcl_PushStack((ClientData)globalNs, &search);
@@ -532,10 +531,10 @@
 
                     objPtr = Tcl_NewStringObj((char*)NULL, 0);
                     Tcl_GetCommandFullName(interp, cmd, objPtr);
-                    name = Tcl_GetStringFromObj(objPtr, (int*)NULL);
+                    cmdName = Tcl_GetString(objPtr);
                 } else {
-                    name = Tcl_GetCommandName(interp, cmd);
-                    objPtr = Tcl_NewStringObj(name, -1);
+                    cmdName = Tcl_GetCommandName(interp, cmd);
+                    objPtr = Tcl_NewStringObj(cmdName, -1);
                 }
 
                 if (originalCmd) {
@@ -543,9 +542,10 @@
                 }
                 Tcl_CreateHashEntry(&unique, (char*)cmd, &newEntry);
 
-                if (newEntry && (!pattern || Tcl_StringMatch(name, pattern))) {
+                if (newEntry &&
+			(!pattern || Tcl_StringMatch(cmdName, pattern))) {
                     Tcl_ListObjAppendElement((Tcl_Interp*)NULL,
-                        listPtr, objPtr);
+                        Tcl_GetObjResult(interp), objPtr);
                 }
             }
             entry = Tcl_NextHashEntry(&place);
@@ -565,7 +565,6 @@
     Tcl_DeleteHashTable(&unique);
     Itcl_DeleteStack(&search);
 
-    Tcl_SetObjResult(interp, listPtr);
     return TCL_OK;
 }
 
@@ -598,8 +597,8 @@
     ItclClass *classDefn = NULL;
     ItclClass *isaDefn = NULL;
 
-    char *name, *token;
-    CONST char *cmdName;
+    char *name = NULL, *token = NULL;
+    CONST char *cmdName = NULL;
     int pos, newEntry, match, handledActiveNs;
     ItclObject *contextObj;
     Tcl_HashTable unique;
@@ -609,7 +608,7 @@
     Tcl_Command cmd, originalCmd;
     Namespace *nsPtr;
     Command *cmdPtr;
-    Tcl_Obj *listPtr, *objPtr;
+    Tcl_Obj *objPtr;
 
     /*
      *  Parse arguments:
@@ -617,7 +616,7 @@
      */
     pos = 0;
     while (++pos < objc) {
-        token = Tcl_GetStringFromObj(objv[pos], (int*)NULL);
+        token = Tcl_GetString(objv[pos]);
         if (*token != '-') {
             if (!pattern) {
                 pattern = token;
@@ -627,7 +626,7 @@
             }
         }
         else if ((pos+1 < objc) && (strcmp(token,"-class") == 0)) {
-            name = Tcl_GetStringFromObj(objv[pos+1], (int*)NULL);
+            name = Tcl_GetString(objv[pos+1]);
             classDefn = Itcl_FindClass(interp, name, /* autoload */ 1);
             if (classDefn == NULL) {
                 return TCL_ERROR;
@@ -635,7 +634,7 @@
             pos++;
         }
         else if ((pos+1 < objc) && (strcmp(token,"-isa") == 0)) {
-            name = Tcl_GetStringFromObj(objv[pos+1], (int*)NULL);
+            name = Tcl_GetString(objv[pos+1]);
             isaDefn = Itcl_FindClass(interp, name, /* autoload */ 1);
             if (isaDefn == NULL) {
                 return TCL_ERROR;
@@ -669,7 +668,6 @@
      *  in this interpreter.  If we find any commands that
      *  represent objects, report them.
      */
-    listPtr = Tcl_NewListObj(0, (Tcl_Obj* CONST*)NULL);
 
     Itcl_InitStack(&search);
     Itcl_PushStack((ClientData)globalNs, &search);
@@ -709,7 +707,7 @@
 
                     objPtr = Tcl_NewStringObj((char*)NULL, 0);
                     Tcl_GetCommandFullName(interp, cmd, objPtr);
-                    name = Tcl_GetStringFromObj(objPtr, (int*)NULL);
+		    cmdName = Tcl_GetString(objPtr);
                 } else {
                     cmdName = Tcl_GetCommandName(interp, cmd);
                     objPtr = Tcl_NewStringObj(cmdName, -1);
@@ -718,7 +716,8 @@
                 Tcl_CreateHashEntry(&unique, (char*)cmd, &newEntry);
 
                 match = 0;
-                if (newEntry && (!pattern || Tcl_StringMatch(name, pattern))) {
+		if (newEntry &&
+			(!pattern || Tcl_StringMatch(cmdName, pattern))) {
                     if (!classDefn || (contextObj->classDefn == classDefn)) {
                         if (!isaDefn) {
                             match = 1;
@@ -736,10 +735,9 @@
 
                 if (match) {
                     Tcl_ListObjAppendElement((Tcl_Interp*)NULL,
-                        listPtr, objPtr);
+                        Tcl_GetObjResult(interp), objPtr);
                 } else {
-                    Tcl_IncrRefCount(objPtr);  /* throw away the name */
-                    Tcl_DecrRefCount(objPtr);
+                    Tcl_DecrRefCount(objPtr);  /* throw away the name */
                 }
             }
             entry = Tcl_NextHashEntry(&place);
@@ -759,7 +757,6 @@
     Tcl_DeleteHashTable(&unique);
     Itcl_DeleteStack(&search);
 
-    Tcl_SetObjResult(interp, listPtr);
     return TCL_OK;
 }
 
@@ -821,9 +818,8 @@
     }
     else if (result != TCL_OK) {
         char mesg[256], *name;
-        name = Tcl_GetStringFromObj(objv[0], (int*)NULL);
-        sprintf(mesg, "\n    (%.100s body line %d)",
-            name, interp->errorLine);
+        name = Tcl_GetString(objv[0]);
+        sprintf(mesg, "\n    (%.100s body line %d)", name, interp->errorLine);
         Tcl_AddErrorInfo(interp, mesg);
     }
 
@@ -865,7 +861,7 @@
      *  then delete them.
      */
     for (i=1; i < objc; i++) {
-        name = Tcl_GetStringFromObj(objv[i], (int*)NULL);
+        name = Tcl_GetString(objv[i]);
         cdefn = Itcl_FindClass(interp, name, /* autoload */ 1);
         if (cdefn == NULL) {
             return TCL_ERROR;
@@ -873,7 +869,7 @@
     }
 
     for (i=1; i < objc; i++) {
-        name = Tcl_GetStringFromObj(objv[i], (int*)NULL);
+        name = Tcl_GetString(objv[i]);
         cdefn = Itcl_FindClass(interp, name, /* autoload */ 0);
 
         if (cdefn) {
