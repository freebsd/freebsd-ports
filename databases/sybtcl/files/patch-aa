--- generic/sybtcl.c	2000-08-30 20:24:18.000000000 -0400
+++ generic/sybtcl.c	2007-10-12 16:54:36.000000000 -0400
@@ -178,5 +178,6 @@
 #endif
 
-#include "tcl.h"
+#include <strings.h>
+#include <tcl.h>
 
 
@@ -279,4 +280,12 @@
 #endif
 
+#ifndef CS_INTERNAL
+#define CS_INTERNAL	/* Not defined by FreeTDS */
+#endif
+
+#ifndef TDS_DEF_CHARSET
+#define TDS_DEF_CHARSET "iso_1" /* Not defined by Sybase */
+#endif
+
 typedef struct SybTclProcs {	/* struct for handle entries */
     int         in_use;		/* if this entry is opened */
@@ -393,5 +402,5 @@
 #else
 
-extern void * malloc();
+#include <stdlib.h>
 
 #endif
@@ -428,22 +437,22 @@
 /* prototypes for all tcl command functions */
 
-EXTERN Sybtcl_Init      _ANSI_ARGS_((Tcl_Interp *interp));
-EXTERN Sybtcl_SafeInit  _ANSI_ARGS_((Tcl_Interp *interp));
+EXTERN int Sybtcl_Init      _ANSI_ARGS_((Tcl_Interp *interp));
+EXTERN int Sybtcl_SafeInit  _ANSI_ARGS_((Tcl_Interp *interp));
 
-extern Tcl_ObjCmdProc  Sybtcl_Connect;
-extern Tcl_ObjCmdProc  Sybtcl_ErrHandler;
-extern Tcl_ObjCmdProc  Sybtcl_MsgHandler;
-extern Tcl_ObjCmdProc  Sybtcl_Money;
-extern Tcl_ObjCmdProc  Sybtcl_Use;
-extern Tcl_ObjCmdProc  Sybtcl_Sql;
-extern Tcl_ObjCmdProc  Sybtcl_Poll;
-extern Tcl_ObjCmdProc  Sybtcl_Next;
-extern Tcl_ObjCmdProc  Sybtcl_Cols;
-extern Tcl_ObjCmdProc  Sybtcl_Cancel;
-extern Tcl_ObjCmdProc  Sybtcl_Close;
-extern Tcl_ObjCmdProc  Sybtcl_Retval;
-extern Tcl_ObjCmdProc  Sybtcl_Wrtext;
-extern Tcl_ObjCmdProc  Sybtcl_Rdtext;
-extern Tcl_ObjCmdProc  Sybtcl_Event;
+static Tcl_ObjCmdProc  Sybtcl_Connect;
+static Tcl_ObjCmdProc  Sybtcl_ErrHandler;
+static Tcl_ObjCmdProc  Sybtcl_MsgHandler;
+static Tcl_ObjCmdProc  Sybtcl_Money;
+static Tcl_ObjCmdProc  Sybtcl_Use;
+static Tcl_ObjCmdProc  Sybtcl_Sql;
+static Tcl_ObjCmdProc  Sybtcl_Poll;
+static Tcl_ObjCmdProc  Sybtcl_Next;
+static Tcl_ObjCmdProc  Sybtcl_Cols;
+static Tcl_ObjCmdProc  Sybtcl_Cancel;
+static Tcl_ObjCmdProc  Sybtcl_Close;
+static Tcl_ObjCmdProc  Sybtcl_Retval;
+static Tcl_ObjCmdProc  Sybtcl_Wrtext;
+static Tcl_ObjCmdProc  Sybtcl_Rdtext;
+static Tcl_ObjCmdProc  Sybtcl_Event;
 
 
@@ -461,8 +470,10 @@
 			Tcl_Interp *interp));
 
+#ifdef POLLED_EVENTS
 static int dbEventProc _ANSI_ARGS_((Tcl_Event *evPtr, int flags));
 static void dbSetupProc _ANSI_ARGS_((ClientData cd_hand, int flags));
 static void dbCheckProc _ANSI_ARGS_((ClientData cd_hand, int flags));
