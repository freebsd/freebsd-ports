--- src/plugins/projectexplorer/runconfiguration.h.orig	2016-06-24 12:44:00 UTC
+++ src/plugins/projectexplorer/runconfiguration.h
@@ -159,6 +159,7 @@ public:
     virtual ~ClonableConcept() = default;
     virtual ClonableConcept *clone() const = 0;
     virtual bool equals(const std::unique_ptr<ClonableConcept> &other) const = 0;
+    virtual void *typeId() const = 0;
 };
 
 template <class T>
@@ -168,11 +169,16 @@ public:
     ClonableModel(const T &data) : m_data(data) { }
     ~ClonableModel() Q_DECL_NOEXCEPT { } // gcc 4.7.3
     ClonableConcept *clone() const override { return new ClonableModel(*this); }
+    void *typeId() const { return T::staticTypeId; }
 
     bool equals(const std::unique_ptr<ClonableConcept> &other) const override
     {
-        auto that = dynamic_cast<const ClonableModel<T> *>(other.get());
-        return that && m_data == that->m_data;
+        if (!other.get())
+            return false;
+        if (other->typeId() != typeId())
+            return false;
+        auto that = static_cast<const ClonableModel<T> *>(other.get());
+        return m_data == that->m_data;
     }
 
     T m_data;
@@ -189,7 +195,7 @@ public:
     void operator=(Runnable other) { d = std::move(other.d); }
 
     template <class T> bool is() const {
-        return dynamic_cast<ClonableModel<T> *>(d.get()) != 0;
+        return d.get()->typeId() == T::staticTypeId;
     }
 
     template <class T> const T &as() const {
@@ -213,7 +219,7 @@ public:
     void operator=(Connection other) { d = std::move(other.d); }
 
     template <class T> bool is() const {
-        return dynamic_cast<ClonableModel<T> *>(d.get()) != 0;
+        return d.get()->typeId() == T::staticTypeId;
     }
 
     template <class T> const T &as() const {
