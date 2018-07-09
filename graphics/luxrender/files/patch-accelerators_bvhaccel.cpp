After http://github.com/boostorg/range/commit/69409ed63a9e1 build fails:

accelerators/bvhaccel.cpp:149:19: error: call to 'distance' is ambiguous
                        u_int middle = distance(list.begin(), it);
                                       ^~~~~~~~
/usr/include/c++/v1/iterator:511:1: note: candidate function [with _InputIter = std::__1::__wrap_iter<boost::shared_ptr<lux::BVHAccelTreeNode> *>]
distance(_InputIter __first, _InputIter __last)
^
/usr/local/include/boost/iterator/distance.hpp:49:9: note: candidate function [with SinglePassIterator = std::__1::__wrap_iter<boost::shared_ptr<lux::BVHAccelTreeNode> *>]
        distance(SinglePassIterator first, SinglePassIterator last)
        ^

--- accelerators/bvhaccel.cpp.orig	2016-05-09 21:21:17 UTC
+++ accelerators/bvhaccel.cpp
@@ -146,7 +146,7 @@ boost::shared_ptr<BVHAccelTreeNode> BVHAccel::BuildHie
 
 			vector<boost::shared_ptr<BVHAccelTreeNode> >::iterator it =
 				partition(list.begin()+splits[j], list.begin()+splits[j+1], bind2nd(ptr_fun(bvh_ltf[splitAxis]), splitValue));
-			u_int middle = distance(list.begin(), it);
+			u_int middle = std::distance(list.begin(), it);
 			middle = max(splits[j]+1, min(splits[j+1]-1, middle)); // Make sure coincidental BBs are still split
 			splits.insert(splits.begin()+j+1, middle);
 		}
