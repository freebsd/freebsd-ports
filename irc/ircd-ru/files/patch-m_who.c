--- src/m_who.c.orig	Fri Jul 14 18:37:05 2006
+++ src/m_who.c	Wed Dec 27 21:22:01 2006
@@ -33,6 +33,14 @@
 #include <fcntl.h>
 #include "h.h"
 
+#if defined(RESTRICT_WHO)
+#define ISADMIN(arg)	IsOAdmin(arg)
+#define ISOPER(arg)	IsOper(arg)
+#else
+#define ISADMIN(arg)	IsAdmin(arg)
+#define ISOPER(arg)	IsAnOper(arg)
+#endif
+
 /* Internally defined stuffs */
 SOpts wsopts;
 int build_searchopts(aClient *, int, char **);
@@ -437,13 +445,7 @@
 
     if(cptr->user->channel)
     {
-	if(
-#if defined(RESTRICT_WHO)
-		IsOAdmin(
-#else
-		IsAdmin(
-#endif
-				sptr))
+	if(ISADMIN(sptr))
 	{
 	    chptr = cptr->user->channel->value.chptr;
 	    if(!(ShowChannel(sptr, chptr)))
@@ -479,13 +481,7 @@
     aClient *ac;
     chanMember *cm;
     Link *lp;
-    int shown=0, i=0, showall=
-#if defined(RESTRICT_WHO)
-								IsOper(
-#else
-								IsAnOper(
-#endif
-										sptr);
+    int shown=0, i=0, showall = ISOPER(sptr);
     char status[4];
 
     /* drop nonlocal clients */
@@ -527,21 +523,9 @@
     {
 	if(IsMember(sptr,wsopts.channel))
 	    showall=1;
-	else if(SecretChannel(wsopts.channel) && 
-#if defined(RESTRICT_WHO)
-											IsOAdmin(
-#else
-											IsAdmin(
-#endif
-													sptr))
+	else if(SecretChannel(wsopts.channel) && ISADMIN(sptr))
 	    showall=1;
-	else if(!SecretChannel(wsopts.channel) && 
-#if defined(RESTRICT_WHO)
-											IsOper(
-#else
-											IsAnOper(
-#endif
-													sptr))
+	else if(!SecretChannel(wsopts.channel) && ISOPER(sptr))
 	    showall=1;
 	else
 	    showall=0;
@@ -561,13 +545,7 @@
 #ifdef NOTHELPER_HIDEOPERATOR
 				&& (IsUmodeh(ac) || IsAnOper(sptr))
 #endif
-				? '*' : ((IsInvisible(ac) && 
-#if defined(RESTRICT_WHO)
-											IsOper(
-#else
-											IsAnOper(
-#endif
-													sptr)) ?
+				? '*' : ((IsInvisible(ac) && ISOPER(sptr)) ?
 					'%' : 0));
 		status[((status[i]) ? ++i : i)]=((cm->flags&CHFL_CHANOP) ? '@'
 						 : ((cm->flags&CHFL_VOICE) ? 
@@ -604,13 +582,7 @@
 #ifdef NOTHELPER_HIDEOPERATOR
 				&& (IsUmodeh(ac) || IsAnOper(sptr))
 #endif
-				? '*' : (IsInvisible(ac) && 
-#if defined(RESTRICT_WHO)
-											IsOper(
-#else
-											IsAnOper(
-#endif
-													sptr) ?
+				? '*' : (IsInvisible(ac) && ISOPER(sptr) ?
 					'%' : 0));
 		status[2]=0;
 		sendto_one(sptr, getreply(RPL_WHOREPLY), me.name, sptr->name,
@@ -658,13 +630,7 @@
 #ifdef NOTHELPER_HIDEOPERATOR
 				&& (IsUmodeh(ac) || IsAnOper(sptr))
 #endif
-				? '*' : ((IsInvisible(ac) && 
-#if defined(RESTRICT_WHO)
-											IsOper(
-#else
-											IsAnOper(
-#endif
-													sptr)) ?
+				? '*' : ((IsInvisible(ac) && ISOPER(sptr)) ?
 					'%' : 0));
 		status[((status[i]) ? ++i : i)]=((cm->flags&CHFL_CHANOP) ? 
 						 '@' : ((cm->flags&CHFL_VOICE)
@@ -697,13 +663,7 @@
 #ifdef NOTHELPER_HIDEOPERATOR
 			    && (IsUmodeh(ac) || IsAnOper(sptr))
 #endif
-			    ? '*' : (IsInvisible(ac) && 
-#if defined(RESTRICT_WHO)
-											IsOper(
-#else
-											IsAnOper(
-#endif
-													sptr) ?
+			    ? '*' : (IsInvisible(ac) && ISOPER(sptr) ?
 				    '%' : 0));
 	    status[2]=0;
 	    sendto_one(sptr, getreply(RPL_WHOREPLY), me.name, sptr->name,
