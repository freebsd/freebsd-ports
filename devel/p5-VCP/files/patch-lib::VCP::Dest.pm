$FreeBSD$
--- lib/VCP/Dest.pm	Fri Feb 27 14:01:18 2004
+++ lib/VCP/Dest.pm	Fri Feb 27 14:05:48 2004
@@ -425,9 +425,9 @@
       return ( "" ) unless length ;
 
       return split /(?:
-	  (?<=[[:alpha:]])(?=[^[:alpha:]])
-	 |(?<=[[:digit:]])(?=[^[:digit:]])
-	 |[^[:alnum:]]+
+	  (?<=[A-Za-z])(?=[^A-Za-z])
+	 |(?<=[0-9])(?=[^0-9])
+	 |[^A-Za-z0-9]+
       )/x ;
    }
 }
