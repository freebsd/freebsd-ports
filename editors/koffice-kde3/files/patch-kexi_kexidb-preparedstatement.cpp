--- kexi/kexidb/preparedstatement.cpp.orig	Thu May 25 15:55:54 2006
+++ kexi/kexidb/preparedstatement.cpp	Thu May 25 16:02:59 2006
@@ -104,7 +104,7 @@
 		}
 		s.append(")");
 		s.prepend(QCString("INSERT INTO ") + table->name().latin1()
-			+ (allTableFieldsUsed ? "" : (" (" + namesList + ")"))
+			+ (allTableFieldsUsed ? QCString("") : (" (" + namesList + ")"))
 			+ " VALUES (");
 	}
 	return s;
