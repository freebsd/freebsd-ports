--- boost/signals2/detail/signal_template.hpp.orig	2023-12-06 21:03:06 UTC
+++ boost/signals2/detail/signal_template.hpp
@@ -103,9 +103,9 @@ namespace boost
               BOOST_SIGNALS2_FORWARDED_ARGS(BOOST_SIGNALS2_NUM_ARGS));
         }
         template<typename T>
-          bool operator==(const T &other) const
+          bool contains(const T &other) const
         {
-          return _fun == other;
+          return _fun.contains(other);
         }
       private:
         BOOST_SIGNALS2_BOUND_EXTENDED_SLOT_FUNCTION_N(BOOST_SIGNALS2_NUM_ARGS)()
@@ -116,6 +116,8 @@ namespace boost
       };
 
       template<BOOST_SIGNALS2_SIGNAL_TEMPLATE_DECL(BOOST_SIGNALS2_NUM_ARGS)>
+        class BOOST_SIGNALS2_WEAK_SIGNAL_CLASS_NAME(BOOST_SIGNALS2_NUM_ARGS);
+      template<BOOST_SIGNALS2_SIGNAL_TEMPLATE_DECL(BOOST_SIGNALS2_NUM_ARGS)>
         class BOOST_SIGNALS2_SIGNAL_IMPL_CLASS_NAME(BOOST_SIGNALS2_NUM_ARGS);
 
       template<BOOST_SIGNALS2_SIGNAL_TEMPLATE_SPECIALIZATION_DECL(BOOST_SIGNALS2_NUM_ARGS)>
@@ -150,6 +152,8 @@ namespace boost
         typedef GroupCompare group_compare_type;
         typedef typename detail::slot_call_iterator_t<slot_invoker,
           typename connection_list_type::iterator, connection_body<group_key_type, slot_type, Mutex> > slot_call_iterator;
+        typedef detail::BOOST_SIGNALS2_WEAK_SIGNAL_CLASS_NAME(BOOST_SIGNALS2_NUM_ARGS)
+          <BOOST_SIGNALS2_SIGNAL_TEMPLATE_INSTANTIATION> weak_signal_type;
 
         BOOST_SIGNALS2_SIGNAL_IMPL_CLASS_NAME(BOOST_SIGNALS2_NUM_ARGS)(const combiner_type &combiner_arg,
           const group_compare_type &group_compare):
@@ -219,7 +223,7 @@ namespace boost
         void disconnect(const T &slot)
         {
           typedef mpl::bool_<(is_convertible<T, group_type>::value)> is_group;
-          do_disconnect(slot, is_group());
+          do_disconnect(unwrap_ref(slot), is_group());
         }
         // emit signal
         result_type operator ()(BOOST_SIGNALS2_SIGNATURE_FULL_ARGS(BOOST_SIGNALS2_NUM_ARGS))
@@ -531,13 +535,20 @@ namespace boost
             {
               (*it)->nolock_disconnect(lock);
             }else
-            {
-              // check for wrapped extended slot
+            { // check for wrapped extended slot
               bound_extended_slot_function_type *fp;
               fp = (*it)->slot().slot_function().template target<bound_extended_slot_function_type>();
-              if(fp && function_equal(*fp, slot))
+              if(fp && fp->contains(slot))
               {
                 (*it)->nolock_disconnect(lock);
+              }else
+              { // check for wrapped signal
+                weak_signal_type *fp;
+                fp = (*it)->slot().slot_function().template target<weak_signal_type>();
+                if(fp && fp->contains(slot))
+                {
+                  (*it)->nolock_disconnect(lock);
+                }
               }
             }
           }
@@ -588,8 +599,6 @@ namespace boost
         const boost::shared_ptr<mutex_type> _mutex;
       };
 
-      template<BOOST_SIGNALS2_SIGNAL_TEMPLATE_DECL(BOOST_SIGNALS2_NUM_ARGS)>
-        class BOOST_SIGNALS2_WEAK_SIGNAL_CLASS_NAME(BOOST_SIGNALS2_NUM_ARGS);
     }
 
     template<BOOST_SIGNALS2_SIGNAL_TEMPLATE_DEFAULTED_DECL(BOOST_SIGNALS2_NUM_ARGS)>
@@ -603,8 +612,7 @@ namespace boost
       typedef detail::BOOST_SIGNALS2_SIGNAL_IMPL_CLASS_NAME(BOOST_SIGNALS2_NUM_ARGS)
         <BOOST_SIGNALS2_SIGNAL_TEMPLATE_INSTANTIATION> impl_class;
     public:
-      typedef detail::BOOST_SIGNALS2_WEAK_SIGNAL_CLASS_NAME(BOOST_SIGNALS2_NUM_ARGS)
-        <BOOST_SIGNALS2_SIGNAL_TEMPLATE_INSTANTIATION> weak_signal_type;
+      typedef typename impl_class::weak_signal_type weak_signal_type;
       friend class detail::BOOST_SIGNALS2_WEAK_SIGNAL_CLASS_NAME(BOOST_SIGNALS2_NUM_ARGS)
         <BOOST_SIGNALS2_SIGNAL_TEMPLATE_INSTANTIATION>;
 
@@ -746,12 +754,24 @@ namespace boost
         using std::swap;
         swap(_pimpl, other._pimpl);
       }
+      bool operator==(const BOOST_SIGNALS2_SIGNAL_CLASS_NAME(BOOST_SIGNALS2_NUM_ARGS) & other) const
+      {
+        return _pimpl.get() == other._pimpl.get();
+      }
     protected:
       virtual shared_ptr<void> lock_pimpl() const
       {
         return _pimpl;
       }
     private:
+      // explicit private copy constructor to avoid compiler trying to do implicit conversions to signal
+      explicit BOOST_SIGNALS2_SIGNAL_CLASS_NAME(BOOST_SIGNALS2_NUM_ARGS)(
+        const BOOST_SIGNALS2_SIGNAL_CLASS_NAME(BOOST_SIGNALS2_NUM_ARGS) & other) BOOST_NOEXCEPT
+      {
+          // noncopyable
+          BOOST_ASSERT(false);
+      }
+
       shared_ptr<impl_class>
         _pimpl;
     };
@@ -801,6 +821,16 @@ namespace boost
             <BOOST_SIGNALS2_SIGNAL_TEMPLATE_INSTANTIATION> >
             shared_pimpl(_weak_pimpl.lock());
           return (*shared_pimpl)(BOOST_SIGNALS2_SIGNATURE_ARG_NAMES(BOOST_SIGNALS2_NUM_ARGS));
+        }
+        bool contains(const BOOST_SIGNALS2_SIGNAL_CLASS_NAME(BOOST_SIGNALS2_NUM_ARGS)
+          <BOOST_SIGNALS2_SIGNAL_TEMPLATE_INSTANTIATION> &signal) const
+        {
+          return _weak_pimpl.lock().get() == signal._pimpl.get(); 
+        }
+        template <typename T>
+        bool contains(const T&) const
+        {
+          return false;
         }
       private:
         boost::weak_ptr<detail::BOOST_SIGNALS2_SIGNAL_IMPL_CLASS_NAME(BOOST_SIGNALS2_NUM_ARGS)
