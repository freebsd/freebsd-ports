--- lib/cmmodule/twoList.py.orig	2021-04-04 22:42:53 UTC
+++ lib/cmmodule/twoList.py
@@ -5,7 +5,7 @@ from operator import mul,add,sub
 def check_list(v1,v2):
 	'''check if the length of two list is same'''
 	if v1.size != v2.size:
-		raise ValueError,"the lenght of both arrays must be the same"
+		raise ValueError("the length of both arrays must be the same")
 	pass
 
 def Add(v1,v2):
@@ -50,4 +50,4 @@ def Min(v1,v2):
 def euclidean_distance(v1,v2):
 	'''return euclidean distance'''                                                                                 
 	check_list(v1,v2)
-	return (sum((v1.__sub__(v2))**2) / v1.size)**0.5
\ No newline at end of file
+	return (sum((v1.__sub__(v2))**2) / v1.size)**0.5
