--- main.py.orig	Tue Apr  8 12:09:31 2003
+++ main.py	Tue Apr  8 12:09:55 2003
@@ -1036,6 +1036,7 @@
 
     # Do some error handling
     def HandleError(self, error, source, extra = None):
+        """ Perform error handling for given errors. """
         if (str(error) != ""):
             if (type(error) == TupleType) or (type(error) == InstanceType):
                 errornumber = atoi(str(error[0]))
@@ -1044,8 +1045,13 @@
                 errornumber = atoi(str(error)[0:3])
                 errormessage = strip(str(error)[4:])
         else:
-            errornumber = 999
-            errormessage = "emirror internal: unknown error"
+            # If no error is given, use the traceback
+            if (str(sys.exc_info()[0].__name__) == "EOFError"):
+                errornumber = 902
+                errormessage = "EOFError"
+            else:
+                errornumber = 999
+                errormessage = format_exception(sys.exc_info()[0], sys.exc_info()[1], sys.exc_info()[2])
         self.log4py.error("[ %s ] Error: #%d - %s" % (str(self.title), errornumber, errormessage)) 
         found = FALSE
         for i in range(len(errormsgs)):
@@ -1098,7 +1104,7 @@
                 self.log4py.error("Please report this error to Martin.Preishuber@eclipt.at")
                 self.log4py.error("or check error.py and adapt it (it's not really difficult ;-))")
 
-            self.AppendLog([LMError, str(errornumber) + "-" + errormessage])
+            self.AppendLog([LMError, str(errornumber) + "-" + str(errormessage)])
             self.WriteLog()
             exit(1)
 
