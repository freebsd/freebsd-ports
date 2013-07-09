--- src/corelib/animation/qpropertyanimation.cpp.orig
+++ src/corelib/animation/qpropertyanimation.cpp
@@ -136,8 +136,11 @@ void QPropertyAnimationPrivate::updateProperty(const QVariant &newValue)
 
     if (newValue.userType() == propertyType) {
         //no conversion is needed, we directly call the QMetaObject::metacall
-        void *data = const_cast<void*>(newValue.constData());
-        QMetaObject::metacall(targetValue, QMetaObject::WriteProperty, propertyIndex, &data);
+        //check QMetaProperty::write for an explanation of these
+        int status = -1;
+        int flags = 0;
+        void *argv[] = { const_cast<void *>(newValue.constData()), const_cast<QVariant *>(&newValue), &status, &flags };
+        QMetaObject::metacall(targetValue, QMetaObject::WriteProperty, propertyIndex, argv);
     } else {
         targetValue->setProperty(propertyName.constData(), newValue);
     }
