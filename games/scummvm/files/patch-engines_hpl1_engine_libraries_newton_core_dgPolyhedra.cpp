The HPL1 engine seems to be still under heavy development so this is
rather a workaround to fix the build on x64 platforms with Clang which
is very strict regarding pointer conversions to smaller types.

Amend this issue after brief consultation with upstream by using
`PointerToInt(NULL)` instead of `dgUnsigned32(NULL)`.

Obtained from:

https://github.com/scummvm/scummvm/commit/5304df12f1232ddcfa33fcffed1cd5fb4ad01275

--- engines/hpl1/engine/libraries/newton/core/dgPolyhedra.cpp.orig	2023-02-13 22:19:11 UTC
+++ engines/hpl1/engine/libraries/newton/core/dgPolyhedra.cpp
@@ -2714,7 +2714,7 @@ void dgPolyhedra::Optimize(const dgFloat64 *const arra
 							if (handle) {
 								handle->m_edge = NULL;
 							}
-							ptr->m_userData = dgUnsigned32(NULL);
+							ptr->m_userData = PointerToInt(NULL);
 
 						}
 
@@ -2753,7 +2753,7 @@ void dgPolyhedra::Optimize(const dgFloat64 *const arra
 									if (handle) {
 										handle->m_edge = NULL;
 									}
-									ptr1->m_userData = dgUnsigned32(NULL);
+									ptr1->m_userData = PointerToInt(NULL);
 
 								}
 							}
@@ -2780,7 +2780,7 @@ void dgPolyhedra::Optimize(const dgFloat64 *const arra
 									if (handle) {
 										handle->m_edge = NULL;
 									}
-									ptr1->m_twin->m_userData = dgUnsigned32(NULL);
+									ptr1->m_twin->m_userData = PointerToInt(NULL);
 
 								}
 							}
