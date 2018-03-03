--- src/core/lib/gpr/arena.cc.orig	2018-03-02 14:59:20 UTC
+++ src/core/lib/gpr/arena.cc
@@ -83,7 +83,7 @@ void* gpr_arena_alloc(gpr_arena* arena, 
           ROUND_UP_TO_ALIGNMENT_SIZE(sizeof(zone)) + next_z_size));
       next_z->size_begin = z->size_end;
       next_z->size_end = z->size_end + next_z_size;
-      if (!gpr_atm_rel_cas(&z->next_atm, static_cast<gpr_atm>(NULL),
+      if (!gpr_atm_rel_cas(&z->next_atm, (gpr_atm)NULL,
                            (gpr_atm)next_z)) {
         gpr_free_aligned(next_z);
         next_z = (zone*)gpr_atm_acq_load(&z->next_atm);
