--- xcalendar.c.dist	Tue Jul  4 06:59:01 1995
+++ xcalendar.c	Mon Mar 12 20:53:10 2001
@@ -1091,10 +1091,10 @@
 struct tm      *
 gettime()
 {
-    struct timeval  t;
+    time_t now;
 
-    gettimeofday(&t, NULL);
-    today = localtime(&t.tv_sec);
+    (void) time(&now);
+    today = localtime(&now);
     return today;
 }
 
@@ -1827,8 +1827,8 @@
 		*sb++ = '1', *sb++ = '9';
 		/* fall thru */
 	    case 'y':
-		*sb++ = tm.tm_year / 10 + '0';
-		*sb++ = tm.tm_year % 10 + '0';
+		*sb++ = (tm.tm_year%100) / 10 + '0';
+		*sb++ = (tm.tm_year%100) % 10 + '0';
 		break;
 	    case '%':
 		*sb++ = *p;
@@ -1869,6 +1869,13 @@
 	if (len == -1)
 	    return;
     }
+
+    /* terminate `buf' with NULL */
+    if (sizeof(buf) == len) {
+      buf = XtRealloc(buf, len + 1);
+    }
+    buf[len] = NULL;
+
     start = buf;
 
     while (len > 0) {
