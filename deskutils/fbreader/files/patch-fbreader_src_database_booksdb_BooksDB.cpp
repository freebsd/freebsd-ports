BooksDB.cpp:148:10: error: no viable conversion from returned value of type 'bool' to function return type 'shared_ptr<Book>'
                return false;
                       ^~~~~
/wrkdirs/usr/ports/deskutils/fbreader/work/FBReader-0.99.6-freebsdport/fbreader/../zlibrary/core/include/shared_ptr.h:57:3: note: candidate constructor not viable: no known conversion from 'bool' to 'Book *' for 1st argument
                shared_ptr(T *t);
                ^
/wrkdirs/usr/ports/deskutils/fbreader/work/FBReader-0.99.6-freebsdport/fbreader/../zlibrary/core/include/shared_ptr.h:58:3: note: candidate constructor not viable: no known conversion from 'bool' to 'const shared_ptr<Book> &' for 1st argument
                shared_ptr(const shared_ptr<T> &t);
                ^
/wrkdirs/usr/ports/deskutils/fbreader/work/FBReader-0.99.6-freebsdport/fbreader/../zlibrary/core/include/shared_ptr.h:59:3: note: candidate constructor not viable: no known conversion from 'bool' to 'const weak_ptr<Book> &' for 1st argument
                shared_ptr(const weak_ptr<T> &t);
                ^
1 error generated.

--- fbreader/src/database/booksdb/BooksDB.cpp.orig	2014-01-11 12:45:25 UTC
+++ fbreader/src/database/booksdb/BooksDB.cpp
@@ -145,7 +145,7 @@ shared_ptr<Book> BooksDB::loadBook(const std::string &

 	myFindFileId->setFileName(fileName);
 	if (!myFindFileId->run()) {
-		return false;
+		return 0;
 	}
 	((DBIntValue&)*myLoadBook->parameter("@file_id").value()) = myFindFileId->fileId();
 	shared_ptr<DBDataReader> reader = myLoadBook->executeReader();
