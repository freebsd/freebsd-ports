--- gcc/dumpfile.c.orig	2020-04-07 14:09:14 UTC
+++ gcc/dumpfile.c
@@ -2055,7 +2055,7 @@ temp_dump_context::temp_dump_context (bool forcibly_en
 				      bool forcibly_enable_dumping,
 				      dump_flags_t test_pp_flags)
 : m_context (),
-  m_saved (&dump_context ().get ())
+  m_saved(&dump_context::get())
 {
   dump_context::s_current = &m_context;
   if (forcibly_enable_optinfo)
