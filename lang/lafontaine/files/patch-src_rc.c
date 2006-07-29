--- src/rc.c.orig	Thu Jul 27 22:40:17 2006
+++ src/rc.c	Thu Jul 27 22:43:36 2006
@@ -39,6 +39,12 @@
 #include "rc.h"
 
 struct s_turtle my_turtle;
+void rc_parse_group(GScanner *scanner);
+void rc_parse_coresave(GScanner *scanner);
+void rc_parse_history(GScanner *scanner);
+void rc_parse_locales(GScanner *scanner);
+void rc_parse_alocale(GScanner *scanner);
+void rc_parse_keyval(GScanner *scanner, struct s_keyval *keyval);
 
 
 static const GScannerConfig gtk_rc_scanner_config =
@@ -152,6 +158,7 @@
       rc_parse_coresave(scanner);
       break;
     default:
+	break;
     }
 
 }
@@ -176,6 +183,7 @@
 	  printf("coredump file: %s\n", keyval.value);
 	  break;
 	default:
+		break;
 	}
     }
 
@@ -203,6 +211,7 @@
 	  printf("history file: %s\n", keyval.value);
 	  break;
 	default:
+		break;
 	}
     }
 
