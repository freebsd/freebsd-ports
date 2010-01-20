--- src/s_serv.c	2006-07-14 18:11:33.000000000 +0400
+++ src/s_serv.c	2007-01-11 02:54:40.000000000 +0300
@@ -290,8 +290,8 @@ int m_squit(aClient *cptr, aClient *sptr
 #ifdef USE_SYSLOG
 	    syslog(LOG_NOTICE, "Failed SQUIT U-lined server %s attempt by "
 		"server %s", acptr->name, parv[0]);
-	}
 #endif
+	}
 	else
 	{
 	    sendto_one(sptr, err_str(ERR_NOPRIVILEGES), me.name, parv[0]);
