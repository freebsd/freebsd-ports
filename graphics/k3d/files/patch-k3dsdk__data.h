--- k3dsdk/data.h.orig	2010-07-03 11:27:46.000000000 +0900
+++ k3dsdk/data.h	2012-06-20 16:00:25.000000000 +0900
@@ -580,7 +580,7 @@
 
 		try
 		{
-			set_value(boost::lexical_cast<value_t>(*new_value), Hint);
+			this->set_value(boost::lexical_cast<value_t>(*new_value), Hint);
 			return true;
 		}
 		catch(...)
@@ -865,7 +865,7 @@
 
 		try
 		{
-			set_value(boost::lexical_cast<value_t>(*new_value), Hint);
+			this->set_value(boost::lexical_cast<value_t>(*new_value), Hint);
 			return true;
 		}
 		catch(...)
@@ -1011,7 +1011,7 @@
 
 		try
 		{
-			set_value(boost::lexical_cast<value_t>(*new_value), Hint);
+			this->set_value(boost::lexical_cast<value_t>(*new_value), Hint);
 			return true;
 		}
 		catch(...)
