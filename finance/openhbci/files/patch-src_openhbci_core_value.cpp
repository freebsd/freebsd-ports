value.cpp:145:10: error: no viable conversion from 'std::__1::basic_istream<char>' to 'bool'
    bool readsuccess = (ist >> _value);
         ^             ~~~~~~~~~~~~~~~

--- src/openhbci/core/value.cpp.orig	2018-09-01 02:40:24 UTC
+++ src/openhbci/core/value.cpp
@@ -142,7 +142,8 @@ Value::Value(const string &strvalue)
     setlocale(LC_NUMERIC, "C");
     
     // Read float (double) value according to C-locale rules.
-    bool readsuccess = (ist >> _value);
+    ist >> _value;
+    bool readsuccess = ist.good();
 
     // Reset locale to cached string.
     setlocale(LC_NUMERIC, oldloc.c_str());
