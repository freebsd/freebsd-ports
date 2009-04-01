--- object.c.orig	2009-03-03 17:41:46.000000000 +0200
+++ object.c	2009-03-03 17:58:19.000000000 +0200
@@ -20,8 +20,10 @@
 SOBJ scm_mkobjdef(int ndefs)
 {
   SOBJ new = scm_newcell(SOBJ_T_OBJDEF);
-  SCM_OBJDEF_AUX(new) =
-	scm_must_alloc(sizeof(SCM_ObjDefAux) + ((ndefs - 1) * sizeof(SCM_ObjDef)));
+  /*SCM_OBJDEF_AUX(new) =
+	scm_must_alloc(sizeof(SCM_ObjDefAux) + ((ndefs - 1) * sizeof(SCM_ObjDef)));*/
+  SCM_OBJDEF_AUX_SET(new,
+	scm_must_alloc(sizeof(SCM_ObjDefAux) + ((ndefs - 1) * sizeof(SCM_ObjDef))));
 
   SCM_OBJDEF_AUX(new)->ndefs = ndefs;
   return(new);
@@ -43,7 +45,8 @@
 {
   if (SCM_OBJDEF_AUX(x)) {
 	scm_free(SCM_OBJDEF_AUX(x));
-	SCM_OBJDEF_AUX(x) = NULL;
+	/*SCM_OBJDEF_AUX(x) = NULL;*/
+	SCM_OBJDEF_AUX_SET(x, NULL);
   }
 }
 
@@ -64,9 +67,12 @@
 {
   SOBJ new = scm_newcell(SOBJ_T_OBJECT);
   
-  SCM_OBJECT_DEF(new) = def;
+  /*SCM_OBJECT_DEF(new) = def;
   SCM_OBJECT_VAL(new) =
-	scm_must_alloc(sizeof(SCM_ObjVal) + ((nslots - 1) * sizeof(SOBJ)));
+	scm_must_alloc(sizeof(SCM_ObjVal) + ((nslots - 1) * sizeof(SOBJ)));*/
+  SCM_OBJECT_DEF_SET(new, def);
+  SCM_OBJECT_VAL_SET(new,
+	scm_must_alloc(sizeof(SCM_ObjVal) + ((nslots - 1) * sizeof(SOBJ))));
 
   SCM_OBJECT_VAL(new)->nslots = nslots;
   return(new);
@@ -237,7 +243,8 @@
   int nslots;
 
   if (SCM_OBJECT_VAL(obj) == NULL) {
-	SCM_OBJECT_VAL(obj) = scm_must_alloc(offsetof(SCM_ObjVal, slot[1]));
+	/*SCM_OBJECT_VAL(obj) = scm_must_alloc(offsetof(SCM_ObjVal, slot[1]));*/
+	SCM_OBJECT_VAL_SET(obj, scm_must_alloc(offsetof(SCM_ObjVal, slot[1])));
 	SCM_OBJECT_VAL(obj)->nslots = 1;
 	return(0);
   }
@@ -246,7 +253,9 @@
   memcpy(ov, SCM_OBJECT_VAL(obj), offsetof(SCM_ObjVal, slot[nslots]));
   ov->nslots++;
   ov->slot[nslots] = NULL;
-  scm_free(SCM_OBJECT_VAL(obj));   SCM_OBJECT_VAL(obj) = ov;
+  scm_free(SCM_OBJECT_VAL(obj));
+  /*SCM_OBJECT_VAL(obj) = ov;*/
+  SCM_OBJECT_VAL_SET(obj, ov);
   return(nslots);
 }
 
@@ -284,11 +293,13 @@
   int nslots, size;
   SOBJ new = scm_newcell(SOBJ_T_OBJECT);
   
-  SCM_OBJECT_DEF(new) = SCM_OBJECT_DEF(obj);
+  /*SCM_OBJECT_DEF(new) = SCM_OBJECT_DEF(obj);*/
+  SCM_OBJECT_DEF_SET(new, SCM_OBJECT_DEF(obj));
   
   nslots = SCM_OBJECT_VAL(obj)->nslots;
   size   = offsetof(SCM_ObjVal, slot[nslots]);
-  SCM_OBJECT_VAL(new) = scm_must_alloc(size);
+  /*SCM_OBJECT_VAL(new) = scm_must_alloc(size);*/
+  SCM_OBJECT_VAL_SET(new, scm_must_alloc(size));
   memcpy(SCM_OBJECT_VAL(new), SCM_OBJECT_VAL(obj), size);
   return(new);
 }
@@ -377,7 +388,8 @@
   /* make a new objdef with space for 2 more defs */
   newdef = scm_newcell(SOBJ_T_OBJDEF);
   d = objdef_append_fields(SCM_OBJDEF_AUX(olddef), 2);
-  SCM_OBJDEF_AUX(newdef) = d;
+  /*SCM_OBJDEF_AUX(newdef) = d;*/
+  SCM_OBJDEF_AUX_SET(newdef, d);
 
   /* prepare atom for the set! name */
   i = strlen(SCM_ATOM_NAME(name));
@@ -414,7 +426,8 @@
   if ((olddef = SCM_OBJECT_DEF(obj)) == NULL) SCM_ERR("bad objdef for object",obj);
   newdef = scm_newcell(SOBJ_T_OBJDEF);
   d = objdef_append_fields(SCM_OBJDEF_AUX(olddef), 1);
-  SCM_OBJDEF_AUX(newdef) = d;
+  /*SCM_OBJDEF_AUX_SET(newdef) = d;*/
+  SCM_OBJDEF_AUX_SET(newdef, d);
 
   slotnr = object_new_slot(obj); /* alloc new slot and get index */
 
@@ -424,7 +437,8 @@
   d->def[i].type = type;
   d->def[i].index= slotnr;
 
-  SCM_OBJECT_DEF(obj) = newdef;	/* adjust object def pointer */
+  /*SCM_OBJECT_DEF(obj) = newdef;*/
+  SCM_OBJECT_DEF_SET(obj, newdef);	/* adjust object def pointer */
   SCM_OBJECT_SLOT(obj,slotnr) = value;
   return(obj);
 }
