--- src/modules/Odbc/odbc_result.c.old	Wed Nov 16 10:55:43 2005
+++ src/modules/Odbc/odbc_result.c	Wed Nov 16 10:55:48 2005
@@ -2,7 +2,7 @@
 || This file is part of Pike. For copyright information see COPYRIGHT.
 || Pike is distributed under GPL, LGPL and MPL. See the file COPYING
 || for more information.
-|| $Id: odbc_result.c,v 1.37 2003/05/02 12:54:37 grubba Exp $
+|| $Id: odbc_result.c,v 1.38 2005/11/09 13:12:35 grubba Exp $
 */
 
 /*
@@ -21,7 +21,7 @@
 #include "config.h"
 #endif /* HAVE_CONFIG_H */
 
-RCSID("$Id: odbc_result.c,v 1.37 2003/05/02 12:54:37 grubba Exp $");
+RCSID("$Id: odbc_result.c,v 1.38 2005/11/09 13:12:35 grubba Exp $");
 
 #include "interpret.h"
 #include "object.h"
@@ -442,6 +442,18 @@
 	      push_int(0);
 	    }
 	    break;
+	  } else if (code == SQL_SUCCESS_WITH_INFO) {
+	    /* Data truncated. */
+	    num_strings++;
+#ifdef ODBC_DEBUG
+	    fprintf(stderr, "[%d] ", num_strings);
+#endif /* ODBC_DEBUG */
+	    if (PIKE_ODBC_RES->field_info[i].type == SQL_C_BINARY) {
+	      push_string(make_shared_binary_string(blob_buf, BLOB_BUFSIZ));
+	    } else {
+	      /* SQL_C_CHAR's are NUL-terminated... */
+	      push_string(make_shared_binary_string(blob_buf, BLOB_BUFSIZ - 1));
+	    }
 	  } else {
 	    num_strings++;
 #ifdef ODBC_DEBUG
@@ -453,15 +465,27 @@
 #endif /* SQL_NO_TOTAL */
                 ) {
 	      push_string(make_shared_binary_string(blob_buf, len));
-	      break;
 	    } else {
-	      if (PIKE_ODBC_RES->field_info[i].type == SQL_C_BINARY) {
-		push_string(make_shared_binary_string(blob_buf, BLOB_BUFSIZ));
-	      } else {
-		/* SQL_C_CHAR's are NUL-terminated... */
-		push_string(make_shared_binary_string(blob_buf, BLOB_BUFSIZ - 1));
+	      /* Truncated, but no support for chained SQLGetData calls. */
+	      char *buf = xalloc(len+2);
+	      SQLLEN newlen = 0;
+	      code = SQLGetData(PIKE_ODBC_RES->hstmt, (SQLUSMALLINT)(i+1),
+				PIKE_ODBC_RES->field_info[i].type,
+				buf, len+1, &newlen);
+	      if (code != SQL_SUCCESS) {
+		Pike_error("odbc->fetch_row(): "
+			   "Unexpected code from SQLGetData(): %d\n",
+			   code);
 	      }
+	      if (len != newlen) {
+		Pike_error("odbc->fetch_row(): "
+			   "Unexpected length from SQLGetData(): "
+			   "%d (expected %d)\n", newlen, len);
+	      }
+	      push_string(make_shared_binary_string(buf, len));
+	      free(buf);
 	    }
+	    break;
 	  }
 	}
 	if (num_strings > 1) {
