--- Zend/zend_execute.c.orig	Tue Dec 28 15:03:55 2004
+++ Zend/zend_execute.c	Tue Dec 28 15:03:57 2004
@@ -1577,6 +1577,10 @@
 									EX(Ts)[EX(opline)->op1.u.var].EA.data.overloaded_element.elements_list = (zend_llist *) emalloc(sizeof(zend_llist));
 									zend_llist_init(EX(Ts)[EX(opline)->op1.u.var].EA.data.overloaded_element.elements_list, sizeof(zend_overloaded_element), NULL, 0);
 									EX(object).ptr->refcount++;
+									/* is-ref needed so that assign to this in call won't separate it */
+									if(EX(object).ptr->refcount > 1) {
+										EX(object).ptr->is_ref = 1;
+									}
 								}
 								zend_llist_add_element(EX(Ts)[EX(opline)->op1.u.var].EA.data.overloaded_element.elements_list, &overloaded_element);
 								EX(fbc) = (zend_function *) emalloc(sizeof(zend_function));
