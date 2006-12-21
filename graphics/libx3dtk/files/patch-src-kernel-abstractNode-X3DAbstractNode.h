*** src/kernel/abstractNode/X3DAbstractNode.h.orig	Sat Dec 16 16:20:51 2006
--- src/kernel/abstractNode/X3DAbstractNode.h	Sat Dec 16 16:21:07 2006
***************
*** 102,108 ****
    inline void defineTypeName(const SFString &name, const SFString &component = SFString(""), const SFString &sceneGraph = SFString("")) {defineTempTypeName(this, name, component, sceneGraph);};
    /// Method to avoid defineTypeName having a template parameter.
    template<class T>
!   inline void defineTempTypeName(T *t, const SFString &name, const SFString &component, const SFString &sceneGraph) {define(Recorder<T>::getTypeName(name, component, sceneGraph));};
    /// Defines an attribute.
    template<class T, class V>
    inline void defineAttribute(const SFString &name, V T:: *member, const V &init);
--- 102,108 ----
    inline void defineTypeName(const SFString &name, const SFString &component = SFString(""), const SFString &sceneGraph = SFString("")) {defineTempTypeName(this, name, component, sceneGraph);};
    /// Method to avoid defineTypeName having a template parameter.
    template<class T>
!   inline void defineTempTypeName(T * /* t */, const SFString &name, const SFString &component, const SFString &sceneGraph) {define(Recorder<T>::getTypeName(name, component, sceneGraph));};
    /// Defines an attribute.
    template<class T, class V>
    inline void defineAttribute(const SFString &name, V T:: *member, const V &init);
