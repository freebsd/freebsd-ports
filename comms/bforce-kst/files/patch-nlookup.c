--- bfutil/nlookup.c.orig	Thu Aug 30 16:33:51 2001
+++ bfutil/nlookup.c	Sat Jun 19 07:05:34 2004
@@ -28,15 +28,34 @@
 static void usage(void)
 {
 	printf_usage("nodelist lookup utility",
-		"usage: nlookup [-rh] <address>\n"
+		"usage: nlookup [-rmh] <address>\n"
 		"\n"
 		"options:\n"
 		"  -r                show nodelist string\n"
+		"  -m                show email address\n"
 		"  -h                show this help message\n"
 		"\n"
 	);
 }
 
+void print_nodemail(const s_node *node)
+{
+	char abuf[BF_MAXADDRSTR+1];
+
+	if( node->sysop && *node->sysop && strcmp(node->sysop, "<none>") )
+	{
+		char username[BNI_MAXSYSOP+1];
+		
+		strnxcpy(username, node->sysop, sizeof(node->sysop));
+		string_replchar(username, ' ', '_');
+
+		printf("%s@%s.fidonet.org\n", username,
+			    ftn_addrstr_inet(abuf, node->addr));
+	}
+	
+	fflush(stdout);
+}
+
 void print_nodeinfo(const s_node *node)
 {
 	char abuf[BF_MAXADDRSTR+1];
@@ -124,6 +143,9 @@
 	}
 	else if( nodelist_lookup(&node, addr) == 0 )
 	{
+	    if( emailaddr )
+		print_nodemail(&node);
+	    else
 		print_nodeinfo(&node);
 	}
 	
