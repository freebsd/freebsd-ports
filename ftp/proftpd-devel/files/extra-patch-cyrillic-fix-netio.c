--- ./src/netio.c.orig  Sun Oct 10 00:46:22 2004
+++ ./src/netio.c       Thu Oct 12 15:17:22 2006
@@ -901,47 +901,6 @@
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
