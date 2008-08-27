--- src/ixlib_garbage.hh.orig	2001-06-20 01:16:29.000000000 +0200
+++ src/ixlib_garbage.hh	2008-08-27 17:54:47.000000000 +0200
@@ -126,24 +126,24 @@
       // compiler generates one, which is *ahem* - fatal
       ref(ref const &src)
         : ref_base<T>(src) {
-	reference_manager_keeper<T_Managed>::Manager.addReference(Instance);
+	reference_manager_keeper<T_Managed>::Manager.addReference(this->Instance);
 	}
       template<class T2>
       ref(ref<T2,T_Managed> const &src)
         : ref_base<T>(src.get()) {
-	reference_manager_keeper<T_Managed>::Manager.addReference(Instance);
+	reference_manager_keeper<T_Managed>::Manager.addReference(this->Instance);
 	}
       template<class T2>
       ref(no_free_ref<T2,T_Managed> const &src)
         : ref_base<T>(src.get()) {
-	reference_manager_keeper<T_Managed>::Manager.addReference(Instance);
+	reference_manager_keeper<T_Managed>::Manager.addReference(this->Instance);
 	}
       ref(T *instance = NULL)
         : ref_base<T>(instance) {
-	reference_manager_keeper<T_Managed>::Manager.addReference(Instance);
+	reference_manager_keeper<T_Managed>::Manager.addReference(this->Instance);
 	}
       ~ref() {
-        reference_manager_keeper<T_Managed>::Manager.freeReference(Instance);
+        reference_manager_keeper<T_Managed>::Manager.freeReference(this->Instance);
 	}
 	
       ref &operator=(ref const &src) {
@@ -157,20 +157,20 @@
       
       // methods
       void release() {
-	reference_manager_keeper<T_Managed>::Manager.freeReference(Instance);
-	Instance = NULL;
+	reference_manager_keeper<T_Managed>::Manager.freeReference(this->Instance);
+	this->Instance = NULL;
 	}
       void set(T *instance) {
-        if (instance == Instance) return;
+        if (instance == this->Instance) return;
 	
-	reference_manager_keeper<T_Managed>::Manager.freeReference(Instance);
-	Instance = instance;
-	reference_manager_keeper<T_Managed>::Manager.addReference(Instance);
+	reference_manager_keeper<T_Managed>::Manager.freeReference(this->Instance);
+	this->Instance = instance;
+	reference_manager_keeper<T_Managed>::Manager.addReference(this->Instance);
         }
       T *releaseFromGCArena() {
-        T *oldinst = Instance;
-	reference_manager_keeper<T_Managed>::Manager.forgetReference(Instance);
-	Instance = NULL;
+        T *oldinst = this->Instance;
+	reference_manager_keeper<T_Managed>::Manager.forgetReference(this->Instance);
+	this->Instance = NULL;
 	return oldinst;
         }
     };
@@ -200,24 +200,24 @@
       // compiler generates one, which is *ahem* - fatal
       no_free_ref(no_free_ref const &src)
         : ref_base<T>(src) {
-	reference_manager_keeper<T_Managed>::Manager.addNoFreeReference(Instance);
+	reference_manager_keeper<T_Managed>::Manager.addNoFreeReference(this->Instance);
 	}
       template<class T2>
       no_free_ref(ref<T2,T_Managed> const &src)
         : ref_base<T>(src.get()) {
-	reference_manager_keeper<T_Managed>::Manager.addNoFreeReference(Instance);
+	reference_manager_keeper<T_Managed>::Manager.addNoFreeReference(this->Instance);
 	}
       template<class T2>
       no_free_ref(no_free_ref<T2,T_Managed> const &src)
         : ref_base<T>(src.get()) {
-	reference_manager_keeper<T_Managed>::Manager.addNoFreeReference(Instance);
+	reference_manager_keeper<T_Managed>::Manager.addNoFreeReference(this->Instance);
 	}
       no_free_ref(T *instance = NULL)
         : ref_base<T>(instance) {
-	reference_manager_keeper<T_Managed>::Manager.addNoFreeReference(Instance);
+	reference_manager_keeper<T_Managed>::Manager.addNoFreeReference(this->Instance);
 	}
       ~no_free_ref() {
-        reference_manager_keeper<T_Managed>::Manager.removeNoFreeReference(Instance);
+        reference_manager_keeper<T_Managed>::Manager.removeNoFreeReference(this->Instance);
 	}
 	
       // assignment
