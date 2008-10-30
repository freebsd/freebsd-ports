--- Wnn/jserver/de.c.orig	2004-06-19 01:32:41.000000000 +0900
+++ Wnn/jserver/de.c	2008-10-30 15:45:46.000000000 +0900
@@ -102,9 +102,9 @@
 #endif
 
 #ifndef INET6
-#  define OPTIONARGS  "Df:s:h:N:p:vu4"
+#  define OPTIONARGS  "a:Df:s:h:N:p:vu4"
 #else
-#  define OPTIONARGS  "Df:s:h:N:p:vu46"
+#  define OPTIONARGS  "a:Df:s:h:N:p:vu46"
 #endif /* INET6 */
 
 /*      Accept Socket   */
@@ -1063,7 +1063,16 @@
 #else
   saddr_in.sin_family = AF_INET;
   saddr_in.sin_port = htons (port);
-  saddr_in.sin_addr.s_addr = htonl (INADDR_ANY);
+  if (!inet_aton(listenaddr, &saddr_in.sin_addr)) {
+	struct hostent	*hp;
+	struct in_addr	**pptr;
+
+	if ((hp = gethostbyname(listenaddr)) == NULL) {
+		xerror ("could not create inet socket");
+	}
+	pptr = (struct in_addr **)hp->h_addr_list;
+	memcpy(&saddr_in.sin_addr, pptr[0], sizeof(struct in_addr));
+  }
   if ((sock_d_in = socket (AF_INET, SOCK_STREAM, 0)) == ERROR)
 #endif
     {
@@ -1193,6 +1202,7 @@
 	{"inet",	0, NULL, '4'},
 	{"inet6",	0, NULL, '6'},
 	{"jserverrc",	1, NULL, 'f'},
+	{"listenaddr",	1, NULL, 'a'},
 	{"version",	0, NULL, 'v'},
 	{0, 0, 0, 0}
       };
@@ -1209,7 +1219,13 @@
 	  break;
 
         case 'f': /* --jserverrc FILENAME */
-          strcpy (jserverrcfile, optarg);
+          strncpy(jserverrcfile, optarg, sizeof(jserverrcfile) - 1);
+	  jserverrcfile[sizeof(jserverrcfile) - 1] = '\0';
+          break;
+
+        case 'a': /* --listenaddr ADDR */
+          strncpy(listenaddr, optarg, sizeof(listenaddr) - 1);
+	  listenaddr[sizeof(listenaddr) - 1] = '\0';
           break;
 
         case 's':
@@ -1318,9 +1334,9 @@
 {
   fprintf(stderr, 
 #ifdef INET6
-	  "usage: %s [-Du46][-f <init_file> -s <log_file(\"-\" for stderr)> -h <pos_file> -N <serverNO> -p <port_base>]\n",
+	  "usage: %s [-Du46][-f <init_file> -a <listenaddr> -s <log_file(\"-\" for stderr)> -h <pos_file> -N <serverNO> -p <port_base>]\n",
 #else
-	  "usage: %s [-Du4][-f <init_file> -s <log_file(\"-\" for stderr)> -h <pos_file> -N <serverNO> -p <port_base>]\n",
+	  "usage: %s [-Du4][-f <init_file> -a <listenaddr> -s <log_file(\"-\" for stderr)> -h <pos_file> -N <serverNO> -p <port_base>]\n",
 #endif
 	  cmd_name);
   fprintf(stderr,