-void Sybtcl_Kill _ANSI_ARGS_((ClientData clientData));
+#endif
+static void Sybtcl_Kill _ANSI_ARGS_((ClientData clientData));
 static int CS_INTERNAL syb_tcl_err_handler _ANSI_ARGS_((
 	DBPROCESS *db_proc,
@@ -496,4 +507,5 @@
 
 
+#ifdef POLLED_EVENTS /* { */
 /*
  *----------------------------------------------------------------------
@@ -566,5 +578,5 @@
     }
 }
-
+#endif /* POLLED_EVENTS } */
 
 
@@ -609,5 +621,4 @@
 {
     dbState *statePtr = (dbState *) instanceData;
-    int hand = statePtr->hand;
 
 #ifdef POLLED_EVENTS
@@ -641,5 +652,5 @@
     dbState *statePtr = (dbState *) instanceData;
 
-    *handlePtr = (ClientData)statePtr->fd; 
+    *handlePtr = (ClientData)(intptr_t)statePtr->fd; 
     return TCL_OK;                      
 }   
@@ -661,5 +672,5 @@
 }
 
-Tcl_Channel
+static Tcl_Channel
 dbMakeChannel (sock, hand, channelName)
     int sock;
@@ -1167,9 +1178,9 @@
  */
 
+CALLBACK_SCOPE Tcl_ChannelProc callback_handler;
 static void
 remove_handler (hand)
     int hand;
 {
-    CALLBACK_SCOPE Tcl_ChannelProc callback_handler;
     if (SybProcs[hand].callBackScript != NULL) {
         Tcl_DecrRefCount(SybProcs[hand].callBackScript);
@@ -1177,8 +1188,8 @@
 	if (SybProcs[hand].sybChan != NULL) {
 	    Tcl_DeleteChannelHandler(SybProcs[hand].sybChan,
-				callback_handler, (ClientData) hand);
+				callback_handler, (ClientData)(intptr_t)hand);
         }
 #ifdef POLLED_EVENTS
-        Tcl_DeleteEventSource( dbSetupProc, dbCheckProc, (ClientData) hand);
+        Tcl_DeleteEventSource( dbSetupProc, dbCheckProc, (ClientData)(intptr_t)hand);
 #endif
     }
@@ -1451,4 +1462,16 @@
 				&dateinfo,(DBDATETIME *) col_ptr);
 		j=0;
