--- raul/AtomicInt.hpp.orig	2008-11-16 16:23:19.000000000 +0100
+++ raul/AtomicInt.hpp	2008-11-16 16:32:45.000000000 +0100
@@ -27,22 +27,22 @@
 public:
 	
 	inline AtomicInt(int val)
-		{ g_atomic_int_set(&_val, val); }
+		{ g_atomic_int_set((volatile gint *)&_val, (gint)val); }
 
 	inline AtomicInt(const AtomicInt& copy)
-		{ g_atomic_int_set(&_val, copy.get()); }
+		{ g_atomic_int_set((volatile gint *)&_val, (gint)copy.get()); }
 	
 	inline int get() const
-		{ return g_atomic_int_get(&_val); }
+		{ return g_atomic_int_get((volatile gint *)&_val); }
 
 	inline void operator=(int val)
-		{ g_atomic_int_set(&_val, val); }
+		{ g_atomic_int_set((volatile gint *)&_val, (gint)val); }
 
 	inline void operator+=(int val)
-		{ g_atomic_int_add(&_val, val); }
+		{ g_atomic_int_add((volatile gint *)&_val, (gint)val); }
 	
 	inline void operator-=(int val)
-		{ g_atomic_int_add(&_val, -val); }
+		{ g_atomic_int_add((volatile gint *)&_val, (gint)-val); }
 	
 	inline bool operator==(int val) const
 		{ return get() == val; }
@@ -51,28 +51,28 @@
 		{ return get() + val; }
 
 	inline AtomicInt& operator++() // prefix
-		{ g_atomic_int_inc(&_val); return *this; }
+		{ g_atomic_int_inc((volatile gint *)&_val); return *this; }
 	
 	inline AtomicInt& operator--() // prefix
-		{ g_atomic_int_add(&_val, -1); return *this; }
+		{ g_atomic_int_add((volatile gint *)&_val, -1); return *this; }
 	
 	/** Set value to newval iff current value is oldval.
 	 * @return whether set succeeded.
 	 */
 	inline bool compare_and_exchange(int oldval, int newval)
-		{ return g_atomic_int_compare_and_exchange(&_val, oldval, newval); }
+		{ return g_atomic_int_compare_and_exchange((volatile gint *)&_val, (gint)oldval, (gint)newval); }
 
 	/** Add val to value.
 	 * @return value immediately before addition took place.
 	 */
 	inline int exchange_and_add(int val)
-		{ return g_atomic_int_exchange_and_add(&_val, val); }
+		{ return g_atomic_int_exchange_and_add((volatile gint *)&_val, (gint)val); }
 
 	/** Decrement value.
 	 * @return true if value is now 0, otherwise false.
 	 */
 	inline bool decrement_and_test()
-		{ return g_atomic_int_dec_and_test(&_val); }
+		{ return g_atomic_int_dec_and_test((gint *)&_val); }
 
 private:
 	volatile int _val;
