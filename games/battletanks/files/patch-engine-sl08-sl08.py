From: Ansgar Burchardt <ansgar@debian.org>
Bug-Debian: http://bugs.debian.org/624916
Subject: Fix FTBFS with gcc-4.6

Update: Add missing this->'s to appease Clang
Update2: Convert to Python 3.x syntax (2020/01/28)

--- engine/sl08/sl08.py.orig	2008-08-13 09:10:45 UTC
+++ engine/sl08/sl08.py
@@ -26,7 +26,7 @@ class Generator(object):
 		
 	def prototype(self, proto):	
 		r = '('
-		for i in xrange(0, self.__n): 
+		for i in range(0, self.__n): 
 			if proto: 
 				r = r + "arg%d_type " %(i + 1)
 			r = r + "a%d" %(i + 1)
@@ -41,14 +41,14 @@ class Generator(object):
 			r = '<typename return_type'
 		
 		if cname == 'base-signal': 
-			for i in xrange(0, self.__n): 
+			for i in range(0, self.__n): 
 				if not void or i > 0:
 					r = r + ", "
 				r = r + "typename arg%d_type" %(i + 1)
 			r = r + ">"
 			return r
 		elif cname == 'signal': 
-			for i in xrange(0, self.__n): 
+			for i in range(0, self.__n): 
 				if not void or i > 0:
 					r = r + ", "
 				r = r + "typename arg%d_type" %(i + 1)
@@ -61,7 +61,7 @@ class Generator(object):
 				r = r + "class validator_type = default_validator<return_type> >"
 			return r
 		elif cname == 'slot': 
-			for i in xrange(0, self.__n): 
+			for i in range(0, self.__n): 
 				if not void or i > 0:
 					r = r + ", "
 				r = r + "typename arg%d_type" %(i + 1)
@@ -70,7 +70,7 @@ class Generator(object):
 			r = r + "class object_type>"
 			return r
 		elif cname == 'base-slot': 
-			for i in xrange(0, self.__n): 
+			for i in range(0, self.__n): 
 				if not void or i > 0:
 					r = r + ", "
 				r = r + "typename arg%d_type" %(i + 1)
@@ -86,22 +86,22 @@ class Generator(object):
 			r = '<return_type'
 		
 		if cname == 'base-signal': 
-			for i in xrange(0, self.__n): 
+			for i in range(0, self.__n): 
 				r = r + ", arg%d_type" %(i + 1)
 			r = r + ">"
 			return r
 		elif cname == 'signal': 
-			for i in xrange(0, self.__n): 
+			for i in range(0, self.__n): 
 				r = r + ", arg%d_type" %(i + 1)
 			r = r + ", validator_type>"
 			return r
 		elif cname == 'slot': 
-			for i in xrange(0, self.__n): 
+			for i in range(0, self.__n): 
 				r = r + ", arg%d_type" %(i + 1)
 			r = r + ", object_type>"
 			return r
 		elif cname == 'base-slot': 
-			for i in xrange(0, self.__n): 
+			for i in range(0, self.__n): 
 				r = r + ", arg%d_type" %(i + 1)
 			r = r + ">"
 			return r
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
@@ -329,11 +329,11 @@ class Generator(object):
 		
 
 text = ''
-for i in xrange(0, 6):
+for i in range(0, 6):
 	g = Generator(i)
 	text = text + "\n" + g.generate(); 
 
-print """#ifndef BTANKS_SL08_SLOTSANDSIGNALS_H__
+print("""#ifndef BTANKS_SL08_SLOTSANDSIGNALS_H__
 #define BTANKS_SL08_SLOTSANDSIGNALS_H__
 
 /* sl08 - small slot/signals library
@@ -387,5 +387,5 @@ namespace sl08 {
 }
 
 #endif
-""" %(text);
+""" %(text));
 
