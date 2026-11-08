Description: Use an absolute import of ExceptionNotSeen instead of the Python
  2 implicit relative import.
Issue ID: none
Changeset: none (fixed on upstream master, unreleased)
TODO: Drop if a release after 0.1.3 appears.

--- naiveBayesClassifier/trainedData.py.orig	2014-05-12 16:52:54 UTC
+++ naiveBayesClassifier/trainedData.py
@@ -1,4 +1,4 @@
-from ExceptionNotSeen import NotSeen
+from naiveBayesClassifier.ExceptionNotSeen import NotSeen
 
 class TrainedData(object):
     def __init__(self):
