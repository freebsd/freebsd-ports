--- src/emu/netlist/nl_base.h.orig
+++ src/emu/netlist/nl_base.h
@@ -287,7 +287,7 @@
 
 	ATTR_COLD const pstring &name() const;
 
-	PSTATE_INTERFACE(*m_netlist, name())
+	PSTATE_INTERFACE_DECL()
 
 #if 0
 	template<class C> ATTR_COLD void save(C &state, const pstring &stname)
@@ -1120,6 +1120,8 @@
 // Inline implementations
 // ----------------------------------------------------------------------------------------
 
+PSTATE_INTERFACE(netlist_object_t, m_netlist, name())
+
 ATTR_HOT inline void netlist_param_str_t::setTo(const pstring &param)
 {
 	m_param = param;
