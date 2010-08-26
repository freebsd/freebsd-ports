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
+# define bind_textdomain_codeset(Domain,Codeset) "C"
+# define bindtextdomain(Domain,Dir) "/nonexistent"
+# define gettext(String) gettext_noop(String)
+# define ngettext(String1,String2,Int) gettext_noop(Int == 1 ? String1 : String2)
+# define dgettext(Domain,String) gettext_noop(String)
+# define dngettext(Domain,String1,String2,Int) gettext_noop(Int == 1 ? String1 : String2)
+# define dcgettext(Domain,String,Int) gettext_noop(String)
+# define dcngettext(Domain,String1,String2,Int1,Int2) gettext_noop(Int1 == 1 ? String1 : String2)
+char *textdomain (const char *domainname);
+#endif
 
 const char* egettext(const char*);
 const char* sgettext(const char*);
