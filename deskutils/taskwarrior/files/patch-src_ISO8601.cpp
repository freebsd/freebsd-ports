--- src/ISO8601.cpp.orig	2015-10-21 20:50:42 UTC
+++ src/ISO8601.cpp
@@ -1535,34 +1535,28 @@ bool ISO8601d::sameYear (const ISO8601d&
 }
 
 ////////////////////////////////////////////////////////////////////////////////
-ISO8601d ISO8601d::operator+ (time_t delta)
-{
-  return ISO8601d (_date + delta);
-}
-
-////////////////////////////////////////////////////////////////////////////////
-ISO8601d ISO8601d::operator+ (const int delta)
+ISO8601d ISO8601d::operator+ (const time_t delta)
 {
   return ISO8601d (_date + delta);
 }
 
 ////////////////////////////////////////////////////////////////////////////////
-ISO8601d ISO8601d::operator- (const int delta)
+ISO8601d ISO8601d::operator- (const time_t delta)
 {
   return ISO8601d (_date - delta);
 }
 
 ////////////////////////////////////////////////////////////////////////////////
-ISO8601d& ISO8601d::operator+= (const int delta)
+ISO8601d& ISO8601d::operator+= (const time_t delta)
 {
-  _date += (time_t) delta;
+  _date += delta;
   return *this;
 }
 
 ////////////////////////////////////////////////////////////////////////////////
-ISO8601d& ISO8601d::operator-= (const int delta)
+ISO8601d& ISO8601d::operator-= (const time_t delta)
 {
-  _date -= (time_t) delta;
+  _date -= delta;
   return *this;
 }
 
@@ -1576,7 +1570,7 @@ time_t ISO8601d::operator- (const ISO860
 // Prefix decrement by one day.
 void ISO8601d::operator-- ()
 {
-  ISO8601d yesterday = startOfDay () - 1;
+  ISO8601d yesterday = startOfDay () - (time_t) 1;
   yesterday = ISO8601d (yesterday.month (),
                         yesterday.day (),
                         yesterday.year (),
@@ -1590,7 +1584,7 @@ void ISO8601d::operator-- ()
 // Postfix decrement by one day.
 void ISO8601d::operator-- (int)
 {
-  ISO8601d yesterday = startOfDay () - 1;
+  ISO8601d yesterday = startOfDay () - (time_t) 1;
   yesterday = ISO8601d (yesterday.month (),
                         yesterday.day (),
                         yesterday.year (),
@@ -1604,7 +1598,7 @@ void ISO8601d::operator-- (int)
 // Prefix increment by one day.
 void ISO8601d::operator++ ()
 {
-  ISO8601d tomorrow = (startOfDay () + 90001).startOfDay ();
+  ISO8601d tomorrow = (startOfDay () + (time_t) 90001).startOfDay ();
   tomorrow = ISO8601d (tomorrow.month (),
                        tomorrow.day (),
                        tomorrow.year (),
@@ -1618,7 +1612,7 @@ void ISO8601d::operator++ ()
 // Postfix increment by one day.
 void ISO8601d::operator++ (int)
 {
-  ISO8601d tomorrow = (startOfDay () + 90001).startOfDay ();
+  ISO8601d tomorrow = (startOfDay () + (time_t) 90001).startOfDay ();
   tomorrow = ISO8601d (tomorrow.month (),
                        tomorrow.day (),
                        tomorrow.year (),
