--- src/emu/netlist/pstate.h.orig
+++ src/emu/netlist/pstate.h
@@ -15,10 +15,13 @@
 // state saving ...
 // ----------------------------------------------------------------------------------------
 
-#define PSTATE_INTERFACE(manager, module)               \
-	template<class C> ATTR_COLD void save(C &state, const pstring &stname) \
+#define PSTATE_INTERFACE_DECL()               \
+	template<class C> ATTR_COLD void save(C &state, const pstring &stname);
+
+#define PSTATE_INTERFACE(obj, manager, module)               \
+	template<class C> ATTR_COLD void obj::save(C &state, const pstring &stname) \
 	{                                                                       \
-		dynamic_cast<pstate_manager_t &>(manager).save_manager(state, module + "." + stname);  \
+		manager->save_manager(state, module + "." + stname);  \
 	}
 
 enum netlist_data_type_e {
