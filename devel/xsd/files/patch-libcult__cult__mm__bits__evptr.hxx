clang build fix: cult/mm/evptr.hxx has
  using Base::p_;
  using Base::cp_;
  using Base::c_;
in a public section, but these members are private here.
--- libcult/cult/mm/bits/evptr.hxx~	2012-08-06 20:07:10.000000000 -0300
+++ libcult/cult/mm/bits/evptr.hxx	2012-08-06 20:11:24.000000000 -0300
@@ -227,6 +227,7 @@
         template <typename>
         friend class Transfer;
 
+      protected:
         mutable X* p_;
         mutable X const* cp_;
         mutable Counter* c_;
@@ -337,6 +338,7 @@
         template <typename>
         friend class Transfer;
 
+      protected:
         mutable X const* p_;
         mutable X const* cp_;
         mutable Counter* c_;
