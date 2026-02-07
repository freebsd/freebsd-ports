--- src/rc.c.orig	2002-09-17 20:06:21 UTC
+++ src/rc.c
@@ -38,7 +38,13 @@
 #include "turtle.h"
 #include "rc.h"
 
-struct s_turtle my_turtle;
+extern struct s_turtle my_turtle;
+void rc_parse_group(GScanner *scanner);
+void rc_parse_coresave(GScanner *scanner);
+void rc_parse_history(GScanner *scanner);
+void rc_parse_locales(GScanner *scanner);
+void rc_parse_alocale(GScanner *scanner);
+void rc_parse_keyval(GScanner *scanner, struct s_keyval *keyval);
 
 
 static const GScannerConfig gtk_rc_scanner_config =
@@ -152,6 +158,7 @@ void rc_parse_group(GScanner *scanner)
       rc_parse_coresave(scanner);
       break;
     default:
+	break;
     }
 
 }
@@ -176,6 +183,7 @@ void rc_parse_coresave(GScanner *scanner)
 	  printf("coredump file: %s\n", keyval.value);
 	  break;
 	default:
+		break;
 	}
     }
 
@@ -203,6 +211,7 @@ void rc_parse_history(GScanner *scanner)
 	  printf("history file: %s\n", keyval.value);
 	  break;
 	default:
+		break;
 	}
     }
 
