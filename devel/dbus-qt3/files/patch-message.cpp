--- message.cpp.orig	2006-07-18 15:42:53.000000000 +0400
+++ message.cpp	2008-05-30 00:09:02.000000000 +0400
@@ -359,6 +359,7 @@
 Message Message::operator=( const Message& other )
 {
   //FIXME: ref the other.d->msg instead of copying it?
+  return (Message &)(d->msg);
 }
 /**
  * Destructs message.
@@ -508,42 +509,49 @@
   const dbus_bool_t right_size_bool = b;
   dbus_message_append_args( d->msg, DBUS_TYPE_BOOLEAN, &right_size_bool,
                             DBUS_TYPE_INVALID );
+  return (Message &)(d->msg);
 }
 
 Message& Message::operator<<( Q_INT8 byte )
 {
   dbus_message_append_args( d->msg, DBUS_TYPE_BYTE, &byte,
                             DBUS_TYPE_INVALID );
+  return (Message &)(d->msg);
 }
 
 Message& Message::operator<<( Q_INT32 num )
 {
   dbus_message_append_args( d->msg, DBUS_TYPE_INT32, &num,
                             DBUS_TYPE_INVALID );
+  return (Message &)(d->msg);
 }
 
 Message& Message::operator<<( Q_UINT32 num )
 {
   dbus_message_append_args( d->msg, DBUS_TYPE_UINT32, &num,
                             DBUS_TYPE_INVALID );
+  return (Message &)(d->msg);
 }
 
 Message& Message::operator<<( Q_INT64 num )
 {
   dbus_message_append_args( d->msg, DBUS_TYPE_INT64, &num,
                             DBUS_TYPE_INVALID );
+  return (Message &)(d->msg);
 }
 
 Message& Message::operator<<( Q_UINT64 num )
 {
   dbus_message_append_args( d->msg, DBUS_TYPE_UINT64, &num,
                             DBUS_TYPE_INVALID );
+  return (Message &)(d->msg);
 }
 
 Message& Message::operator<<( double num )
 {
   dbus_message_append_args( d->msg, DBUS_TYPE_DOUBLE, &num,
                             DBUS_TYPE_INVALID );
+  return (Message &)(d->msg);
 }
 
 Message& Message::operator<<( const QString& str )
@@ -551,11 +559,13 @@
   const char *u = str.utf8();
   dbus_message_append_args( d->msg, DBUS_TYPE_STRING, &u,
                             DBUS_TYPE_INVALID );
+  return (Message &)(d->msg);
 }
 
 Message& Message::operator<<( const QVariant& custom )
 {
   //FIXME: imeplement
+  return (Message &)(d->msg);
 }
 
 }
