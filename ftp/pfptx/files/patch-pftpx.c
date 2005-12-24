--- pftpx.c.orig        Mon Jun 27 17:58:30 2005
+++ pftpx.c     Mon Jun 27 18:01:11 2005
@@ -58,6 +58,58 @@

 #define        sstosa(ss)      ((struct sockaddr *)(ss))

+#include <sys/types.h>
+
+#include <ctype.h>
+#include <limits.h>
+#include <string.h>
+
+#define isoctal(c)      (((u_char)(c)) >= '0' && ((u_char)(c)) <= '7')
+#include <sys/types.h>
+
+#define isoctal(c)      (((u_char)(c)) >= '0' && ((u_char)(c)) <= '7')
+#define isvisible(c)    (((u_int)(c) <= UCHAR_MAX && isascii((u_char)(c)) && \
+                                isgraph((u_char)(c))) ||                     \
+                                ((flag & VIS_SP) == 0 && (c) == ' ') ||      \
+                                ((flag & VIS_TAB) == 0 && (c) == '\t') ||    \
+                                ((flag & VIS_NL) == 0 && (c) == '\n') ||     \
+                                ((flag & VIS_SAFE) && ((c) == '\b' ||        \
+                                (c) == '\007' || (c) == '\r' ||              \
+                                isgraph((u_char)(c)))))
+
+#define _VIS_H_
+
+#include <sys/types.h>
+#include <limits.h>
+
+/*
+ * to select alternate encoding format
+ */
+#define VIS_OCTAL       0x01    /* use octal \ddd format */
+#define VIS_CSTYLE      0x02    /* use \[nrft0..] where appropriate */
+
+/*
+ * to alter set of characters encoded (default is to encode all
+ * non-graphic except space, tab, and newline).
+ */
+#define VIS_SP          0x04    /* also encode space */
+#define VIS_TAB         0x08    /* also encode tab */
+#define VIS_NL          0x10    /* also encode newline */
+#define VIS_WHITE       (VIS_SP | VIS_TAB | VIS_NL)
+#define VIS_SAFE        0x20    /* only encode "unsafe" characters */
+
+/*
+ * other
+ */
+#define VIS_NOSLASH     0x40    /* inhibit printing '\' */
+
+#define LIST_FIRST(head)                ((head)->lh_first)
+#define LIST_END(head)                        NULL
+#define LIST_NEXT(elm, field)                ((elm)->field.le_next)
+
+char    *vis(char *, int, int, int);
+int     strnvis(char *, const char *, size_t, int);
+
 enum { CMD_NONE = 0, CMD_PORT, CMD_EPRT, CMD_PASV, CMD_EPSV };

 struct session {
@@ -1037,3 +1089,143 @@
            "[-p address] [-q queue] [-t timeout]\n", __progname);
        exit(1);
 }
+
+
+/*
+ * vis - visually encode characters
+ */
+char *
+vis(dst, c, flag, nextc)
+        register char *dst;
+        int c, nextc;
+        register int flag;
+{
+        if (isvisible(c)) {
+                *dst++ = c;
+                if (c == '\\' && (flag & VIS_NOSLASH) == 0)
+                        *dst++ = '\\';
+                *dst = '\0';
+                return (dst);
+        }
+
+        if (flag & VIS_CSTYLE) {
+                switch(c) {
+                case '\n':
+                        *dst++ = '\\';
+                        *dst++ = 'n';
+                        goto done;
+                case '\r':
+                        *dst++ = '\\';
+                        *dst++ = 'r';
+                        goto done;
+                case '\b':
+                        *dst++ = '\\';
+                        *dst++ = 'b';
+                        goto done;
+                case '\a':
+                        *dst++ = '\\';
+                        *dst++ = 'a';
+                        goto done;
+                case '\v':
+                        *dst++ = '\\';
+                        *dst++ = 'v';
+                        goto done;
+                case '\t':
+                        *dst++ = '\\';
+                        *dst++ = 't';
+                        goto done;
+                case '\f':
+                        *dst++ = '\\';
+                        *dst++ = 'f';
+                        goto done;
+                case ' ':
+                        *dst++ = '\\';
+                        *dst++ = 's';
+                        goto done;
+                case '\0':
+                        *dst++ = '\\';
+                        *dst++ = '0';
+                        if (isoctal(nextc)) {
+                                *dst++ = '0';
+                                *dst++ = '0';
+                        }
+                        goto done;
+                }
+        }
+        if (((c & 0177) == ' ') || (flag & VIS_OCTAL)) {
+                *dst++ = '\\';
+                *dst++ = ((u_char)c >> 6 & 07) + '0';
+                *dst++ = ((u_char)c >> 3 & 07) + '0';
+                *dst++ = ((u_char)c & 07) + '0';
+                goto done;
+        }
+        if ((flag & VIS_NOSLASH) == 0)
+                *dst++ = '\\';
+        if (c & 0200) {
+                c &= 0177;
+                *dst++ = 'M';
+        }
+        if (iscntrl(c)) {
+                *dst++ = '^';
+                if (c == 0177)
+                        *dst++ = '?';
+                else
+                        *dst++ = c + '@';
+        } else {
+                *dst++ = '-';
+                *dst++ = c;
+        }
+done:
+        *dst = '\0';
+        return (dst);
+}
+
+int
+strnvis(dst, src, siz, flag)
+        char *dst;
+        const char *src;
+        size_t siz;
+        int flag;
+{
+        char c;
+        char *start, *end;
+        char tbuf[5];
+        int  i;
+
+        i = 0;
+        for (start = dst, end = start + siz - 1; (c = *src) && dst < end; ) {
+                if (isvisible(c)) {
+                        i = 1;
+                        *dst++ = c;
+                        if (c == '\\' && (flag & VIS_NOSLASH) == 0) {
+                                /* need space for the extra '\\' */
+                                if (dst < end)
+                                        *dst++ = '\\';
+                                else {
+                                        dst--;
+                                        i = 2;
+                                        break;
+                                }
+                        }
+                        src++;
+                } else {
+                        i = vis(tbuf, c, flag, *++src) - tbuf;
+                        if (dst + i <= end) {
+                                memcpy(dst, tbuf, i);
+                                dst += i;
+                        } else {
+                                src--;
+                                break;
+                        }
+                }
+        }
+        if (siz > 0)
+                *dst = '\0';
+        if (dst + i > end) {
+                /* adjust return value for truncation */
+                while ((c = *src))
+                        dst += vis(tbuf, c, flag, *++src) - tbuf;
+        }
+        return (dst - start);
+}
+

