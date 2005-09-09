--- rlparse.y.orig	Sat Jun 25 07:56:54 2005
+++ rlparse.y	Wed Sep  7 00:48:58 2005
@@ -470,14 +470,14 @@
 			id->sawInterface = true;
 		}
 		id->sectionEndLoc = @2;
-	}
+	};
 
 /* Include statements are processed by both the scanner and the parser. */
 Include:
 	IncludeKeyword OptSection OptFileName ';' {
 		if ( id->active )
 			doInclude( @1, $2, $3 );
-	}
+	};
 
 IncludeKeyword: 
 	KW_Include {
@@ -607,7 +607,7 @@
 NoNameSep:
 	/* Nothing */ {
 		id->nameRef.empty();
-	}
+	};
 
 /* A qualified state reference. */
 StateRef:
@@ -622,7 +622,7 @@
 	} |
 	/* Nothing. */ {
 		id->nameRef.empty();
-	}
+	};
 
 /* List of names separated by :: */
 StateRefNames:
