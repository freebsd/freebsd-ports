
$FreeBSD$

--- _mysql.c	2002/01/09 13:02:08	1.1
+++ _mysql.c	2002/01/09 13:06:07
@@ -781,7 +781,11 @@
 			goto error;
 		}
 		if (!row) {
+#if PY_VERSION_HEX < 0x02020000
 			if (_PyTuple_Resize(r, i, 0) == -1) goto error;
+#else
+			if (_PyTuple_Resize(r, i) == -1) goto error;
+#endif
 			break;
 		}
 		v = convert_row(self, row);
