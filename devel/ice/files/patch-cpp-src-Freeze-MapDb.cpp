--- cpp.orig/src/Freeze/MapDb.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Freeze/MapDb.cpp	2012-09-10 11:43:58.000000000 +0200
@@ -72,7 +72,13 @@ Freeze::MapDb::~MapDb()
         }
         catch(const ::DbException& dx)
         {
+#if defined(ICE_DESTRUCTORS_DONT_THROW_BY_DEFAULT)
+            Error out(_communicator->getLogger());
+            out << "DbException while closing database " << _dbName << ": "
+                << dx.what();
+#else
             throw DatabaseException(__FILE__, __LINE__, dx.what());
+#endif
         }
     }
 }
@@ -229,7 +229,11 @@
 #ifndef NDEBUG
                 bool inserted = 
 #endif
-                    _indices.insert(IndexMap::value_type(indexBase->name(), indexI.get())).second;
+                    _indices.insert(IndexMap::value_type(indexBase->name(), indexI.get()))
+#ifndef NDEBUG                    
+                    .second
+#endif
+                ;
                 assert(inserted);
                 
                 indexBase->_impl = indexI.release();
