--- sql/mytcpd.h.orig	Sun Jan  9 13:33:51 2005
+++ sql/mytcpd.h	Sun Jan  9 13:41:42 2005
@@ -6,6 +6,25 @@
   * $FreeBSD: /tmp/pcvs/ports/databases/mysql50-server/files/patch-sql::mytcpd.h,v 1.1 2005-01-10 13:17:30 ale Exp $
   */
 
+#ifndef _TCPWRAPPERS_TCPD_H
+#define _TCPWRAPPERS_TCPD_H
+
+/* someone else may have defined this */
+#undef  __P
+
+/* use prototypes if we have an ANSI C compiler or are using C++ */
+#if defined(__STDC__) || defined(__cplusplus)
+#define __P(args)       args
+#else
+#define __P(args)       ()
+#endif
+
+/* Need definitions of struct sockaddr_in and FILE. */
+#include <netinet/in.h>
+#include <stdio.h>
+
+__BEGIN_DECLS
+
 /* Structure to describe one communications endpoint. */
 
 #define STRING_LENGTH	128		/* hosts, users, processes */
@@ -31,10 +50,10 @@
     char    pid[10];			/* access via eval_pid(request) */
     struct host_info client[1];		/* client endpoint info */
     struct host_info server[1];		/* server endpoint info */
-    void  (*sink) ();			/* datagram sink function or 0 */
-    void  (*hostname) ();		/* address to printable hostname */
-    void  (*hostaddr) ();		/* address to printable address */
-    void  (*cleanup) ();		/* cleanup function or 0 */
+    void  (*sink) __P((int));		/* datagram sink function or 0 */
+    void  (*hostname) __P((struct host_info *)); /* address to printable hostname */
+    void  (*hostaddr) __P((struct host_info *)); /* address to printable address */
+    void  (*cleanup) __P((struct request_info *)); /* cleanup function or 0 */
     struct netconfig *config;		/* netdir handle */
 };
 
@@ -67,20 +86,23 @@
 /* Global functions. */
 
 #if defined(TLI) || defined(PTX) || defined(TLI_SEQUENT)
-extern void fromhost();			/* get/validate client host info */
+extern void fromhost __P((struct request_info *));	/* get/validate client host info */
 #else
 #define fromhost sock_host		/* no TLI support needed */
 #endif
 
-extern int hosts_access();		/* access control */
-extern void shell_cmd();		/* execute shell command */
-extern char *percent_x();		/* do %<char> expansion */
-extern void rfc931();			/* client name from RFC 931 daemon */
-extern void clean_exit();		/* clean up and exit */
-extern void refuse();			/* clean up and exit */
-extern char *xgets();			/* fgets() on steroids */
-extern char *split_at();		/* strchr() and split */
-extern unsigned long dot_quad_addr();	/* restricted inet_addr() */
+extern void shell_cmd __P((char *));	/* execute shell command */
+extern char *percent_x __P((char *, int, char *, struct request_info *)); /* do %<char> expansion */
+#ifdef INET6
+extern void rfc931 __P((struct sockaddr *, struct sockaddr *, char *)); /* client name from RFC 931 daemon */
+#else
+extern void rfc931 __P((struct sockaddr_in *, struct sockaddr_in *, char *)); /* client name from RFC 931 daemon */
+#endif
+extern void clean_exit __P((struct request_info *)); /* clean up and exit */
+extern void refuse __P((struct request_info *));	/* clean up and exit */
+extern char *xgets __P((char *, int, FILE *));	/* fgets() on steroids */
+extern char *split_at __P((char *, int));	/* strchr() and split */
+extern unsigned long dot_quad_addr __P((char *)); /* restricted inet_addr() */
 
 /* Global variables. */
 
@@ -98,9 +120,14 @@
   */
 
 #ifdef __STDC__
+extern int hosts_access(struct request_info *request);
+extern int hosts_ctl(char *daemon, char *client_name, char *client_addr, 
+                     char *client_user);
 extern struct request_info *request_init(struct request_info *,...);
 extern struct request_info *request_set(struct request_info *,...);
 #else
+extern int hosts_access();
+extern int hosts_ctl();
 extern struct request_info *request_init();	/* initialize request */
 extern struct request_info *request_set();	/* update request structure */
 #endif
@@ -123,27 +150,27 @@
   * host_info structures serve as caches for the lookup results.
   */
 
-extern char *eval_user();		/* client user */
-extern char *eval_hostname();		/* printable hostname */
-extern char *eval_hostaddr();		/* printable host address */
-extern char *eval_hostinfo();		/* host name or address */
-extern char *eval_client();		/* whatever is available */
-extern char *eval_server();		/* whatever is available */
+extern char *eval_user __P((struct request_info *));	/* client user */
+extern char *eval_hostname __P((struct host_info *));	/* printable hostname */
+extern char *eval_hostaddr __P((struct host_info *));	/* printable host address */
+extern char *eval_hostinfo __P((struct host_info *));	/* host name or address */
+extern char *eval_client __P((struct request_info *));	/* whatever is available */
+extern char *eval_server __P((struct request_info *));	/* whatever is available */
 #define eval_daemon(r)	((r)->daemon)	/* daemon process name */
 #define eval_pid(r)	((r)->pid)	/* process id */
 
 /* Socket-specific methods, including DNS hostname lookups. */
 
-extern void sock_host();		/* look up endpoint addresses */
-extern void sock_hostname();		/* translate address to hostname */
-extern void sock_hostaddr();		/* address to printable address */
+extern void sock_host __P((struct request_info *));
+extern void sock_hostname __P((struct host_info *));
+extern void sock_hostaddr __P((struct host_info *));
 #define sock_methods(r) \
 	{ (r)->hostname = sock_hostname; (r)->hostaddr = sock_hostaddr; }
 
 /* The System V Transport-Level Interface (TLI) interface. */
 
 #if defined(TLI) || defined(PTX) || defined(TLI_SEQUENT)
-extern void tli_host();			/* look up endpoint addresses etc. */
+extern void tli_host __P((struct request_info *));	/* look up endpoint addresses etc. */
 #endif
 
  /*
@@ -184,7 +211,7 @@
   * behavior.
   */
 
-extern void process_options();		/* execute options */
+extern void process_options __P((char *, struct request_info *)); /* execute options */
 extern int dry_run;			/* verification flag */
 
 /* Bug workarounds. */
@@ -223,3 +250,7 @@
 #define strtok	my_strtok
 extern char *my_strtok();
 #endif
+
+__END_DECLS
+
+#endif /* tcpd.h */
