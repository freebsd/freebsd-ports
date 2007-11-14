--- src/clients/lib/python/xmmsapi.pyx.orig	Sun May 20 08:55:40 2007
+++ src/clients/lib/python/xmmsapi.pyx	Wed Nov 14 15:16:18 2007
@@ -14,7 +14,7 @@
 	void Py_DECREF(object)
 
 cdef extern from "string.h":
-	int strcmp(signed char *s1, signed char *s2)
+	int strcmp(char *s1, char *s2)
 	char *strdup(char *str)
 
 cdef extern from "xmmsc/xmmsc_idnumbers.h":
@@ -129,17 +129,17 @@
 	void xmmsc_result_unref(xmmsc_result_t *res)
 	void xmmsc_result_notifier_set_full(xmmsc_result_t *res, xmmsc_result_notifier_t func, void *user_data, xmmsc_user_data_free_func_t free_func)
 	void xmmsc_result_wait(xmmsc_result_t *res)
-	signed int xmmsc_result_iserror(xmmsc_result_t *res)
-	signed char *xmmsc_result_get_error(xmmsc_result_t *res)
+	int xmmsc_result_iserror(xmmsc_result_t *res)
+	char *xmmsc_result_get_error(xmmsc_result_t *res)
 	xmmsc_result_value_type_t xmmsc_result_get_type(xmmsc_result_t *res)
 	xmmsc_result_type_t xmmsc_result_get_class(xmmsc_result_t *res)
 
-	signed int xmmsc_result_get_int(xmmsc_result_t *res, int *r)
-	signed int xmmsc_result_get_uint(xmmsc_result_t *res, unsigned int *r)
-	signed int xmmsc_result_get_string(xmmsc_result_t *res, signed char **r)
-	signed int xmmsc_result_get_bin(xmmsc_result_t *res, unsigned char **r, unsigned int *rlen)
-	signed int xmmsc_result_get_playlist_change(xmmsc_result_t *res, unsigned int *change, unsigned int *id, unsigned int *argument)
-	signed int xmmsc_result_get_collection (xmmsc_result_t *conn, xmmsc_coll_t **coll)
+	int xmmsc_result_get_int(xmmsc_result_t *res, int *r)
+	int xmmsc_result_get_uint(xmmsc_result_t *res, unsigned int *r)
+	int xmmsc_result_get_string(xmmsc_result_t *res, char **r)
+	int xmmsc_result_get_bin(xmmsc_result_t *res, unsigned char **r, unsigned int *rlen)
+	int xmmsc_result_get_playlist_change(xmmsc_result_t *res, unsigned int *change, unsigned int *id, unsigned int *argument)
+	int xmmsc_result_get_collection (xmmsc_result_t *conn, xmmsc_coll_t **coll)
 
 	ctypedef void(*xmmsc_dict_foreach_func)(void *key, xmmsc_result_value_type_t type, void *value, void *user_data)
 	ctypedef void(*xmmsc_propdict_foreach_func)(void *key, xmmsc_result_value_type_t type, void *value, char *source, void *user_data)
@@ -155,7 +155,7 @@
 
 	xmmsc_connection_t *xmmsc_init(char *clientname)
 	void xmmsc_disconnect_callback_set(xmmsc_connection_t *c, object(*callback)(object), object userdata)
-	signed int xmmsc_connect(xmmsc_connection_t *c, signed char *p)
+	int xmmsc_connect(xmmsc_connection_t *c, char *p)
 	void xmmsc_unref(xmmsc_connection_t *c)
 	xmmsc_result_t *xmmsc_quit(xmmsc_connection_t *conn)
 	xmmsc_result_t *xmmsc_plugin_list (xmmsc_connection_t *c, unsigned int type)
@@ -175,8 +175,8 @@
 	xmmsc_result_t *xmmsc_playlist_list_entries(xmmsc_connection_t *, char *playlist)
 	xmmsc_result_t *xmmsc_playlist_sort(xmmsc_connection_t *, char *playlist, char **properties)
 	xmmsc_result_t *xmmsc_playlist_set_next(xmmsc_connection_t *, int pos)
-	xmmsc_result_t *xmmsc_playlist_set_next_rel(xmmsc_connection_t *, signed int)
-	xmmsc_result_t *xmmsc_playlist_move_entry(xmmsc_connection_t *, char *playlist, unsigned int id, signed int movement)
+	xmmsc_result_t *xmmsc_playlist_set_next_rel(xmmsc_connection_t *, int)
+	xmmsc_result_t *xmmsc_playlist_move_entry(xmmsc_connection_t *, char *playlist, unsigned int id, int movement)
 	xmmsc_result_t *xmmsc_playlist_current_pos(xmmsc_connection_t *, char *playlist)
 	xmmsc_result_t *xmmsc_playlist_current_active(xmmsc_connection_t *)
 	xmmsc_result_t *xmmsc_playlist_insert_args(xmmsc_connection_t *, char *playlist, int pos, char *url, int numargs, char **args)
@@ -188,7 +188,7 @@
 	xmmsc_result_t *xmmsc_playlist_radd_encoded(xmmsc_connection_t *c, char *, char *path)
 
 	xmmsc_result_t *xmmsc_playlist_load(xmmsc_connection_t *, char *playlist)
-	xmmsc_result_t *xmmsc_playlist_move(xmmsc_connection_t *c, unsigned int id, signed int movement)
+	xmmsc_result_t *xmmsc_playlist_move(xmmsc_connection_t *c, unsigned int id, int movement)
 	xmmsc_result_t *xmmsc_playlist_create(xmmsc_connection_t *c, char *playlist)
 
 	xmmsc_result_t *xmmsc_broadcast_playlist_changed(xmmsc_connection_t *c)
@@ -357,7 +357,7 @@
 			i = i + 1
 		free(self.lst) 
 
-cdef foreach_source_hash(signed char *key, xmmsc_result_value_type_t typ, void *value, char *source, udata):
+cdef foreach_source_hash(char *key, xmmsc_result_value_type_t typ, void *value, char *source, udata):
 	if typ == XMMSC_RESULT_VALUE_TYPE_STRING:
 		v = to_unicode(<char *>value)
 	elif typ == XMMSC_RESULT_VALUE_TYPE_UINT32:
@@ -367,7 +367,7 @@
 
 	udata[(source,key)]=v
 
-cdef foreach_hash(signed char *key, xmmsc_result_value_type_t typ, void *value, udata):
+cdef foreach_hash(char *key, xmmsc_result_value_type_t typ, void *value, udata):
 	if typ == XMMSC_RESULT_VALUE_TYPE_STRING:
 		v = to_unicode(<char *>value)
 	elif typ == XMMSC_RESULT_VALUE_TYPE_UINT32:
@@ -874,7 +874,7 @@
 		Get data from the result structure as an int.
 		@rtype: int
 		"""
-		cdef signed int ret
+		cdef int ret
 		self._check()
 		if xmmsc_result_get_int(self.res, &ret):
 			return ret
@@ -898,7 +898,7 @@
 		Get data from the result structure as a string.
 		@rtype: string
 		"""
-		cdef signed char *ret
+		cdef char *ret
 
 		self._check()
 		if xmmsc_result_get_string(self.res, &ret):
