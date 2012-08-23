--- ./forms/source/component/ComboBox.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./forms/source/component/ComboBox.cxx	2012-07-18 14:41:05.000000000 -0400
@@ -227,7 +227,7 @@
     switch (_nHandle)
     {
         case PROPERTY_ID_LISTSOURCETYPE :
-            DBG_ASSERT(_rValue.getValueType().equals(::getCppuType(reinterpret_cast<ListSourceType*>(NULL))),
+            DBG_ASSERT(_rValue.getValueType().equals(::getCppuType(static_cast<ListSourceType*>(0))),
                 "OComboBoxModel::setFastPropertyValue_NoBroadcast : invalid type !" );
             _rValue >>= m_eListSourceType;
             break;
