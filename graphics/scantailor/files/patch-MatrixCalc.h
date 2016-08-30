--- math/MatrixCalc.h
+++ math/MatrixCalc.h
@@ -74,7 +74,7 @@ class DynamicPoolAllocator : public AbstractAllocator<T>
 template<typename T>
 class Mat
 {
-	template<typename OT, typename Alloc> friend class MatrixCalc;
+	template<typename OT, typename Alloc> friend class ::MatrixCalc;
 	template<typename OT> friend Mat<OT> operator+(Mat<OT> const& m1, Mat<OT> const& m2);
 	template<typename OT> friend Mat<OT> operator-(Mat<OT> const& m1, Mat<OT> const& m2);
 	template<typename OT> friend Mat<OT> operator*(Mat<OT> const& m1, Mat<OT> const& m2);

