--- mixkit/src/MxAsp.cxx.orig	Sat Jan 23 06:50:45 1999
+++ mixkit/src/MxAsp.cxx	Mon Nov  3 22:09:45 2003
@@ -53,8 +53,8 @@
 }
 
 #define asprint(V)\
-out<< *as##.##V##_var; \
-for(i=1; i<size; i++) out << " " << as##.##V##_var[i]
+out<< *as.V##_var; \
+for(i=1; i<size; i++) out << " " << as.V##_var[i]
 
 ostream& MxAspVar::print(ostream& out) const
 {
@@ -79,7 +79,7 @@
 #define defset(V, T) \
 bool MxAspVar::set_##V(V val, uint i) \
 {\
-     if( type==T && i<size ) { as##.##V##_var[i]=val; return true; } \
+     if( type==T && i<size ) { as.V##_var[i]=val; return true; } \
      else  return false; \
 }
 
@@ -94,7 +94,7 @@
 #define defget(V, T) \
 V *MxAspVar::get_##V(V *out, uint i) \
 {\
-     if( type==T && i<size ) { *out = as##.##V##_var[i]; return out; } \
+     if( type==T && i<size ) { *out = as.V##_var[i]; return out; } \
      else  return NULL; \
 } 
 
