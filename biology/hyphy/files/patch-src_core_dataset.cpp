--- src/core/dataset.cpp.orig	2020-02-20 18:58:13 UTC
+++ src/core/dataset.cpp
@@ -700,7 +700,7 @@ void _DataSet::MatchIndices(_Formula &f, _SimpleList &
       receptacle << i;
     }
   }
-  v->SetValue(new _Constant(0.0), nil);
+  v->SetValue(new _Constant(0.0), false);
 }
 
 //_________________________________________________________
