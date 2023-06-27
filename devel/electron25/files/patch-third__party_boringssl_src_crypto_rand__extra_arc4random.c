--- third_party/boringssl/src/crypto/rand_extra/arc4random.c.orig	2022-02-07 13:39:41 UTC
+++ third_party/boringssl/src/crypto/rand_extra/arc4random.c
@@ -0,0 +1,33 @@
+/* Copyright (c) 2018, Robert Nagy <robert@openbsd.org>
+ *
+ * Permission to use, copy, modify, and/or distribute this software for any
+ * purpose with or without fee is hereby granted, provided that the above
+ * copyright notice and this permission notice appear in all copies.
+ *
+ * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
+ * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
+ * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
+ * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
+ * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
+ * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
+ * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */
+
+#define _BSD_SOURCE 1
+
+#include <openssl/rand.h>
+
+#if defined(OPENSSL_ARC4RANDOM) && !defined(BORINGSSL_UNSAFE_DETERMINISTIC_MODE)
+
+#include <stdlib.h>
+
+#include "../fipsmodule/rand/internal.h"
+
+void CRYPTO_sysrand_for_seed(uint8_t *out, size_t requested) {                 
+  CRYPTO_sysrand(out, requested);
+}                                                                              
+
+void CRYPTO_sysrand(uint8_t *out, size_t requested) {
+  arc4random_buf(out, requested);
+}
+
+#endif  // OPENSSL_ARC4RANDOM && !BORINGSSL_UNSAFE_DETERMINISTIC_MODE
