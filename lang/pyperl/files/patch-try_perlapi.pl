
$FreeBSD$

--- try_perlapi.pl
+++ try_perlapi.pl
@@ -24,6 +24,9 @@
 #include "perlmodule.h"
 #include "lang_lock.h"
 #include "thrd_ctx.h"
+
+#define PERL_CORE
+#include "embed.h"
 EOT
 
 print C <<EOT if $ENABLE_JMPENV;
