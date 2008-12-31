Index: pcp/pcp.h
===================================================================
RCS file: /cvsroot/pgpool/pgpool-II/pcp/pcp.h,v
retrieving revision 1.3
diff -u -r1.3 pcp.h
--- pcp/pcp.h	29 Jan 2008 01:56:37 -0000	1.3
+++ pcp/pcp.h	29 Dec 2008 05:15:44 -0000
@@ -62,6 +62,8 @@
 extern int pcp_attach_node(int nid);
 extern void pcp_set_timeout(long sec);
 extern int pcp_recovery_node(int nid);
+extern void pcp_enable_debug(void);
+extern void pcp_disable_debug(void);
 
 /* ------------------------------
  * pcp_error.c
