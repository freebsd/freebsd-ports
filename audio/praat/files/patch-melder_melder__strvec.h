--- melder/melder_strvec.h.orig	2024-10-29 19:53:40 UTC
+++ melder/melder_strvec.h
@@ -192,12 +192,6 @@ class _autostringautovector { (public)
 		return _autostringvectorview<T> (our elements + (firstPosition - 1), newSize);
 	}
 	_autostringautovector&& move () noexcept { return static_cast <_autostringautovector&&> (*this); }   // enable construction and assignment for l-values (variables) via explicit move()
-	void initWithCapacity (integer capacity) {
-		if (capacity > 0)
-			our cells = MelderArray:: _alloc <_autostring <T>> (capacity, MelderArray::kInitializationType::ZERO);
-		our size = 0;
-		our _capacity = capacity;
-	}
 	void resize (integer newSize) {
 		if (newSize > our _capacity) {
 			/*
