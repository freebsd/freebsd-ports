--- ./lib/localcharset.c.orig	2018-02-03 12:42:20 UTC
+++ ./lib/localcharset.c
@@ -129,7 +129,7 @@ get_charset_aliases (void)
   cp = charset_aliases;
   if (cp == NULL)
     {
-#if !(defined DARWIN7 || defined VMS || defined WINDOWS_NATIVE || defined __CYGWIN__ || defined OS2)
+#if !(defined DARWIN7 || defined VMS || defined WINDOWS_NATIVE || defined __CYGWIN__ || defined OS2 || defined __FreeBSD__)
       char *malloc_dir = NULL;
       const char *dir;
       const char *base = "charset.alias";
@@ -259,6 +259,86 @@ get_charset_aliases (void)
 
 #else
 
+# if defined __FreeBSD__
+      /* To avoid the trouble of installing a file that is shared by many
+         GNU packages -- many packaging systems have problems with this --,
+         simply inline the aliases here.  */
+      cp = "US-ASCII" "\0" "ASCII" "\0"
+           "la_LN.ASCII" "\0" "ASCII" "\0"
+           "lt_LN.ASCII" "\0" "ASCII" "\0"
+           "da_DK.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "da_DK.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "de_AT.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "de_AT.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "de_CH.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "de_CH.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "de_DE.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "de_DE.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "en_AU.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "en_AU.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "en_CA.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "en_CA.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "en_GB.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "en_GB.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "en_US.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "en_US.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "es_ES.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "es_ES.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "fi_FI.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "fi_FI.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "fr_BE.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "fr_BE.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "fr_CA.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "fr_CA.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "fr_CH.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "fr_CH.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "fr_FR.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "fr_FR.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "is_IS.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "is_IS.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "it_CH.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "it_CH.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "it_IT.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "it_IT.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "la_LN.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "la_LN.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "lt_LN.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "lt_LN.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "nl_BE.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "nl_BE.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "nl_NL.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "nl_NL.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "no_NO.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "no_NO.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "pt_PT.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "pt_PT.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "sv_SE.ISO_8859-1" "\0" "ISO-8859-1" "\0"
+           "sv_SE.DIS_8859-15" "\0" "ISO-8859-15" "\0"
+           "cs_CZ.ISO_8859-2" "\0" "ISO-8859-2" "\0"
+           "hr_HR.ISO_8859-2" "\0" "ISO-8859-2" "\0"
+           "hu_HU.ISO_8859-2" "\0" "ISO-8859-2" "\0"
+           "la_LN.ISO_8859-2" "\0" "ISO-8859-2" "\0"
+           "lt_LN.ISO_8859-2" "\0" "ISO-8859-2" "\0"
+           "pl_PL.ISO_8859-2" "\0" "ISO-8859-2" "\0"
+           "sl_SI.ISO_8859-2" "\0" "ISO-8859-2" "\0"
+           "la_LN.ISO_8859-4" "\0" "ISO-8859-4" "\0"
+           "lt_LT.ISO_8859-4" "\0" "ISO-8859-4" "\0"
+           "ru_RU.KOI8-R" "\0" "KOI8-R" "\0"
+           "ru_RU.ISO_8859-5" "\0" "ISO-8859-5" "\0"
+           "ru_RU.CP866" "\0" "CP866" "\0"
+           "ru_SU.KOI8-R" "\0" "KOI8-R" "\0"
+           "ru_SU.ISO_8859-5" "\0" "ISO-8859-5" "\0"
+           "ru_SU.CP866" "\0" "CP866" "\0"
+           "uk_UA.KOI8-U" "\0" "KOI8-U" "\0"
+           "zh_TW.BIG5" "\0" "BIG5" "\0"
+           "zh_TW.Big5" "\0" "BIG5" "\0"
+           "zh_CN.EUC" "\0" "GB2312" "\0"
+           "ja_JP.EUC" "\0" "EUC-JP" "\0"
+           "ja_JP.SJIS" "\0" "SHIFT_JIS" "\0"
+           "ja_JP.Shift_JIS" "\0" "SHIFT_JIS" "\0"
+           "ko_KR.EUC" "\0" "EUC-KR" "\0";
+# endif
+
 # if defined DARWIN7
       /* To avoid the trouble of installing a file that is shared by many
          GNU packages -- many packaging systems have problems with this --,
