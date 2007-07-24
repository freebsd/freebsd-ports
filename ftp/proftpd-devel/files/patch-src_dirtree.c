Index: src/dirtree.c
===================================================================
RCS file: /cvsroot/proftp/proftpd/src/dirtree.c,v
retrieving revision 1.184
diff -u -r1.184 dirtree.c
--- src/dirtree.c	22 Mar 2007 03:54:20 -0000	1.184
+++ src/dirtree.c	24 Jul 2007 17:13:05 -0000
@@ -2911,12 +2911,13 @@
                * this address.
                */
               snprintf(ipbuf, sizeof(ipbuf), "::ffff:%s", ipstr);
-              ipstr = ipbuf;
+              ipstr = pstrdup(s->pool, ipbuf);
             }
           }
 #endif /* PR_USE_IPV6 */
 
-          pr_conf_add_server_config_param_str(s, "_bind", 1, ipstr);
+          if (ipstr)
+            pr_conf_add_server_config_param_str(s, "_bind", 1, ipstr);
         }
       }
