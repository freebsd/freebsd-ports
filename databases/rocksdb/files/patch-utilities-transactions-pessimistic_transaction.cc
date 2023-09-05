--- utilities/transactions/pessimistic_transaction.cc.orig	2023-09-01 20:58:39 UTC
+++ utilities/transactions/pessimistic_transaction.cc
@@ -688,7 +688,7 @@ Status WriteCommittedTxn::CommitWithoutPrepareInternal
           const Comparator* ucmp =
               WriteBatchWithIndexInternal::GetUserComparator(*wbwi, cf);
           return ucmp ? ucmp->timestamp_size()
-                      : std::numeric_limits<uint64_t>::max();
+                      : std::numeric_limits<size_t>::max();
         });
     if (!s.ok()) {
       return s;
@@ -763,7 +763,7 @@ Status WriteCommittedTxn::CommitInternal() {
         const Comparator* ucmp =
             WriteBatchWithIndexInternal::GetUserComparator(*wbwi, cf);
         return ucmp ? ucmp->timestamp_size()
-                    : std::numeric_limits<uint64_t>::max();
+                    : std::numeric_limits<size_t>::max();
       });
     }
   }
