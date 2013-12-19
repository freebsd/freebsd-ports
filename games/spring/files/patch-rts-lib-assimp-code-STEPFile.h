--- rts/lib/assimp/code/STEPFile.h.orig	2013-03-26 03:58:36.000000000 +0400
+++ rts/lib/assimp/code/STEPFile.h	2013-11-11 04:15:43.177772957 +0400
@@ -195,13 +195,13 @@
 			// conversion support.
 			template <typename T>
 			const T& ResolveSelect(const DB& db) const {
-				return Couple<T>(db).MustGetObject(To<EXPRESS::ENTITY>())->To<T>();
+				return Couple<T>(db).MustGetObject(To<EXPRESS::ENTITY>())->template To<T>();
 			}
 
 			template <typename T>
 			const T* ResolveSelectPtr(const DB& db) const {
 				const EXPRESS::ENTITY* e = ToPtr<EXPRESS::ENTITY>();
-				return e?Couple<T>(db).MustGetObject(*e)->ToPtr<T>():(const T*)0;
+				return e?Couple<T>(db).MustGetObject(*e)->template ToPtr<T>():(const T*)0;
 			}
 
 		public:
