--- rts/System/creg/creg.h.orig	2013-12-06 06:06:48.806486080 +0400
+++ rts/System/creg/creg.h	2013-12-06 07:18:09.477443592 +0400
@@ -442,10 +442,10 @@
 // Stupid GCC likes this template<> crap very much
 #define CR_BIND_TEMPLATE(TCls, ctor_args) \
 	template<> creg::IMemberRegistrator* TCls::memberRegistrator=0;	\
-	template<> creg::Class* TCls::GetClass() const { return binder.class_; } \
 	template<> void TCls::_ConstructInstance(void* d) { new(d) MyType ctor_args; } \
 	template<> void TCls::_DestructInstance(void* d) { ((MyType*)d)->~MyType(); } \
-	template<> creg::ClassBinder TCls::binder(#TCls, 0, 0, &TCls::memberRegistrator, sizeof(TCls), alignof(TCls), TCls::hasVTable, TCls::_ConstructInstance, TCls::_DestructInstance);
+	template<> creg::ClassBinder TCls::binder(#TCls, 0, 0, &TCls::memberRegistrator, sizeof(TCls), alignof(TCls), TCls::hasVTable, TCls::_ConstructInstance, TCls::_DestructInstance); \
+	template<> creg::Class* TCls::GetClass() const { return binder.class_; }
 
 /** @def CR_BIND_DERIVED_INTERFACE
  * Bind an abstract derived class
