Description: Use an absolute import of ExceptionNotSeen instead of the Python
  2 implicit relative import.
Issue ID: none
Changeset: none (fixed on upstream master, unreleased)
TODO: Drop if a release after 0.1.3 appears.

--- naiveBayesClassifier/classifier.py.orig	2014-05-12 16:53:33 UTC
+++ naiveBayesClassifier/classifier.py
@@ -2,7 +2,7 @@ from functools import reduce
 import operator
 from functools import reduce
 
-from ExceptionNotSeen import NotSeen
+from naiveBayesClassifier.ExceptionNotSeen import NotSeen
 
 class Classifier(object):
     """docstring for Classifier"""
