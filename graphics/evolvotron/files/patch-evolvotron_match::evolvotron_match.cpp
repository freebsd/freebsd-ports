--- evolvotron_match/evolvotron_match.cpp.orig	Mon Jul 12 02:05:44 2004
+++ evolvotron_match/evolvotron_match.cpp	Thu Dec  9 20:07:52 2004
@@ -187,13 +187,15 @@
 	{
 	  do 
 	    {
-	      new_imagefn=std::auto_ptr<const MutatableImage>(new MutatableImage(mutation_parameters,true,true,false));
+	      std::auto_ptr<const MutatableImage> tmp(new MutatableImage(mutation_parameters,true,true,false));
+	      new_imagefn=tmp;
 	    }
 	  while (new_imagefn->is_constant());
 	}
       else
 	{
-	  new_imagefn=std::auto_ptr<const MutatableImage>(best_imagefn->mutated(mutation_parameters));
+	  std::auto_ptr<const MutatableImage> tmp(best_imagefn->mutated(mutation_parameters));
+	  new_imagefn=tmp;
 	}
 
       
