--- libcharset/lib/localcharset.c.orig	2020-05-09 08:59:22 UTC
+++ libcharset/lib/localcharset.c
@@ -92,6 +92,7 @@ static const struct table_entry alias_table[] =
 #  if defined __FreeBSD__                                   /* FreeBSD */
   /*{ "ARMSCII-8",  "ARMSCII-8" },*/
     { "Big5",       "BIG5" },
+    { "Big5HKSCS",  "BIG5-HKSCS" },
     { "C",          "ASCII" },
   /*{ "CP1131",     "CP1131" },*/
   /*{ "CP1251",     "CP1251" },*/
@@ -104,6 +105,7 @@ static const struct table_entry alias_table[] =
     { "ISO8859-13", "ISO-8859-13" },
     { "ISO8859-15", "ISO-8859-15" },
     { "ISO8859-2",  "ISO-8859-2" },
+    { "ISO8859-4",  "ISO-8859-4" },
     { "ISO8859-5",  "ISO-8859-5" },
     { "ISO8859-7",  "ISO-8859-7" },
     { "ISO8859-9",  "ISO-8859-9" },
