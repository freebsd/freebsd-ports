diff -r -u -P src/netio.c src/netio.c
--- src/netio.c.orig	2007-08-22 18:50:23.000000000 +0400
+++ src/netio.c	2008-09-04 18:27:21.000000000 +0400
@@ -954,47 +954,6 @@
       cp = *pbuf->current++;
       pbuf->remaining++;
 
-      switch (mode) {
-        case IAC:
-          switch (cp) {
-            case WILL:
-            case WONT:
-            case DO:
-            case DONT:
-              mode = cp;
-              continue;
-
-            case IAC:
-              mode = 0;
-              break;
-
-            default:
-              /* Ignore */
-              mode = 0;
-              continue;
-          }
-          break;
-
-        case WILL:
-        case WONT:
-          pr_netio_printf(out_nstrm, "%c%c%c", IAC, DONT, cp);
-          mode = 0;
-          continue;
-
-        case DO:
-        case DONT:
-          pr_netio_printf(out_nstrm, "%c%c%c", IAC, WONT, cp);
-          mode = 0;
-          continue;
-
-        default:
-          if (cp == IAC) {
-            mode = cp;
-            continue;
-          }
-          break;
-      }
-
       *bp++ = cp;
       buflen--;
     }
