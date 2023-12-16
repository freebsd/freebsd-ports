--- ircd/ircd.c.orig	2023-12-06 19:33:28 UTC
+++ ircd/ircd.c
@@ -49,7 +49,6 @@ char	*debugmode = "";		/*  -"-    -"-   -"-   -"- */
 int	firstrejoindone = 0;		/* Server rejoined the network after
 					   start */
 char	*debugmode = "";		/*  -"-    -"-   -"-   -"- */
-char	*sbrk0;				/* initial sbrk(0) */
 char	*tunefile = IRCDTUNE_PATH;
 volatile static	int	dorehash = 0,
 			dorestart = 0,
@@ -140,11 +139,9 @@ void	restart(char *mesg)
 void	restart(char *mesg)
 {
 #ifdef	USE_SYSLOG
-	(void)syslog(LOG_WARNING, "Restarting Server because: %s (%u)", mesg,
-		     (u_int)((char *)sbrk((size_t)0)-sbrk0));
+	(void)syslog(LOG_WARNING, "Restarting Server because: %s", mesg);
 #endif
-	sendto_flag(SCH_NOTICE, "Restarting server because: %s (%u)", mesg,
-		    (u_int)((char *)sbrk((size_t)0)-sbrk0));
+	sendto_flag(SCH_NOTICE, "Restarting server because: %s (%u)");
 	server_reboot();
 }
 
@@ -175,8 +172,7 @@ void	server_reboot(void)
 {
 	Reg	int	i;
 
-	sendto_flag(SCH_NOTICE, "Aieeeee!!!  Restarting server... (%u)",
-		    (u_int)((char *)sbrk((size_t)0)-sbrk0));
+	sendto_flag(SCH_NOTICE, "Aieeeee!!!  Restarting server...");
 
 	Debug((DEBUG_NOTICE,"Restarting server..."));
 	flush_connections(me.fd);
@@ -768,7 +764,6 @@ int	main(int argc, char *argv[])
 {
 	uid_t	uid, euid;
 
-	sbrk0 = (char *)sbrk((size_t)0);
 	uid = getuid();
 	euid = geteuid();
 