+#if defined(MSDBLIB) && !defined(dateyear)
+#	define dateyear	year
+#	define datemonth	month
+#	define datedmonth	day
+#	define datedyear	dayofyear
+#	define datedweek	weekday
+#	define datehour	hour
+#	define dateminute	minute
+#	define datesecond	second
+#	define datemsecond	millisecond
+#	define datetzone	tzone
+#endif
 		while((unsigned int) j < strlen(date_str)) {
 		    if (!strncmp(&(date_str[j]),"YYYY",4)) {
@@ -1669,6 +1692,8 @@
 
 
-#ifdef DBVERSION_100
+#ifdef SYBBOUNDARY
 	case SYBBOUNDARY:
+#endif
+#ifdef SYBSENSITIVITY
 	case SYBSENSITIVITY:
 #endif  
@@ -1694,5 +1719,5 @@
  */
 
-void
+static void
 Sybtcl_Kill (clientData)
     ClientData clientData;
@@ -1776,5 +1801,5 @@
  */
 
-void
+static void
 Sybtcl_DeleteInterp (clientData, interp)
     ClientData clientData;
@@ -2429,5 +2454,5 @@
  */
 
-int
+static int
 Sybtcl_ErrHandler (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -2466,5 +2491,5 @@
  */
 
-int
+static int
 Sybtcl_MsgHandler (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -2505,5 +2530,5 @@
  */
 
-int
+static int
 Sybtcl_Connect (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -2556,5 +2581,7 @@
 
     DBSETLUSER(login,Tcl_GetStringFromObj(objv[1],NULL));
-    DBSETLPWD(login, Tcl_GetStringFromObj(objv[2],NULL));
+    server_str = Tcl_GetStringFromObj(objv[2],&len);
+    if (len > 0)
+	DBSETLPWD(login, server_str);
 
     /* check for server optional parameter */
@@ -2594,8 +2621,8 @@
             DBSETLCHARSET(login, charset_str);
 	} else {
-            DBSETLCHARSET(login, NULL);
+            DBSETLCHARSET(login, TDS_DEF_CHARSET);
 	}
     } else {
-        DBSETLCHARSET(login, NULL);
+        DBSETLCHARSET(login, TDS_DEF_CHARSET);
     }
 
@@ -2607,5 +2634,6 @@
     if (SybProcs[hand].dbproc == NULL) {
 	Sybtcl_AppendObjResult (interp, CMD_STR,
-	   ": sybconnect failed in dbopen", (char *) NULL);
+	   ": sybconnect to ", server_str ? server_str : "(DEFAULT)",
+	   " failed in dbopen", (char *) NULL);
 	return TCL_ERROR;
     }
@@ -2673,4 +2701,5 @@
  */
 
+static int
 Sybtcl_Money (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -2788,4 +2817,5 @@
  */
 
+static int
 Sybtcl_Use (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -2850,4 +2880,5 @@
  */
 
+static int
 Sybtcl_Sql (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -2909,5 +2940,5 @@
     if (SybProcs[hand].last_text != SybOptions[i].maxtext) {
 	SybProcs[hand].last_text = SybOptions[i].maxtext;
-	sprintf(conv_buf,"%d",SybOptions[i].maxtext);
+	sprintf(conv_buf,"%ld",SybOptions[i].maxtext);
 	dbsetopt(SybProcs[hand].dbproc, DBTEXTSIZE, conv_buf, -1);
 	dbsqlexec(SybProcs[hand].dbproc);  /* execute dbsetopt() */
@@ -3022,4 +3053,5 @@
  */
 
+static int
 Sybtcl_Poll (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -3551,4 +3583,5 @@
  */
 
+static int
 Sybtcl_Next (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -3819,4 +3852,5 @@
  */
 
+static int
 Sybtcl_Cols (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -3972,4 +4006,5 @@
  */
 
+static int
 Sybtcl_Cancel (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -4020,4 +4055,5 @@
  */
 
+static int
 Sybtcl_Retval (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -4091,4 +4127,5 @@
  */
 
+static int
 Sybtcl_Close (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -4167,4 +4204,5 @@
  */
 
+static int
 Sybtcl_Wrtext (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -4190,5 +4228,5 @@
     int      obj_parm;
     int      isvar = 0;
-    Tcl_Channel fd;
+    Tcl_Channel fd = NULL;
 #ifndef MAC_TCL
     struct stat stat_buf;		
@@ -4305,5 +4343,6 @@
     txtptr = dbtxptr(SybProcs[hand].dbproc,col);
     if (txtptr == NULL) {
-        Tcl_Close (NULL,fd);
+	if (fd != NULL)
+            Tcl_Close (NULL,fd);
         Sybtcl_AppendObjResult (interp, CMD_STR,
 	   ": dbtxptr failed ", (char *) NULL);
@@ -4448,5 +4487,5 @@
  */
 
-
+static int
 Sybtcl_Rdtext (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -4638,5 +4677,5 @@
     int        mask;
 {
-    int         hand = (int) cd_hand;
+    int         hand = (int)(intptr_t)cd_hand;
     Tcl_Interp *interp = SybProcs[hand].interp;
     DBPROCESS  *readyproc;
@@ -4754,5 +4793,5 @@
  */
 
-
+static int
 Sybtcl_Event (clientData, interp, objc, objv)
     ClientData   clientData;
@@ -4791,9 +4830,9 @@
                 /* create handler */
                 Tcl_CreateChannelHandler(SybProcs[hand].sybChan, TCL_READABLE, 
-    				    callback_handler, (ClientData) hand);
+    				    callback_handler, (ClientData)(intptr_t)hand);
 
 #ifdef POLLED_EVENTS
                 Tcl_CreateEventSource(dbSetupProc, dbCheckProc,
-				(ClientData) hand);
+				(ClientData)(intptr_t)hand);
 #endif
 
