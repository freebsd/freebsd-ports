In file included from squirrel/sq_extensions.cc:6:
In file included from squirrel/../tpl/ptrhashtable_tpl.h:8:
In file included from squirrel/../tpl/hashtable_tpl.h:4:
In file included from squirrel/../tpl/slist_tpl.h:11:
In file included from /usr/include/c++/v1/iterator:417:
In file included from /usr/include/c++/v1/__functional_base:19:
/usr/include/c++/v1/utility:488:67: error: expected an identifier or template-id
      after '::'
                typename __make_tuple_indices<sizeof...(_Args1)>::type(),
                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^
squirrel/squirrel/sqobject.h:131:19: note: expanded from macro 'type'
#define type(obj) ((obj)._type)
                  ^

--- squirrel/sq_extensions.cc.orig	2018-07-28 07:52:43 UTC
+++ squirrel/sq_extensions.cc
@@ -1,9 +1,9 @@
 #include "sq_extensions.h"
 
+#include "../tpl/ptrhashtable_tpl.h"
 #include "squirrel/sqpcheader.h" // for declarations...
 #include "squirrel/sqvm.h"       // for Raise_Error_vl
 #include <stdarg.h>
-#include "../tpl/ptrhashtable_tpl.h"
 
 // store data associate to vm's here
 struct my_vm_info_t {
