--- src/gettext.hpp~
+++ src/gettext.hpp
@@ -35,7 +35,21 @@
 
 // gettext-related declarations
 
-#include <libintl.h>
+#include "wesconfig.h"
+
+#ifdef ENABLE_NLS
+# include <libintl.h>
+#else
+# define bind_textdomain_codeset(Domain, Codeset) "C"
+# define bindtextdomain(Domain, Directory) "/nonexistent"
+# define gettext(String) gettext_noop(String)
+# define ngettext(Singular, Plural, Number) gettext_noop(Number == 1 ? Singular : Plural)
+# define dgettext(Domain, String) gettext_noop(String)
+# define dngettext(Domain, Singular, Plural, Number) gettext_noop(Number == 1 ? Singular : Plural)
+# define dcgettext(Domain, String, Category) gettext_noop(String)
+# define dcngettext(Domain, Singular, Plural, Number, Category) gettext_noop(Number == 1 ? Singular : Plural)
+char *textdomain (const char *domainname);
+#endif
 
 const char* egettext(const char*);
 const char* sgettext(const char*);
