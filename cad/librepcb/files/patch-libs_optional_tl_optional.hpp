- workaround for https://github.com/LibrePCB/LibrePCB/issues/1454

--- libs/optional/tl/optional.hpp.orig	2024-10-31 19:31:32 UTC
+++ libs/optional/tl/optional.hpp
@@ -1979,17 +1979,6 @@ template <class T> class optional<T &> { (public)
     return *this;
   }
 
-  /// Constructs the value in-place, destroying the current one if there is
-  /// one.
-  template <class... Args> T &emplace(Args &&... args) noexcept {
-    static_assert(std::is_constructible<T, Args &&...>::value,
-                  "T must be constructible with Args");
-
-    *this = nullopt;
-    this->construct(std::forward<Args>(args)...);
-    return value();
-  }
-
   void swap(optional &rhs) noexcept { std::swap(m_value, rhs.m_value); }
 
   /// Returns a pointer to the stored value
