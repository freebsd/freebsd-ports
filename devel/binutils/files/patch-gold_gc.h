From 10b4dbbf281397e2827820c715c39559c7f7a29d Mon Sep 17 00:00:00 2001
From: Alan Modra <amodra@gmail.com>
Date: Tue, 20 Jul 2021 18:46:57 +0930
Subject: [PATCH] PR28106, build of 2.37 fails on FreeBSD and Clang

https://en.cppreference.com/w/cpp/types/NULL says NULL might be
defined as nullptr.
https://en.cppreference.com/w/cpp/language/reinterpret_cast says
reinterpret_cast can't be used on nullptr.

	PR gold/28106
	PR gold/27815
	* gc.h (gc_process_relocs): Use static_cast in Section_id constructor.

(cherry picked from commit b97bd976233ee4d43c2fe18f6356e62779cbe82d)
---
 gold/ChangeLog | 6 ++++++
 gold/gc.h      | 4 ++--
 2 files changed, 8 insertions(+), 2 deletions(-)

diff --git gold/gc.h gold/gc.h
index 6ebd81f3fd0..4a1368f5abe 100644
--- gold/gc.h
+++ gold/gc.h
@@ -247,7 +247,7 @@ gc_process_relocs(
 	      if (is_ordinary) 
 		(*secvec).push_back(Section_id(src_obj, dst_indx));
 	      else
-		(*secvec).push_back(Section_id(reinterpret_cast<Relobj*>(NULL), 0));
+		(*secvec).push_back(Section_id(static_cast<Relobj*>(NULL), 0));
               // If the target of the relocation is an STT_SECTION symbol,
               // make a note of that by storing -1 in the symbol vector.
               if (lsym.get_st_type() == elfcpp::STT_SECTION)
@@ -329,7 +329,7 @@ gc_process_relocs(
               if (is_ordinary && dst_obj != NULL)
 		(*secvec).push_back(Section_id(dst_obj, dst_indx));
 	      else
-		(*secvec).push_back(Section_id(reinterpret_cast<Relobj*>(NULL), 0));
+		(*secvec).push_back(Section_id(static_cast<Relobj*>(NULL), 0));
               (*symvec).push_back(gsym);
 	      (*addendvec).push_back(std::make_pair(
 					static_cast<long long>(symvalue),
-- 
2.32.0

