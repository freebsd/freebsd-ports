--- lib/third_party/HashLibPlus/Base/Hash.h.orig	2024-02-23 13:24:13 UTC
+++ lib/third_party/HashLibPlus/Base/Hash.h
@@ -214,7 +214,7 @@ class Hash : public virtual IIHash (public)
 		{
 			if (a_length > -1)
 			{
-				if (UInt64(a_stream.tellg() + a_length) > size)
+				if (UInt64(a_stream.tellg()) + a_length > size)
 					throw IndexOutOfRangeHashLibException(IndexOutOfRange);
 			} // end if
 
