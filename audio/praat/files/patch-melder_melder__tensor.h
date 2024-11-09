--- melder/melder_tensor.h.orig	2024-10-29 19:52:21 UTC
+++ melder/melder_tensor.h
@@ -155,10 +155,6 @@ struct vectorview {
 		Melder_assert (last >= 1 && last <= our size);
 		return vectorview<T> (& our operator[] (first), newSize, our stride);
 	}
-	matrixview<T> asmatrixview (integer nrow, integer ncol) {
-		Melder_assert (nrow * ncol <= our size);
-		return matrixview (our cells, nrow, ncol, ncol * our stride, our stride);
-	}
 	T *asArgumentToFunctionThatExpectsZeroBasedArray () const { return & our operator[] (1); }
 	T *asArgumentToFunctionThatExpectsOneBasedArray () const { return & our operator[] (0); }
 };
@@ -188,10 +184,6 @@ struct constvectorview {
 		Melder_assert (last >= 1 && last <= our size);
 		return constvectorview<T> (& our operator[] (first), newSize, our stride);
 	}
-	constmatrixview<T> asmatrixview (integer nrow, integer ncol) {
-		Melder_assert (nrow * ncol <= our size);
-		return constmatrixview (our cells, nrow, ncol, ncol * our stride, our stride);
-	}
 	const T *asArgumentToFunctionThatExpectsZeroBasedArray () const { return & our operator[] (1); }
 	const T *asArgumentToFunctionThatExpectsOneBasedArray () const { return & our operator[] (0); }
 };
@@ -1049,7 +1041,7 @@ struct consttensor3 {
 			our cells
 			+ (dim2 - 1) * our stride2
 			+ (dim3 - 1) * our stride3,
-			our nidm1,
+			our ndim1,
 			our stride1
 		);
 	}
