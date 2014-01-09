--- cpp.orig/src/slice2cpp/Gen.cpp	2013-03-11 15:19:46.000000000 +0000
+++ cpp/src/slice2cpp/Gen.cpp	2013-05-20 19:51:48.109197053 +0000
@@ -756,10 +756,11 @@
 
         C << sp << nl << "class " << factoryName << "__Init";
         C << sb;
+        C << nl << "IceInternal::FactoryTableInit* _ftableinit;";
         C.dec();
         C << nl << "public:";
         C.inc();
-        C << sp << nl << factoryName << "__Init()";
+        C << sp << nl << factoryName << "__Init(): _ftableinit(new IceInternal::FactoryTableInit)";
         C << sb;
         C << nl << "::IceInternal::factoryTable->addExceptionFactory(\"" << p->scoped() << "\", new "
           << factoryName << ");";
@@ -767,6 +768,7 @@
         C << sp << nl << "~" << factoryName << "__Init()";
         C << sb;
         C << nl << "::IceInternal::factoryTable->removeExceptionFactory(\"" << p->scoped() << "\");";
+        C << nl << "delete _ftableinit;";
         C << eb;
         C << eb << ';';
 
@@ -3976,10 +3978,11 @@
             C << sp;
             C << nl << "class " << factoryName << "__Init";
             C << sb;
+            C << nl << "IceInternal::FactoryTableInit* _ftableinit;";
             C.dec();
             C << nl << "public:";
             C.inc();
-            C << sp << nl << factoryName << "__Init()";
+            C << sp << nl << factoryName << "__Init(): _ftableinit(new IceInternal::FactoryTableInit)";
             C << sb;
             if(!p->isAbstract())
             {
@@ -4002,6 +4005,7 @@
             {
                 C << nl << "::IceInternal::factoryTable->removeTypeId(" << p->compactId() << ");";
             }
+            C << nl << "delete _ftableinit;";
             C << eb;
             C << eb << ';';
 
