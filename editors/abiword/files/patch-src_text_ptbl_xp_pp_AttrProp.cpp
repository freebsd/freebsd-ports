--- src/text/ptbl/xp/pp_AttrProp.cpp.orig	Sat Jul 12 02:57:05 2003
+++ src/text/ptbl/xp/pp_AttrProp.cpp	Sat Jul 12 03:04:49 2003
@@ -82,7 +82,7 @@
 				void* tmp = const_cast<void*> (entry->first());
 				FREEP(tmp);
 				if (entry->second())
-					delete static_cast<const PP_PropertyType *>(entry->second());
+					delete (const PP_PropertyType*)entry->second();
 				delete entry;
 			}
 		}
@@ -336,7 +336,7 @@
 
 		FREEP(tmp);
 		if (p->second())
-			delete static_cast<const PP_PropertyType *>(p->second());
+			delete (const PP_PropertyType *)p->second();
 		delete p;
 
 		if(bRemove)
@@ -406,7 +406,7 @@
 	if ( (i == ndx) && c.is_valid())
  		{
 		  szName = static_cast<const XML_Char*>(c.key().c_str());
-		  szValue = static_cast<const XML_Char*>(static_cast<const UT_Pair*>(val)->first());
+		  szValue = (const XML_Char*)(static_cast<const UT_Pair*>(val)->first());
 		  return true;
  		}
 	return false;
@@ -421,7 +421,7 @@
 	if (!pEntry)
 		return false;
 
-	szValue = static_cast<const XML_Char *>(static_cast<const UT_Pair*>(pEntry)->first());
+	szValue = (const XML_Char *)(static_cast<const UT_Pair*>(pEntry)->first());
 
 	return true;
 }
@@ -440,12 +440,12 @@
 		m_pProperties->set(szName, new UT_Pair
 				   (pEntry->first(),
 				    PP_PropertyType::createPropertyType(Type,
-									static_cast<const XML_Char *>(pEntry->first()))));
+									(const XML_Char *)(pEntry->first()))));
 		delete pEntry;
 		pEntry = static_cast<const UT_Pair *>(m_pProperties->pick(szName));
 	}
 
-	return static_cast<const PP_PropertyType *>(pEntry->second());
+	return (const PP_PropertyType *)(pEntry->second());
 }
 bool PP_AttrProp::getAttribute(const XML_Char * szName, const XML_Char *& szValue) const
 {
@@ -750,14 +750,14 @@
 		{
 			const UT_Pair* p = static_cast<const UT_Pair*>(pEntry);
 
-			if(*(static_cast<const XML_Char *>(p->first())) == 0)
+			if(*((const XML_Char *)(p->first())) == 0)
 			{
 
 				void* tmp = const_cast<void*> (p->first());
 				UT_ASSERT(!m_bIsReadOnly);
 				FREEP(tmp);
 				if (p->second())
-					delete static_cast<const PP_PropertyType *>(p->second());
+					delete (const PP_PropertyType *)(p->second());
 				delete p;
 
 				m_pProperties->remove(_hc1.key(),pEntry);
@@ -985,7 +985,7 @@
 	while (val != NULL)
 	{
 		s1 = static_cast<const XML_Char *>(c2.key().c_str());
-		s2 = static_cast<const XML_Char *>(static_cast<const UT_Pair*>(val)->first());
+		s2 = (const XML_Char *)(static_cast<const UT_Pair*>(val)->first());
 
 		m_checkSum += UT_XML_strlen(s1);
 		m_checkSum += UT_XML_strlen(s2);