@@ -232,20 +232,20 @@
       
       // methods
       void release() {
-	reference_manager_keeper<T_Managed>::Manager.removeNoFreeReference(Instance);
-	Instance = NULL;
+	reference_manager_keeper<T_Managed>::Manager.removeNoFreeReference(this->Instance);
+	this->Instance = NULL;
 	}
       void set(T *instance) {
-        if (instance == Instance) return;
+        if (instance == this->Instance) return;
 	
-	reference_manager_keeper<T_Managed>::Manager.removeNoFreeReference(Instance);
-	Instance = instance;
-	reference_manager_keeper<T_Managed>::Manager.addNoFreeReference(Instance);
+	reference_manager_keeper<T_Managed>::Manager.removeNoFreeReference(this->Instance);
+	this->Instance = instance;
+	reference_manager_keeper<T_Managed>::Manager.addNoFreeReference(this->Instance);
         }
       T *releaseFromGCArena() {
-        T *oldinst = Instance;
-	reference_manager_keeper<T_Managed>::Manager.forgetReference(Instance);
-	Instance = NULL;
+        T *oldinst = this->Instance;
+	reference_manager_keeper<T_Managed>::Manager.forgetReference(this->Instance);
+	this->Instance = NULL;
 	return oldinst;
         }
     };
@@ -265,14 +265,14 @@
     public:
       dynamic_ref(dynamic_ref const &src)
         : ref_base<T>(src),Manager(src.Manager) {
-	Manager.addReference(Instance);
+	Manager.addReference(this->Instance);
 	}
       dynamic_ref(reference_manager<T> &mgr,T *instance = NULL)
         : ref_base<T>(instance),Manager(mgr) {
-	Manager.addReference(Instance);
+	Manager.addReference(this->Instance);
 	}
       ~dynamic_ref() {
-        Manager.freeReference(Instance);
+        Manager.freeReference(this->Instance);
 	}
       
       // assignment
@@ -287,20 +287,20 @@
 
       // methods
       void release() {
-	Manager.freeReference(Instance);
-	Instance = NULL;
+	Manager.freeReference(this->Instance);
+	this->Instance = NULL;
 	}
       void set(T *instance) {
-        if (instance == Instance) return;
+        if (instance == this->Instance) return;
 	
-	Manager.freeReference(Instance);
-	Instance = instance;
-	Manager.addReference(Instance);
+	Manager.freeReference(this->Instance);
+	this->Instance = instance;
+	Manager.addReference(this->Instance);
         }
       T *releaseFromGCArena() {
-        T *oldinst = Instance;
-	Manager.forgetReference(Instance);
-	Instance = NULL;
+        T *oldinst = this->Instance;
+	Manager.forgetReference(this->Instance);
+	this->Instance = NULL;
 	return oldinst;
         }
     };
@@ -330,14 +330,14 @@
     public:
       no_free_dynamic_ref(no_free_dynamic_ref const &src)
         : ref_base<T>(src),Manager(src.Manager) {
-	Manager.addNoFreeReference(Instance);
+	Manager.addNoFreeReference(this->Instance);
 	}
       no_free_dynamic_ref(reference_manager<T> &mgr,T *instance = NULL)
         : ref_base<T>(instance),Manager(mgr) {
-	Manager.addNoFreeReference(Instance);
+	Manager.addNoFreeReference(this->Instance);
 	}
       ~no_free_dynamic_ref() {
-        Manager.removeNoFreeReference(Instance);
+        Manager.removeNoFreeReference(this->Instance);
 	}
       
       // assignment
@@ -352,20 +352,20 @@
 
       // methods
       void release() {
-	Manager.removeNoFreeReference(Instance);
-	Instance = NULL;
+	Manager.removeNoFreeReference(this->Instance);
+	this->Instance = NULL;
 	}
       void set(T *instance) {
-        if (instance == Instance) return;
+        if (instance == this->Instance) return;
 	
-	Manager.removeNoFreeReference(Instance);
-	Instance = instance;
-	Manager.addNoFreeReference(Instance);
+	Manager.removeNoFreeReference(this->Instance);
+	this->Instance = instance;
+	Manager.addNoFreeReference(this->Instance);
         }
       T *releaseFromGCArena() {
-        T *oldinst = Instance;
-	Manager.forgetReference(Instance);
-	Instance = NULL;
+        T *oldinst = this->Instance;
+	Manager.forgetReference(this->Instance);
+	this->Instance = NULL;
 	return oldinst;
         }
     };
@@ -440,7 +440,7 @@
 	
     private:
       hash_value hash(T const *ptr) const {
-        unsigned u = reinterpret_cast<unsigned>(ptr);
+        uintptr_t u = reinterpret_cast<uintptr_t>(ptr);
         return (u ^ (u >> 8) ^ (u >> 16) ^ (u >> 24)) & HASH_MAX;
         }
       instance_data *getHashEntry(T const *instance) {
@@ -482,7 +482,7 @@
 
 
   #define IXLIB_GARBAGE_DECLARE_MANAGER(TYPE) \
-    ixion::reference_manager<TYPE> ixion::reference_manager_keeper<TYPE>::Manager;
+    template <> ixion::reference_manager<TYPE> ixion::reference_manager_keeper<TYPE>::Manager = ixion::reference_manager<TYPE>();
   }
 
 
