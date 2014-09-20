--- common/kernel.c.orig
+++ common/kernel.c
@@ -341,7 +341,7 @@ static void kqemu_del_state(struct kqemu
     }
 }
 
-struct kqemu_global_state *kqemu_global_init(int max_locked_pages)
+struct kqemu_global_state * CDECL kqemu_global_init(int max_locked_pages)
 {
     struct kqemu_global_state *g;
     
@@ -354,13 +354,13 @@ struct kqemu_global_state *kqemu_global_
     return g;
 }
 
-void kqemu_global_delete(struct kqemu_global_state *g)
+void CDECL kqemu_global_delete(struct kqemu_global_state *g)
 {
     /* XXX: free all existing states ? */
     kqemu_vfree(g);
 }
 
-struct kqemu_state *kqemu_init(struct kqemu_init *d, 
+struct kqemu_state * CDECL kqemu_init(struct kqemu_init *d, 
                                struct kqemu_global_state *g)
 {
     struct kqemu_state *s;
@@ -756,7 +756,7 @@ struct kqemu_state *kqemu_init(struct kq
     return NULL;
 }
 
-int kqemu_set_phys_mem(struct kqemu_state *s,
+int CDECL kqemu_set_phys_mem(struct kqemu_state *s,
                        const struct kqemu_phys_mem *kphys_mem)
 {
     uint64_t start, size, end, addr;
@@ -951,7 +951,7 @@ static void profile_dump(struct kqemu_st
 }
 #endif
 
-void kqemu_delete(struct kqemu_state *s)
+void CDECL kqemu_delete(struct kqemu_state *s)
 {
     uint8_t *s1;
     struct kqemu_ram_page *rp;
@@ -990,7 +990,7 @@ void kqemu_delete(struct kqemu_state *s)
     kqemu_vfree(s1);
 }
 
-struct kqemu_cpu_state *kqemu_get_cpu_state(struct kqemu_state *s)
+struct kqemu_cpu_state * CDECL kqemu_get_cpu_state(struct kqemu_state *s)
 {
     return &s->cpu_state;
 }
@@ -1063,7 +1063,7 @@ static void apic_restore_nmi(struct kqem
     }\
 }
 
-long kqemu_exec(struct kqemu_state *s)
+long CDECL kqemu_exec(struct kqemu_state *s)
 {
     const struct monitor_code_header *m = (void *)monitor_code;
     void (*kernel2monitor)(struct kqemu_state *s) = 
