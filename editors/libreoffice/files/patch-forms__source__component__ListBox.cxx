--- ./forms/source/component/ListBox.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./forms/source/component/ListBox.cxx	2012-07-18 14:39:02.000000000 -0400
@@ -304,7 +304,7 @@
             break;
 
         case PROPERTY_ID_LISTSOURCETYPE :
-            DBG_ASSERT(_rValue.getValueType().equals(::getCppuType(reinterpret_cast<ListSourceType*>(NULL))),
+            DBG_ASSERT(_rValue.getValueType().equals(::getCppuType(static_cast<ListSourceType*>(0))),
                 "OComboBoxModel::setFastPropertyValue_NoBroadcast : invalid type !" );
             _rValue >>= m_eListSourceType;
             break;
@@ -343,7 +343,7 @@
             throw PropertyVetoException();
 
         case PROPERTY_ID_DEFAULT_SELECT_SEQ :
-            DBG_ASSERT(_rValue.getValueType().equals(::getCppuType(reinterpret_cast< Sequence<sal_Int16>*>(NULL))),
+            DBG_ASSERT(_rValue.getValueType().equals(::getCppuType(static_cast< Sequence<sal_Int16>*>(0))),
                 "OListBoxModel::setFastPropertyValue_NoBroadcast : invalid type !" );
             _rValue >>= m_aDefaultSelectSeq;
 
@@ -378,7 +378,7 @@
         switch (_nHandle)
         {
         case PROPERTY_ID_BOUNDCOLUMN :
-            bModified = tryPropertyValue(_rConvertedValue, _rOldValue, _rValue, m_aBoundColumn, ::getCppuType(reinterpret_cast<sal_Int16*>(NULL)));
+            bModified = tryPropertyValue(_rConvertedValue, _rOldValue, _rValue, m_aBoundColumn, ::getCppuType(static_cast<sal_Int16*>(0)));
             break;
 
         case PROPERTY_ID_LISTSOURCETYPE:
