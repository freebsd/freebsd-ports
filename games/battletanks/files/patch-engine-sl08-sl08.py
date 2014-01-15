From: Ansgar Burchardt <ansgar@debian.org>
Bug-Debian: http://bugs.debian.org/624916
Subject: Fix FTBFS with gcc-4.6

Update: Add missing this->'s to appease Clang

--- engine/sl08/sl08.py.orig
+++ engine/sl08/sl08.py
@@ -152,11 +152,11 @@ class Generator(object):
 			typedef base_signalXXX %s signal_type; 
 			typedef return_type (object_type::*func_t) %s; 
 
-			inline slotXXX () : object(NULL), func(NULL) {}
-			inline slotXXX(object_type *object, func_t func, signal_type * signal = NULL) : object(object), func(func) {}
+			inline slotXXX () : object(0), func(0) {}
+			inline slotXXX(object_type *object, func_t func, signal_type * signal = 0) : object(object), func(func) {}
 
 			inline void assign(object_type *o, func_t f) { object = o; func = f; }
-			inline void assign(object_type *o, func_t f, signal_type &signal_ref = NULL) { object = o; func = f; connect(signal_ref); }
+			inline void assign(object_type *o, func_t f, signal_type &signal_ref = NULL) { object = o; func = f; this->connect(signal_ref); }
 	
 			inline return_type operator() %s const { 
 				return (object->*func) %s ;
@@ -187,10 +187,10 @@ class Generator(object):
 			typedef base_signalXXX %s signal_type; 
 			typedef void (object_type::*func_t) %s ;
 
-			inline slotXXX () : object(NULL), func(NULL) {}
+			inline slotXXX () : object(0), func(0) {}
 			inline slotXXX (object_type *object, func_t func) : object(object), func(func) {}
 			inline void assign(object_type *o, func_t f) { object = o; func = f; }
-			inline void assign(object_type *o, func_t f, signal_type &signal_ref) { object = o; func = f; connect(signal_ref); }
+			inline void assign(object_type *o, func_t f, signal_type &signal_ref) { object = o; func = f; this->connect(signal_ref); }
 	
 			inline void operator() %s const { 
 				(object->*func) %s; 
