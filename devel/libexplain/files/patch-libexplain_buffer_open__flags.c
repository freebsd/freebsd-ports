Unbreak after base r357412

libexplain/buffer/open_flags.c:187:10: error: duplicate case value '262144'
    case O_EXEC:
         ^
/usr/include/fcntl.h:121:17: note: expanded from macro 'O_EXEC'
#define O_EXEC          0x00040000      /* Open for execute only */
                        ^
libexplain/buffer/open_flags.c:180:11: note: previous case defined here
     case O_SEARCH:
          ^
/usr/include/fcntl.h:122:18: note: expanded from macro 'O_SEARCH'
#define O_SEARCH        O_EXEC
                        ^
/usr/include/fcntl.h:121:17: note: expanded from macro 'O_EXEC'
#define O_EXEC          0x00040000      /* Open for execute only */
                        ^
1 error generated.

--- libexplain/buffer/open_flags.c.orig	2020-02-07 09:55:29 UTC
+++ libexplain/buffer/open_flags.c
@@ -176,7 +176,7 @@ explain_buffer_open_flags(explain_string_buffer_t *sb,
         explain_string_buffer_puts(sb, "O_WRONLY");
         break;
 
-#if defined(O_SEARCH) && O_SEARCH != 0
+#if defined(O_SEARCH) && O_SEARCH != 0 && O_SEARCH != O_EXEC
      case O_SEARCH:
         /* open a directory for searchin only */
         explain_string_buffer_puts(sb, "O_SEARCH");
