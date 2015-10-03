--- bwtgap.c.orig	2014-02-25 21:20:01 UTC
+++ bwtgap.c
@@ -58,7 +58,7 @@ static inline void gap_push(gap_stack_t 
 		q->stack = (gap_entry_t*)realloc(q->stack, sizeof(gap_entry_t) * q->m_entries);
 	}
 	p = q->stack + q->n_entries;
-	p->info = (u_int32_t)score<<21 | i; p->k = k; p->l = l;
+	p->info = (uint32_t)score<<21 | i; p->k = k; p->l = l;
 	p->n_mm = n_mm; p->n_gapo = n_gapo; p->n_gape = n_gape;
 	p->n_ins = n_ins; p->n_del = n_del;
 	p->state = state; 
