diff -urN ../SWIG1.3a5/Lib/guile/typemaps.i ./Lib/guile/typemaps.i
--- ../SWIG1.3a5/Lib/guile/typemaps.i	Thu Sep 21 16:06:17 2000
+++ ./Lib/guile/typemaps.i	Tue Feb 27 06:17:46 2001
@@ -49,6 +49,150 @@
  SIMPLE_MAP(char *, GSWIG_scm2str, gh_str02scm, string);
  SIMPLE_MAP(const char *, GSWIG_scm2str, gh_str02scm, string);
 
+
+
+
+%define SIMPLE_MAP_STR(C_NAME, SCM_TO_C, C_TO_SCM, SCM_NAME)
+ %typemap (guile, in)          C_NAME { char* x; x=SCM_TO_C($source); $target = new string(x); scm_must_free(x);};
+ %typemap (guile, varin)       C_NAME { char* x; x=SCM_TO_C($source); $target = new string(x); scm_must_free(x);};
+ %typemap (guile, out)         C_NAME "$target = C_TO_SCM($source->c_str());";
+ %typemap (guile, varout)      C_NAME "$target = C_TO_SCM($source->c_str());";
+%enddef
+ 
+SIMPLE_MAP_STR(string , GSWIG_scm2str, gh_str02scm, string);
+SIMPLE_MAP_STR(string&, GSWIG_scm2str, gh_str02scm, string);
+SIMPLE_MAP_STR(const string , GSWIG_scm2str, gh_str02scm, string);
+SIMPLE_MAP_STR(const string&, GSWIG_scm2str, gh_str02scm, string);
+
+%typemap (guile, freearg) string, string&, const string, const string& "if ($target) delete $target;";
+
+
+
+
+%typemap (guile, in) vector<string> (vector<string> temp) { 
+
+  SCM v = gh_list_to_vector( $source );
+  unsigned long len = gh_vector_length (v);
+  unsigned long i=0;
+
+  $target = new vector<string>();
+
+  for( i=0; i<len; i++) 
+    {
+      //      cerr << " copying i:" << i << endl;
+      SCM scm_i = gh_ulong2scm(i);
+      SCM scm_str = gh_vector_ref( v, scm_i );
+      char* x = GSWIG_scm2str(scm_str); 
+      $target->push_back(string(x));
+      scm_must_free(x);
+    }
+
+};
+%typemap (guile, freearg) vector<string> "if ($target) delete $target;";
+
+
+%typemap (guile, out) vector<string> {
+
+  int i=0;
+  int count = $source->size();
+
+  cerr << " convert vector<> to scheme world" << endl;
+
+  if( !count ) 
+    {
+      $target = gh_list( SCM_UNDEFINED );
+    }
+  else
+    {
+      const string& s = (*$source)[count-1];
+      cerr << " convert vector<> to scheme world 2... s: " << s << endl;
+      $target = gh_list( gh_str02scm( s.c_str()),  SCM_UNDEFINED );
+      cerr << " convert vector<> to scheme world 3 " << endl;
+
+      for( i=count-2; i>=0; i-- )
+	{
+	  cerr << " convert vector<> to scheme world i:" << i << endl;
+	  const string& s = (*$source)[i];
+	  $target = gh_cons( gh_str02scm( s.c_str()), $target );
+	}
+    }
+};
+
+
+%typemap (guile, out) vector<foo*> {
+
+///////////////////////////////////////////////////////////////////////////////
+///////////////////////////////////////////////////////////////////////////////
+
+  swig_type_info *element_type_mangled_name = SWIGTYPE_p_foo;
+  typedef  foo*  element_type;
+
+///////////////////////////////////////////////////////////////////////////////
+///////////////////////////////////////////////////////////////////////////////
+
+  int i=0;
+  int count = $source->size();
+
+  if( !count ) 
+    {
+      $target = gh_list( SCM_UNDEFINED );
+    }
+  else 
+    {
+      element_type s = (*$source)[count-1];  
+      SCM s_scm = SWIG_Guile_MakePtr( s, element_type_mangled_name );
+      $target = gh_list( s_scm,  SCM_UNDEFINED );
+
+      for( i=count-2; i>=0; i-- )
+	{
+	  element_type s = (*$source)[i];
+	  s_scm = SWIG_Guile_MakePtr( s, element_type_mangled_name );
+	  $target = gh_cons( s_scm , $target );
+	}
+    }
+
+};
+
+
+
+
+
+%typemap (guile, out) vector<Witme_DirItem*> {
+
+///////////////////////////////////////////////////////////////////////////////
+///////////////////////////////////////////////////////////////////////////////
+
+  swig_type_info *element_type_mangled_name = SWIGTYPE_p_Witme_DirItem;
+  typedef  Witme_DirItem*  element_type;
+
+///////////////////////////////////////////////////////////////////////////////
+///////////////////////////////////////////////////////////////////////////////
+
+  int i=0;
+  int count = $source->size();
+
+  if( !count ) 
+    {
+      $target = gh_list( SCM_UNDEFINED );
+    }
+  else 
+    {
+      element_type s = (*$source)[count-1];  
+      SCM s_scm = SWIG_Guile_MakePtr( s, element_type_mangled_name );
+      $target = gh_list( s_scm,  SCM_UNDEFINED );
+
+      for( i=count-2; i>=0; i-- )
+	{
+	  element_type s = (*$source)[i];
+	  s_scm = SWIG_Guile_MakePtr( s, element_type_mangled_name );
+	  $target = gh_cons( s_scm , $target );
+	}
+    }
+
+};
+
+
+
 /* GSWIG_scm2str makes a malloc'ed copy of the string, so get rid of it after
    the function call. */
 
