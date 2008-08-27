--- ./bin/named/pgsqldb.h.orig	2008-08-26 12:01:22.000000000 -0400
+++ ./bin/named/pgsqldb.h	2008-08-26 12:01:22.000000000 -0400
@@ -0,0 +1,25 @@
+/*
+ * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")
+ * Copyright (C) 2000, 2001  Internet Software Consortium.
+ *
+ * Permission to use, copy, modify, and distribute this software for any
+ * purpose with or without fee is hereby granted, provided that the above
+ * copyright notice and this permission notice appear in all copies.
+ *
+ * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
+ * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
+ * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
+ * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
+ * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
+ * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
+ * PERFORMANCE OF THIS SOFTWARE.
+ */
+
+/* $Id: pgsqldb.h,v 1.3 2004/03/05 05:04:32 marka Exp $ */
+
+#include <isc/types.h>
+
+isc_result_t pgsqldb_init(void);
+
+void pgsqldb_clear(void);
+
