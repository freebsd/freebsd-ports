--- source/irchandler.c.orig	Sun Jul 20 15:08:00 2003
+++ source/irchandler.c	Sun Jul 20 15:09:35 2003
@@ -169,12 +169,6 @@
 			break;
 		case 333: /* topic time */
 			break;
-#if 0
-ωνω Numbered server stuff: "352 pana #opennap toasty bender.thirty4.com
-          irc.lightning.net Toasty_ H@ :2 Chad Boyda" (irc.core.com)
-          ωνω Numbered server stuff: "315 pana #opennap :End of /WHO list."
-                    (irc.core.com)
-#endif
 		case 315:
 			break;
 		case 352:
@@ -943,4 +937,4 @@
 	}
 	from_server = ofs;
 }
- 
\ No newline at end of file
+ 
