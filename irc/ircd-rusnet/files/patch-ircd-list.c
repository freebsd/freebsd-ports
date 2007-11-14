--- ircd/list.c.orig	2007-11-14 03:04:31.000000000 +0600
+++ ircd/list.c	2007-11-14 03:05:38.000000000 +0600
@@ -146,7 +146,7 @@
 		istat.is_auth -= 1;
 		MyFree(cptr->auth);
 	}
-	MyFree((char *)cptr);
+	MyFree(cptr);
 }
 
 /*
@@ -251,7 +251,7 @@
 		    {
 			istat.is_away--;
 			istat.is_awaymem -= (strlen(user->away) + 1);
-			MyFree((char *)user->away);
+			MyFree(user->away);
 		    }
 		/*
 		 * sanity check
@@ -297,7 +297,7 @@
 					    user->username, user->host, buf);
 #endif
 		    }
-		MyFree((char *)user);
+		MyFree(user);
 #ifdef	DEBUGMODE
 		users.inuse--;
 #endif
@@ -327,7 +327,7 @@
 				    cptr, cptr ? cptr->name : "<noname>", buf);
 #endif
 		    }
-		MyFree((char *)serv);
+		MyFree(serv);
 	    }
 }
 
@@ -518,7 +518,7 @@
 void	free_link(lp)
 Reg	Link	*lp;
 {
-	MyFree((char *)lp);
+	MyFree(lp);
 #ifdef	DEBUGMODE
 	links.inuse--;
 #endif
@@ -539,7 +539,7 @@
 void	free_class(tmp)
 Reg	aClass	*tmp;
 {
-	MyFree((char *)tmp);
+	MyFree(tmp);
 #ifdef	DEBUGMODE
 	classs.inuse--;
 #endif
@@ -601,10 +601,10 @@
 	if (aconf->passwd)
 		bzero(aconf->passwd, strlen(aconf->passwd));
 	if (aconf->ping)
-		MyFree((char *)aconf->ping);
+		MyFree(aconf->ping);
 	MyFree(aconf->passwd);
 	MyFree(aconf->name);
-	MyFree((char *)aconf);
+	MyFree(aconf);
 #ifdef	DEBUGMODE
 	aconfs.inuse--;
 #endif
