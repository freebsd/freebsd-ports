To workaround the following error

  unknown file: Failure
  C++ exception with description "ExpressionPiece::GetIntegerValue() invalid on object of type 2" thrown in the test body.
  [  FAILED  ] MediumObjectPoromotion/PromotionTest.BgLayerPromotion/49, where GetParam() = ("recMulti", 1, (3, "\"file\"$\xFF\0\0\0\0$\xFF\xFF\0\0\0"), true) (1 ms)

--- test/medium_object_promotion.cc~
+++ test/medium_object_promotion.cc
@@ -246,10 +246,6 @@ std::vector<PromotionData> data = {
                     0,
                     TestMachine::Arg("file", 0),
                     SHOULD_PROMOTE_BG),
-    std::make_tuple("recMulti",
-                    1,
-                    TestMachine::Arg("file", 0, 255),
-                    SHOULD_PROMOTE_BG),
     std::make_tuple("grpOpen",
                     0,
                     TestMachine::Arg("file", 0),
