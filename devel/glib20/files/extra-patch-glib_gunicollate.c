--- glib/gunicollate.c.orig
+++ glib/gunicollate.c
@@ -26,6 +26,10 @@
 #include <wchar.h>
 #endif
 
+#include <unicode/umachine.h>
+#include <unicode/ustring.h>
+#include <unicode/ucol.h>
+
 #ifdef HAVE_CARBON
 #include <CoreServices/CoreServices.h>
 #endif
@@ -36,10 +40,53 @@
 #include "gstring.h"
 #include "gstrfuncs.h"
 #include "gtestutils.h"
+#include "gthread.h"
 #ifndef __STDC_ISO_10646__
 #include "gconvert.h"
 #endif
 
+static gboolean icu_collator_initialized = FALSE;
+static UCollator *icu_collator = NULL;
+G_LOCK_DEFINE_STATIC(icu_collator);
+
+static void
+init_icu_collator (void)
+{
+  G_LOCK(icu_collator);
+  if (! icu_collator_initialized)
+    {
+      UErrorCode error = U_ZERO_ERROR;
+
+      icu_collator = ucol_open(NULL, &error);
+      if (icu_collator == NULL)
+	g_warning("unable to initialize the ICU collator (%s), FreeBSD collation routines will be used", u_errorName(error));
+
+      icu_collator_initialized = TRUE;
+    }
+  G_UNLOCK(icu_collator);
+}
+
+static UChar *
+utf8_to_uchar (const char *str, int32_t len, int32_t *result_len)
+{
+  UErrorCode error = U_ZERO_ERROR;
+  UChar *result = NULL;
+
+  u_strFromUTF8(NULL, 0, result_len, str, len, &error);
+  if (error <= U_ZERO_ERROR || error == U_BUFFER_OVERFLOW_ERROR)
+    {
+      error = U_ZERO_ERROR;
+      result = g_new(UChar, *result_len);
+      u_strFromUTF8(result, *result_len, NULL, str, len, &error);
+      if (error > U_ZERO_ERROR)
+	{
+	  g_free(result);
+	  result = NULL;
+	}
+    }
+
+  return result;
+}
 
 #ifdef _MSC_VER
 /* Workaround for bug in MSVCR80.DLL */
@@ -127,6 +174,28 @@
   g_return_val_if_fail (str1 != NULL, 0);
   g_return_val_if_fail (str2 != NULL, 0);
 
+  init_icu_collator();
+  if (icu_collator != NULL)
+    {
+      int32_t wstr1_len;
+      UChar *wstr1 = utf8_to_uchar(str1, -1, &wstr1_len);
+      if (wstr1 != NULL)
+	{
+	  int32_t wstr2_len;
+	  UChar *wstr2 = utf8_to_uchar(str2, -1, &wstr2_len);
+	  if (wstr2 != NULL)
+	    {
+	      result = ucol_strcoll(icu_collator, wstr1, wstr1_len, wstr2, wstr2_len);
+
+	      g_free(wstr1);
+	      g_free(wstr2);
+
+	      return result;
+	    }
+	  g_free(wstr1);
+	}
+    }
+
   str1_norm = g_utf8_normalize (str1, -1, G_NORMALIZE_ALL_COMPOSE);
   str2_norm = g_utf8_normalize (str2, -1, G_NORMALIZE_ALL_COMPOSE);
 
@@ -419,6 +488,26 @@
 
   g_return_val_if_fail (str != NULL, NULL);
 
+  init_icu_collator();
+  if (icu_collator != NULL)
+    {
+      int32_t wstr_len;
+      UChar *wstr = utf8_to_uchar(str, len, &wstr_len);
+      if (wstr != NULL)
+	{
+	  int32_t result_len;
+
+	  /* get size of result */
+	  result_len = ucol_getSortKey(icu_collator, wstr, wstr_len, NULL, 0);
+
+	  result = g_new(char, result_len);
+	  ucol_getSortKey(icu_collator, wstr, wstr_len, result, result_len);
+	  g_free(wstr);
+
+	  return result;
+	}
+    }
+
   str_norm = g_utf8_normalize (str, len, G_NORMALIZE_ALL_COMPOSE);
 
   result = NULL;
