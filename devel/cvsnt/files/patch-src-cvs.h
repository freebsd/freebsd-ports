--- src/cvs.h.orig	Tue Feb  8 21:53:19 2005
+++ src/cvs.h	Tue Feb  8 21:59:05 2005
@@ -1159,8 +1159,14 @@
 
 namespace cvs
 {
+#if defined(__GNUC__) && (__GNUC__ < 3)
+typedef string_char_traits<char> char_traits_base;
+#else
+typedef std::char_traits<char> char_traits_base;
+#endif
+
 	/* Define traits for the filenames and usernames in c++ */
-	struct filename_char_traits : public std::char_traits<char>
+	struct filename_char_traits : public char_traits_base
 	{
 		static bool eq( char c1, char c2 ) { return FOLD_FN_CHAR(c1) == FOLD_FN_CHAR(c2);  }
 		static bool ne( char c1, char c2 ) { return FOLD_FN_CHAR(c1) != FOLD_FN_CHAR(c2);  }
@@ -1169,7 +1175,7 @@
 		static const char*find( const char* s, int n, char a ) { while( n-- > 0 && FOLD_FN_CHAR(*s) != FOLD_FN_CHAR(a) ) { ++s; } return s; }
 	};
 
-	struct username_char_traits : public std::char_traits<char>
+	struct username_char_traits : public char_traits_base
 	{
 		static bool eq( char c1, char c2 ) { return FOLD_UN_CHAR(c1) == FOLD_UN_CHAR(c2);  }
 		static bool ne( char c1, char c2 ) { return FOLD_UN_CHAR(c1) != FOLD_UN_CHAR(c2);  }
