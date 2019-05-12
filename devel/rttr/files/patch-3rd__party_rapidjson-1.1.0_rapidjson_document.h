--- 3rd_party/rapidjson-1.1.0/rapidjson/document.h.orig	2019-01-18 18:25:46 UTC
+++ 3rd_party/rapidjson-1.1.0/rapidjson/document.h
@@ -1439,7 +1439,7 @@ class GenericValue { (public)
         MemberIterator pos = MemberBegin() + (first - MemberBegin());
         for (MemberIterator itr = pos; itr != last; ++itr)
             itr->~Member();
-        std::memmove(&*pos, &*last, static_cast<size_t>(MemberEnd() - last) * sizeof(Member));
+        std::memmove(static_cast<void*>(&*pos), &*last, static_cast<size_t>(MemberEnd() - last) * sizeof(Member));
         data_.o.size -= static_cast<SizeType>(last - first);
         return pos;
     }
@@ -1642,8 +1642,8 @@ class GenericValue { (public)
         RAPIDJSON_ASSERT(last <= End());
         ValueIterator pos = Begin() + (first - Begin());
         for (ValueIterator itr = pos; itr != last; ++itr)
-            itr->~GenericValue();
-        std::memmove(pos, last, static_cast<size_t>(End() - last) * sizeof(GenericValue));
+	    itr->~GenericValue();
+ 	 std::memmove(static_cast<void*>(pos), last, static_cast<size_t>(End() - last) * sizeof(GenericValue));
         data_.a.size -= static_cast<SizeType>(last - first);
         return pos;
     }
@@ -1950,7 +1950,7 @@ class GenericValue { (public)
         if (count) {
             GenericValue* e = static_cast<GenericValue*>(allocator.Malloc(count * sizeof(GenericValue)));
             SetElementsPointer(e);
-            std::memcpy(e, values, count * sizeof(GenericValue));
+	    std::memcpy(static_cast<void*>(e), values, count * sizeof(GenericValue));
         }
         else
             SetElementsPointer(0);
@@ -1963,7 +1963,7 @@ class GenericValue { (public)
         if (count) {
             Member* m = static_cast<Member*>(allocator.Malloc(count * sizeof(Member)));
             SetMembersPointer(m);
-            std::memcpy(m, members, count * sizeof(Member));
+ 	     std::memcpy(static_cast<void*>(m), members, count * sizeof(Member));
         }
         else
             SetMembersPointer(0);
