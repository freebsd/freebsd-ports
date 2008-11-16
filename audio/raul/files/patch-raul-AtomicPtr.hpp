--- raul/AtomicPtr.hpp.orig	2008-11-16 16:20:09.000000000 +0100
+++ raul/AtomicPtr.hpp	2008-11-16 16:23:06.000000000 +0100
@@ -28,20 +28,20 @@
 public:
 
 	inline AtomicPtr()
-		{ g_atomic_pointer_set(&_val, NULL); }
+		{ g_atomic_pointer_set((volatile gpointer *)&_val, NULL); }
 
 	inline AtomicPtr(const AtomicPtr& copy)
-		{ g_atomic_pointer_set(&_val, copy.get()); }
+		{ g_atomic_pointer_set((volatile gpointer *)&_val, (gpointer)copy.get()); }
 
 	inline T* get() const
-		{ return (T*)g_atomic_pointer_get(&_val); }
+		{ return (T*)g_atomic_pointer_get((volatile gpointer *)&_val); }
 
 	inline void operator=(T* val)
-		{ g_atomic_pointer_set(&_val, val); }
+		{ g_atomic_pointer_set((volatile gpointer *)&_val, (gpointer)val); }
 
 	/** Set value to newval iff current value is oldval */
 	inline bool compare_and_exchange(int oldval, int newval)
-		{ return g_atomic_pointer_compare_and_exchange(&_val, oldval, newval); }
+		{ return g_atomic_pointer_compare_and_exchange((volatile gpointer *)&_val, oldval, newval); }
 
 private:
 	volatile T* _val;
