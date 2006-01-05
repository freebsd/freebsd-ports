# http://lists.gnu.org/archive/html/qemu-devel/2005-05/msg00228.html

Index: qemu/slirp/mbuf.c
@@ -146,18 +146,19 @@
         struct mbuf *m;
         int size;
 {
+	int datasize;
+
 	/* some compiles throw up on gotos.  This one we can fake. */
         if(m->m_size>size) return;
 
         if (m->m_flags & M_EXT) {
-	  /* datasize = m->m_data - m->m_ext; */
+	  datasize = m->m_data - m->m_ext;
 	  m->m_ext = (char *)realloc(m->m_ext,size);
 /*		if (m->m_ext == NULL)
  *			return (struct mbuf *)NULL;
  */		
-	  /* m->m_data = m->m_ext + datasize; */
+	  m->m_data = m->m_ext + datasize;
         } else {
-	  int datasize;
 	  char *dat;
 	  datasize = m->m_data - m->m_dat;
 	  dat = (char *)malloc(size);
