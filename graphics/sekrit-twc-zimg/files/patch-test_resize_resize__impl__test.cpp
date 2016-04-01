test/resize/resize_impl_test.cpp:37:3: error: no matching conversion for functional-style cast from
      'std::__1::unique_ptr<zimg::graph::ImageFilter,
      std::__1::default_delete<zimg::graph::ImageFilter> >' to '::testing::AssertionResult'
                ASSERT_TRUE(filter);
                ^~~~~~~~~~~~~~~~~~~
/usr/local/include/gtest/gtest.h:1921:3: note: expanded from macro 'ASSERT_TRUE'
  GTEST_TEST_BOOLEAN_(condition, #condition, false, true, \
  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/local/include/gtest/internal/gtest-internal.h:1111:7: note: expanded from macro
      'GTEST_TEST_BOOLEAN_'
      ::testing::AssertionResult(expression)) \
      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/local/include/gtest/gtest.h:260:3: note: candidate constructor not viable: no known conversion
      from 'std::__1::unique_ptr<zimg::graph::ImageFilter,
      std::__1::default_delete<zimg::graph::ImageFilter> >' to 'const testing::AssertionResult' for
      1st argument
  AssertionResult(const AssertionResult& other);
  ^
/usr/local/include/gtest/gtest.h:262:12: note: candidate constructor not viable: no known conversion
      from 'std::__1::unique_ptr<zimg::graph::ImageFilter,
      std::__1::default_delete<zimg::graph::ImageFilter> >' to 'bool' for 1st argument
  explicit AssertionResult(bool success) : success_(success) {}
           ^
1 error generated.

--- test/resize/resize_impl_test.cpp.orig	2016-01-22 18:12:28 UTC
+++ test/resize/resize_impl_test.cpp
@@ -34,7 +34,7 @@ void test_case(const zimg::PixelFormat &
 			set_shift(shift).
 			set_subwidth(subwidth_factor * (horizontal ? src_w : src_h)).create();
 
-		ASSERT_TRUE(filter);
+		ASSERT_TRUE(static_cast<bool>(filter));
 		validate_filter(filter.get(), src_w, src_h, format, expected_sha1[sha1_idx++]);
 	}
 }
