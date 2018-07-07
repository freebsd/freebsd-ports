--- calendar/calendar.C.orig	1997-05-21 20:32:59 UTC
+++ calendar/calendar.C
@@ -224,13 +224,13 @@ int Calendar::Read(Lexer* lex) {
 	    char* name = new char[len + 1];
 	    if (! lex->GetText(name, len) ||
 		! lex->Skip(closer)) {
-		delete name;
+		delete [] name;
 		lex->SetError("error reading included file name");
 		return 0;
 	    }
 	    name[len] = '\0';
 	    Include(name);
-	    delete name;
+	    delete [] name;
 	}
 	else if (strcmp(keyword, "Hide") == 0) {
 	    char const* x;
