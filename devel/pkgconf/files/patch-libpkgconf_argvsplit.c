diff --git libpkgconf/argvsplit.c libpkgconf/argvsplit.c
index cded5f7..f893215 100644
--- libpkgconf/argvsplit.c
+++ libpkgconf/argvsplit.c
@@ -111,6 +111,11 @@ pkgconf_argv_split(const char *src, int *argc, char ***argv)
 		}
 		else switch(*src_iter)
 		{
+			case '"':
+			case '\'':
+				quote = *src_iter;
+				break;
+
 			case '\\':
 				src_iter++;
 
