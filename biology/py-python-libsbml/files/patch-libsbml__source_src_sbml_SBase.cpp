--- libsbml_source/src/sbml/SBase.cpp.orig	2023-06-26 04:05:56 UTC
+++ libsbml_source/src/sbml/SBase.cpp
@@ -93,7 +93,7 @@ struct DeletePluginEntity
 struct ClonePluginEntity 
 {
   SBasePlugin* operator() (const SBasePlugin* sb) {
-    if (!sb) return NULL;
+    if (!sb) return 0;
     return sb->clone();
   }
 };
@@ -103,7 +103,7 @@ struct ClonePluginEntity 
 SBase*
 SBase::getElementBySId(const std::string& id)
 {
-  if (id.empty()) return NULL;
+  if (id.empty()) return 0;
   return getElementFromPluginsBySId(id);
 }
 
@@ -118,7 +118,7 @@ SBase::getElementBySId(const std::string& id) const
 SBase*
 SBase::getElementByMetaId(const std::string& metaid)
 {
-  if (metaid.empty()) return NULL;
+  if (metaid.empty()) return 0;
   return getElementFromPluginsByMetaId(metaid);
 }
 
@@ -188,9 +188,9 @@ SBase::getElementFromPluginsBySId(const std::string& i
   for (size_t i=0; i < mPlugins.size(); i++)
   {
     SBase* subObj = mPlugins[i]->getElementBySId(id);
-    if (subObj != NULL) return subObj;
+    if (subObj != 0) return subObj;
   }
-  return NULL;
+  return 0;
 }
 /** @endcond */
 
@@ -202,9 +202,9 @@ SBase::getElementFromPluginsByMetaId(const std::string
   for (size_t i=0; i < mPlugins.size(); i++)
   {
     SBase* subObj = mPlugins[i]->getElementByMetaId(metaid);
-    if (subObj != NULL) return subObj;
+    if (subObj != 0) return subObj;
   }
-  return NULL;
+  return 0;
 }
 /** @endcond */
 
@@ -276,7 +276,7 @@ SBase::transformIdentifiers(IdentifierTransformer* idT
   }
 
   // call transformer
-  if (idTransformer != NULL)
+  if (idTransformer != 0)
   {
     ret = idTransformer->transform(this);
     if (ret != LIBSBML_OPERATION_SUCCESS)
@@ -296,7 +296,7 @@ SBase::getAllElementsFromPlugins(ElementFilter *filter
   for (size_t i=0; i < mPlugins.size(); i++)
   {
     List* sublist = mPlugins[i]->getAllElements(filter);
-    if (sublist != NULL)
+    if (sublist != 0)
     {
       if (sublist->getSize() > 0)
         ret->transferFrom(sublist);
@@ -316,17 +316,17 @@ SBase::SBase (unsigned int level, unsigned int version
    mId   ( "" )
  , mName ( "" )
  , mMetaId ( "" )
- , mNotes     ( NULL )
- , mAnnotation( NULL )
- , mSBML      ( NULL )
- , mSBMLNamespaces (NULL)
- , mUserData(NULL)
+ , mNotes     ( 0 )
+ , mAnnotation( 0 )
+ , mSBML      ( 0 )
+ , mSBMLNamespaces (0)
+ , mUserData(0)
  , mSBOTerm   ( -1 )
  , mLine      ( 0 )
  , mColumn    ( 0 )
- , mParentSBMLObject (NULL)
- , mCVTerms   ( NULL )
- , mHistory   ( NULL )
+ , mParentSBMLObject (0)
+ , mCVTerms   ( 0 )
+ , mHistory   ( 0 )
  , mHasBeenDeleted (false)
  , mEmptyString ("")
  , mURI("")
@@ -362,17 +362,17 @@ SBase::SBase (const SBMLNamespaces *sbmlns) :
    mId   ( "" )
  , mName ( "" )
  , mMetaId ( "" )
- , mNotes     ( NULL )
- , mAnnotation( NULL )
- , mSBML      ( NULL )
- , mSBMLNamespaces (NULL)
- , mUserData(NULL)
+ , mNotes     ( 0 )
+ , mAnnotation( 0 )
+ , mSBML      ( 0 )
+ , mSBMLNamespaces (0)
+ , mUserData(0)
  , mSBOTerm   ( -1 )
  , mLine      ( 0 )
  , mColumn    ( 0 )
- , mParentSBMLObject (NULL)
- , mCVTerms   ( NULL )
- , mHistory   ( NULL )
+ , mParentSBMLObject (0)
+ , mCVTerms   ( 0 )
+ , mHistory   ( 0 )
  , mHasBeenDeleted (false)
  , mEmptyString ("")
  , mURI("")
@@ -416,17 +416,17 @@ SBase::SBase(const SBase& orig)
   : mId (orig.mId)
   , mName (orig.mName)
   , mMetaId (orig.mMetaId)
-  , mNotes (NULL)
-  , mAnnotation (NULL)
-  , mSBML (NULL)
-  , mSBMLNamespaces(NULL)
+  , mNotes (0)
+  , mAnnotation (0)
+  , mSBML (0)
+  , mSBMLNamespaces(0)
   , mUserData(orig.mUserData)
   , mSBOTerm(orig.mSBOTerm)
   , mLine(orig.mLine)
   , mColumn(orig.mColumn)
-  , mParentSBMLObject(NULL)
-  , mCVTerms(NULL)
-  , mHistory(NULL)
+  , mParentSBMLObject(0)
+  , mCVTerms(0)
+  , mHistory(0)
   , mHasBeenDeleted(false)
   , mEmptyString()
   , mPlugins(orig.mPlugins.size())
@@ -439,17 +439,17 @@ SBase::SBase(const SBase& orig)
   , mElementsOfUnknownPkg (orig.mElementsOfUnknownPkg)
   , mElementsOfUnknownDisabledPkg (orig.mElementsOfUnknownDisabledPkg)
 {
-  if(orig.mNotes != NULL)
+  if(orig.mNotes != 0)
     this->mNotes = new XMLNode(*const_cast<SBase&>(orig).getNotes());
 
-  if(orig.mAnnotation != NULL)
+  if(orig.mAnnotation != 0)
     this->mAnnotation = new XMLNode(*const_cast<SBase&>(orig).mAnnotation);
 
-  if(orig.getSBMLNamespaces() != NULL)
+  if(orig.getSBMLNamespaces() != 0)
     this->mSBMLNamespaces =
     new SBMLNamespaces(*const_cast<SBase&>(orig).getSBMLNamespaces());
 
-  if(orig.mCVTerms != NULL)
+  if(orig.mCVTerms != 0)
   {
     this->mCVTerms  = new List();
     unsigned int iMax = orig.mCVTerms->getSize();
@@ -460,7 +460,7 @@ SBase::SBase(const SBase& orig)
     }
   }
 
-  if (orig.mHistory != NULL)
+  if (orig.mHistory != 0)
   {
     this->mHistory = orig.mHistory->clone();
   }
@@ -481,10 +481,10 @@ SBase::SBase(const SBase& orig)
  */
 SBase::~SBase ()
 {
-  if (mNotes != NULL)       delete mNotes;
-  if (mAnnotation != NULL)  delete mAnnotation;
-  if (mSBMLNamespaces != NULL)  delete mSBMLNamespaces;
-  if (mCVTerms != NULL)
+  if (mNotes != 0)       delete mNotes;
+  if (mAnnotation != 0)  delete mAnnotation;
+  if (mSBMLNamespaces != 0)  delete mSBMLNamespaces;
+  if (mCVTerms != 0)
   {
     unsigned int size = mCVTerms->getSize();
     while (size > 0) 
@@ -494,7 +494,7 @@ SBase::~SBase ()
     }
     delete mCVTerms;
   }
-  if (mHistory != NULL) delete mHistory;
+  if (mHistory != 0) delete mHistory;
   mHasBeenDeleted = true;
 
   for_each( mPlugins.begin(), mPlugins.end(), DeletePluginEntity() );
@@ -514,17 +514,17 @@ SBase& SBase::operator=(const SBase& rhs)
 
     delete this->mNotes;
 
-    if(rhs.mNotes != NULL)
+    if(rhs.mNotes != 0)
       this->mNotes = new XMLNode(*const_cast<SBase&>(rhs).getNotes());
     else
-      this->mNotes = NULL;
+      this->mNotes = 0;
 
     delete this->mAnnotation;
 
-    if(rhs.mAnnotation != NULL)
+    if(rhs.mAnnotation != 0)
       this->mAnnotation = new XMLNode(*const_cast<SBase&>(rhs).mAnnotation);
     else
-      this->mAnnotation = NULL;
+      this->mAnnotation = 0;
 
     this->mSBML       = rhs.mSBML;
     this->mSBOTerm    = rhs.mSBOTerm;
@@ -539,21 +539,21 @@ SBase& SBase::operator=(const SBase& rhs)
 
     delete this->mSBMLNamespaces;
 
-    if(rhs.mSBMLNamespaces != NULL)
+    if(rhs.mSBMLNamespaces != 0)
       this->mSBMLNamespaces =
       new SBMLNamespaces(*const_cast<SBase&>(rhs).mSBMLNamespaces);
     else
-      this->mSBMLNamespaces = NULL;
+      this->mSBMLNamespaces = 0;
 
 
-    if(this->mCVTerms != NULL)
+    if(this->mCVTerms != 0)
     {
       unsigned int size = this->mCVTerms->getSize();
       while (size--) delete static_cast<CVTerm*>( this->mCVTerms->remove(0) );
       delete this->mCVTerms;
     }
 
-    if(rhs.mCVTerms != NULL)
+    if(rhs.mCVTerms != 0)
     {
       this->mCVTerms  = new List();
       unsigned int iMax = rhs.mCVTerms->getSize();
@@ -565,17 +565,17 @@ SBase& SBase::operator=(const SBase& rhs)
     }
     else
     {
-      this->mCVTerms = NULL;
+      this->mCVTerms = 0;
     }
 
     delete this->mHistory;
-    if (rhs.mHistory != NULL)
+    if (rhs.mHistory != 0)
     {
       this->mHistory = rhs.mHistory->clone();
     }
     else
     {
-      this->mHistory = NULL;
+      this->mHistory = 0;
     }
 
     this->mHasBeenDeleted = rhs.mHasBeenDeleted;
@@ -630,7 +630,7 @@ SBase::loadPlugins(SBMLNamespaces *sbmlns)
         const std::string &prefix = xmlns->getPrefix(i);
         const SBasePluginCreatorBase* sbPluginCreator = sbmlext->getSBasePluginCreator(extPoint);
 
-        if (sbPluginCreator == NULL)
+        if (sbPluginCreator == 0)
         {
           sbPluginCreator = sbmlext->getSBasePluginCreator(genericPoint);
         }
@@ -824,12 +824,12 @@ SBase::getURI() const
   const string &package = getPackageName();
   const SBMLDocument* doc = getSBMLDocument();
 
-  if (doc == NULL)
+  if (doc == 0)
     return getElementNamespace();
 
   SBMLNamespaces* sbmlns = doc->getSBMLNamespaces();
 
-  if (sbmlns == NULL)
+  if (sbmlns == 0)
     return getElementNamespace();
 
   if (package == "" || package == "core")
@@ -879,11 +879,11 @@ int
 SBase::setUserData(void *userData)
 {
   this->mUserData = userData;
-  if (userData == NULL && mUserData == NULL)
+  if (userData == 0 && mUserData == 0)
   {
     return LIBSBML_OPERATION_SUCCESS;
   }
-  else if (mUserData != NULL)
+  else if (mUserData != 0)
   {
     return LIBSBML_OPERATION_SUCCESS;
   }
@@ -896,7 +896,7 @@ SBase::setUserData(void *userData)
 bool
 SBase::isSetUserData() const
 {
-  if (mUserData != NULL)
+  if (mUserData != 0)
   {
     return true;
   }
@@ -909,8 +909,8 @@ SBase::isSetUserData() const
 int
 SBase::unsetUserData()
 {
-  this->mUserData = NULL;
-  if (mUserData == NULL)
+  this->mUserData = 0;
+  if (mUserData == 0)
   {
     return LIBSBML_OPERATION_SUCCESS;
   }
@@ -926,11 +926,11 @@ SBase::unsetUserData()
 XMLNamespaces*
 SBase::getNamespaces() const
 {
-  if (mSBML != NULL)
+  if (mSBML != 0)
     return mSBML->getSBMLNamespaces()->getNamespaces();
-  if (mSBMLNamespaces != NULL)
+  if (mSBMLNamespaces != 0)
     return mSBMLNamespaces->getNamespaces();
-  return NULL;
+  return 0;
 }
 
 
@@ -942,9 +942,9 @@ SBase::getSBMLDocument () const
 {
   // if the doc object has been deleted the pointer is
   // still valid but points to nothing
-  if (mSBML != NULL && mSBML->getHasBeenDeleted())
+  if (mSBML != 0 && mSBML->getHasBeenDeleted())
   {
-    return NULL;
+    return 0;
   }
 
   return mSBML;
@@ -958,9 +958,9 @@ SBase::getSBMLDocument ()
 {
   // if the doc object has been deleted the pointer is
   // still valid but points to nothing
-  if (mSBML != NULL && mSBML->getHasBeenDeleted())
+  if (mSBML != 0 && mSBML->getHasBeenDeleted())
   {
-    return NULL;
+    return 0;
   }
   return mSBML;
 }
@@ -969,9 +969,9 @@ SBase::getParentSBMLObject ()
 {
   // if the parent object has been deleted the pointer is
   // still valid but points to nothing
-  if (mParentSBMLObject != NULL && mParentSBMLObject->getHasBeenDeleted())
+  if (mParentSBMLObject != 0 && mParentSBMLObject->getHasBeenDeleted())
   {
-    return NULL;
+    return 0;
   }
 
   return mParentSBMLObject;
@@ -982,9 +982,9 @@ SBase::getParentSBMLObject () const
 {
   // if the parent object has been deleted the pointer is
   // still valid but points to nothing
-  if (mParentSBMLObject != NULL && mParentSBMLObject->getHasBeenDeleted())
+  if (mParentSBMLObject != 0 && mParentSBMLObject->getHasBeenDeleted())
   {
-    return NULL;
+    return 0;
   }
 
   return mParentSBMLObject;
@@ -1068,26 +1068,26 @@ SBase::getModelHistory()
 Date*
 SBase::getCreatedDate() const
 {
-  return (mHistory != NULL)  ? mHistory->getCreatedDate() : NULL;
+  return (mHistory != 0)  ? mHistory->getCreatedDate() : 0;
 }
 
 Date*
 SBase::getCreatedDate()
 {
-  return (mHistory != NULL) ? mHistory->getCreatedDate() : NULL;
+  return (mHistory != 0) ? mHistory->getCreatedDate() : 0;
 }
 
 
 Date*
 SBase::getModifiedDate(unsigned int n)
 {
-  return (mHistory != NULL) ? mHistory->getModifiedDate(n) : NULL;
+  return (mHistory != 0) ? mHistory->getModifiedDate(n) : 0;
 }
 
 unsigned int
 SBase::getNumModifiedDates()
 {
-  return (mHistory != NULL) ? mHistory->getNumModifiedDates() : NULL;
+  return (mHistory != 0) ? mHistory->getNumModifiedDates() : 0;
 }
 
 
@@ -1142,7 +1142,7 @@ SBase::isSetIdAttribute () const
 bool
 SBase::isSetNotes () const
 {
-  return (mNotes != NULL);
+  return (mNotes != 0);
 }
 
 
@@ -1154,7 +1154,7 @@ bool
 SBase::isSetAnnotation () const
 {
   const_cast <SBase *> (this)->syncAnnotation();
-  return (mAnnotation != NULL);
+  return (mAnnotation != 0);
 }
 
 
@@ -1172,14 +1172,14 @@ SBase::isSetSBOTerm () const
 bool
 SBase::isSetModelHistory() const
 {
-  return (mHistory != NULL);
+  return (mHistory != 0);
 }
 
 
 bool
 SBase::isSetCreatedDate() const
 {
-  return (mHistory == NULL) ? false : mHistory->isSetCreatedDate();
+  return (mHistory == 0) ? false : mHistory->isSetCreatedDate();
 }
 
 
@@ -1187,7 +1187,7 @@ SBase::isSetCreatedDate() const
 bool
 SBase::isSetModifiedDate() const
 {
-  return (mHistory == NULL) ? false : mHistory->isSetModifiedDate();
+  return (mHistory == 0) ? false : mHistory->isSetModifiedDate();
 }
 
 
@@ -1304,10 +1304,10 @@ SBase::setAnnotation (const XMLNode* annotation)
   //
   //
 
-  if (annotation == NULL)
+  if (annotation == 0)
   {
     delete mAnnotation;
-    mAnnotation = NULL;
+    mAnnotation = 0;
   }
 
 
@@ -1321,7 +1321,7 @@ SBase::setAnnotation (const XMLNode* annotation)
       || RDFAnnotationParser::hasHistoryRDFAnnotation(annotation) == true)
       && isSetMetaId() == false)
     {
-      mAnnotation = NULL;
+      mAnnotation = 0;
       return LIBSBML_MISSING_METAID;
     }
     else
@@ -1363,24 +1363,24 @@ SBase::setAnnotation (const XMLNode* annotation)
   // delete existing mCVTerms
   //
   // existing CVTerms (if any) needs to be deleted at any rate, otherwise
-  // unsetAnnotation() ( setAnnotation(NULL) ) doesn't work as expected.
+  // unsetAnnotation() ( setAnnotation(0) ) doesn't work as expected.
   // (These functions must clear all elements in an annotation.)
   //
 
   /* in L3 might be a model history */
-  if (mHistory != NULL)
+  if (mHistory != 0)
   {
     delete mHistory;
-    mHistory = NULL;
+    mHistory = 0;
   }
 
-  if (mCVTerms != NULL)
+  if (mCVTerms != 0)
   {
     // delete existing mCVTerms (if any)
     unsigned int size = mCVTerms->getSize();
     while (size--) delete static_cast<CVTerm*>( mCVTerms->remove(0) );
     delete mCVTerms;
-    mCVTerms = NULL;
+    mCVTerms = 0;
   }
 
   unsigned int level = getLevel();
@@ -1392,7 +1392,7 @@ SBase::setAnnotation (const XMLNode* annotation)
     validNestedTerms = false;
   }
 
-  if(mAnnotation != NULL
+  if(mAnnotation != 0
         && RDFAnnotationParser::hasCVTermRDFAnnotation(mAnnotation))
   {
     // parse mAnnotation (if any) and set mCVTerms
@@ -1416,7 +1416,7 @@ SBase::setAnnotation (const XMLNode* annotation)
     mCVTermsChanged = true;
   }
 
-  if(getLevel() > 2 && mAnnotation != NULL
+  if(getLevel() > 2 && mAnnotation != 0
      && RDFAnnotationParser::hasHistoryRDFAnnotation(mAnnotation))
   {
     // parse mAnnotation (if any) and set mHistory
@@ -1457,7 +1457,7 @@ SBase::setAnnotation (const std::string& annotation)
   XMLNode* annt_xmln;
   
   // you might not have a document !!
-  if (getSBMLDocument() != NULL)
+  if (getSBMLDocument() != 0)
   {
     const XMLNamespaces* xmlns = getSBMLDocument()->getNamespaces();
     annt_xmln = XMLNode::convertStringToXMLNode(annotation,xmlns);
@@ -1467,7 +1467,7 @@ SBase::setAnnotation (const std::string& annotation)
     annt_xmln = XMLNode::convertStringToXMLNode(annotation);
   }
   
-  if(annt_xmln != NULL)
+  if(annt_xmln != 0)
   {
     success = setAnnotation(annt_xmln);
     delete annt_xmln;
@@ -1498,13 +1498,13 @@ SBase::appendAnnotation (const XMLNode* annotation)
   // see bug reported via libsbml-team
   // https://www.pivotaltracker.com/story/show/166576120
 
-  if (getNumCVTerms() > 0 && mAnnotation == NULL)
+  if (getNumCVTerms() > 0 && mAnnotation == 0)
   {
     syncAnnotation();
   }
 
 
-  if(annotation == NULL)
+  if(annotation == 0)
     return LIBSBML_OPERATION_SUCCESS;
 
   // the annotation is an rdf annotation but the object has no metaid
@@ -1516,7 +1516,7 @@ SBase::appendAnnotation (const XMLNode* annotation)
     return LIBSBML_MISSING_METAID;
   }
 
-  XMLNode* new_annotation = NULL;
+  XMLNode* new_annotation = 0;
   const string&  name = annotation->getName();
 
   // check for annotation tags and add if necessary
@@ -1532,7 +1532,7 @@ SBase::appendAnnotation (const XMLNode* annotation)
   }
 
 
-  if (mAnnotation != NULL)
+  if (mAnnotation != 0)
   {
     // if mAnnotation is just <annotation/> need to tell
     // it to no longer be an end
@@ -1607,14 +1607,14 @@ SBase::appendAnnotation (const std::string& annotation
   // see bug reported via libsbml-team
   // https://www.pivotaltracker.com/story/show/166576120
 
-  if (getNumCVTerms() > 0 && mAnnotation == NULL)
+  if (getNumCVTerms() > 0 && mAnnotation == 0)
   {
     syncAnnotation();
   }
 
   int success = LIBSBML_OPERATION_FAILED;
   XMLNode* annt_xmln;
-  if (getSBMLDocument() != NULL)
+  if (getSBMLDocument() != 0)
   {
     const XMLNamespaces* xmlns = getSBMLDocument()->getNamespaces();
     annt_xmln = XMLNode::convertStringToXMLNode(annotation,xmlns);
@@ -1624,7 +1624,7 @@ SBase::appendAnnotation (const std::string& annotation
     annt_xmln = XMLNode::convertStringToXMLNode(annotation);
   }
 
-  if(annt_xmln != NULL)
+  if(annt_xmln != 0)
   {
     success = appendAnnotation(annt_xmln);
     delete annt_xmln;
@@ -1640,7 +1640,7 @@ SBase::removeTopLevelAnnotationElement(const std::stri
 {
 
   int success = LIBSBML_OPERATION_FAILED;
-  if (mAnnotation == NULL)
+  if (mAnnotation == 0)
   {
     success = LIBSBML_OPERATION_SUCCESS;
     return success;
@@ -1694,11 +1694,11 @@ SBase::removeTopLevelAnnotationElement(const std::stri
     if (removeEmpty && mAnnotation->getNumChildren() == 0)
     {
       delete mAnnotation;
-      mAnnotation = NULL;
+      mAnnotation = 0;
     }
 
     // check success
-    if (mAnnotation == NULL || mAnnotation->getIndex(elementName) < 0)
+    if (mAnnotation == 0 || mAnnotation->getIndex(elementName) < 0)
     {
       success = LIBSBML_OPERATION_SUCCESS;
     }
@@ -1712,7 +1712,7 @@ int
 SBase::replaceTopLevelAnnotationElement(const XMLNode* annotation)
 {
   int success = LIBSBML_OPERATION_FAILED;
-  XMLNode * replacement = NULL;
+  XMLNode * replacement = 0;
   if (annotation->getName() == "annotation")
   {
     if (annotation->getNumChildren() != 1)
@@ -1747,7 +1747,7 @@ SBase::replaceTopLevelAnnotationElement(const std::str
 {
   int success = LIBSBML_OPERATION_FAILED;
   XMLNode* annt_xmln;
-  if (getSBMLDocument() != NULL)
+  if (getSBMLDocument() != 0)
   {
     const XMLNamespaces* xmlns = getSBMLDocument()->getNamespaces();
     annt_xmln = XMLNode::convertStringToXMLNode(annotation,xmlns);
@@ -1757,7 +1757,7 @@ SBase::replaceTopLevelAnnotationElement(const std::str
     annt_xmln = XMLNode::convertStringToXMLNode(annotation);
   }
 
-  if(annt_xmln != NULL)
+  if(annt_xmln != 0)
   {
     success = replaceTopLevelAnnotationElement(annt_xmln);
   }
@@ -1778,10 +1778,10 @@ SBase::setNotes(const XMLNode* notes)
   {
     return LIBSBML_OPERATION_SUCCESS;
   }
-  else if (notes == NULL)
+  else if (notes == 0)
   {
     delete mNotes;
-    mNotes = NULL;
+    mNotes = 0;
     return LIBSBML_OPERATION_SUCCESS;
   }
 
@@ -1831,7 +1831,7 @@ SBase::setNotes(const XMLNode* notes)
       && !SyntaxChecker::hasExpectedXHTMLSyntax(mNotes, getSBMLNamespaces()))
   {
     delete mNotes;
-    mNotes = NULL;
+    mNotes = 0;
     return LIBSBML_INVALID_OBJECT;
   }
 
@@ -1855,7 +1855,7 @@ SBase::setNotes(const std::string& notes, bool addXHTM
     XMLNode* notes_xmln;
 
     // you might not have a document !!
-    if (getSBMLDocument() != NULL)
+    if (getSBMLDocument() != 0)
     {
       const XMLNamespaces* xmlns = getSBMLDocument()->getNamespaces();
       notes_xmln = XMLNode::convertStringToXMLNode(notes,xmlns);
@@ -1865,7 +1865,7 @@ SBase::setNotes(const std::string& notes, bool addXHTM
       notes_xmln = XMLNode::convertStringToXMLNode(notes);
     }
 
-    if(notes_xmln != NULL)
+    if(notes_xmln != 0)
     {
       if (addXHTMLMarkup == true)
       {
@@ -1923,7 +1923,7 @@ int
 SBase::appendNotes(const XMLNode* notes)
 {
   int success = LIBSBML_OPERATION_FAILED;
-  if(notes == NULL)
+  if(notes == 0)
   {
     return LIBSBML_OPERATION_SUCCESS;
   }
@@ -2079,7 +2079,7 @@ SBase::appendNotes(const XMLNode* notes)
   }
 
 
-  if ( mNotes != NULL )
+  if ( mNotes != 0 )
   {
     //------------------------------------------------------------
     //
@@ -2272,7 +2272,7 @@ SBase::appendNotes(const std::string& notes)
 
   XMLNode* notes_xmln;
   // you might not have a document !!
-  if (getSBMLDocument() != NULL)
+  if (getSBMLDocument() != 0)
   {
       const XMLNamespaces* xmlns = getSBMLDocument()->getNamespaces();
       notes_xmln = XMLNode::convertStringToXMLNode(notes,xmlns);
@@ -2282,7 +2282,7 @@ SBase::appendNotes(const std::string& notes)
       notes_xmln = XMLNode::convertStringToXMLNode(notes);
   }
 
-  if(notes_xmln != NULL)
+  if(notes_xmln != 0)
   {
     success = appendNotes(notes_xmln);
     delete notes_xmln;
@@ -2297,7 +2297,7 @@ SBase::setModelHistory(ModelHistory * history)
   // if there is no parent then the required attributes are not
   // correctly identified
   bool dummyParent = false;
-  if (history != NULL && history->getParentSBMLObject() == NULL)
+  if (history != 0 && history->getParentSBMLObject() == 0)
   {
     history->setParentSBMLObject(this);
     dummyParent = true;
@@ -2324,17 +2324,17 @@ SBase::setModelHistory(ModelHistory * history)
     {
       status = LIBSBML_OPERATION_SUCCESS;
     }
-    else if (history == NULL)
+    else if (history == 0)
     {
       delete mHistory;
-      mHistory = NULL;
+      mHistory = 0;
       mHistoryChanged = true;
       status = LIBSBML_OPERATION_SUCCESS;
     }
     else if (!(history->hasRequiredAttributes()))
     {
       delete mHistory;
-      mHistory = NULL;
+      mHistory = 0;
       status = LIBSBML_INVALID_OBJECT;
     }
     else
@@ -2355,7 +2355,7 @@ SBase::setModelHistory(ModelHistory * history)
 int 
 SBase::setCreatedDate(Date* date)
 {
-  if (mHistory != NULL)
+  if (mHistory != 0)
   {
     return mHistory->setCreatedDate(date);
   }
@@ -2372,7 +2372,7 @@ SBase::setCreatedDate(Date* date)
 int
 SBase::addModifiedDate(Date* date)
 {
-  if (mHistory != NULL)
+  if (mHistory != 0)
   {
     return mHistory->addModifiedDate(date);
   }
@@ -2459,7 +2459,7 @@ SBase::getAncestorOfType(int type, const std::string& 
   SBase *child;
   SBase *parent = getParentSBMLObject();
 
-  while ( parent != NULL &&
+  while ( parent != 0 &&
           !( parent->getPackageName() == "core" &&
              parent->getTypeCode() == SBML_DOCUMENT )
         )
@@ -2474,7 +2474,7 @@ SBase::getAncestorOfType(int type, const std::string& 
   }
 
   // if we get here we havent found an ancestor of this type
-  return NULL;
+  return 0;
 
 }
 
@@ -2488,7 +2488,7 @@ SBase::getAncestorOfType(int type, const std::string p
   const SBase *child;
   const SBase *parent = getParentSBMLObject();
 
-  while ( parent != NULL &&
+  while ( parent != 0 &&
           !( parent->getPackageName() == "core" &&
              parent->getTypeCode() == SBML_DOCUMENT )
         )
@@ -2503,7 +2503,7 @@ SBase::getAncestorOfType(int type, const std::string p
   }
 
   // if we get here we havent found an ancestor of this type
-  return NULL;
+  return 0;
 
 }
 
@@ -2549,9 +2549,9 @@ SBase::setSBOTerm (const std::string &sboid)
 int
 SBase::setNamespaces(XMLNamespaces* xmlns)
 {
-  if (xmlns == NULL)
+  if (xmlns == 0)
   {
-    mSBMLNamespaces->setNamespaces(NULL);
+    mSBMLNamespaces->setNamespaces(0);
     return LIBSBML_OPERATION_SUCCESS;
   }
   else
@@ -2672,7 +2672,7 @@ int
 SBase::unsetNotes ()
 {
   delete mNotes;
-  mNotes = NULL;
+  mNotes = 0;
   return LIBSBML_OPERATION_SUCCESS;
 }
 
@@ -2683,7 +2683,7 @@ SBase::unsetNotes ()
 int
 SBase::unsetAnnotation ()
 {
-  const XMLNode* empty = NULL;
+  const XMLNode* empty = 0;
   return setAnnotation(empty);
 }
 
@@ -2752,7 +2752,7 @@ int SBase::addTermToExistingBag(CVTerm *term, Qualifie
   unsigned int added = 0;
   unsigned int length = mCVTerms->getSize();
 
-  CVTerm* nthTerm = NULL;
+  CVTerm* nthTerm = 0;
 
   if (length == 0) return (int)added;
 
@@ -2764,7 +2764,7 @@ int SBase::addTermToExistingBag(CVTerm *term, Qualifie
     {
       nthTerm = static_cast <CVTerm *>(mCVTerms->get((unsigned int)n));
 
-      if (nthTerm != NULL && biol == nthTerm->getBiologicalQualifierType())
+      if (nthTerm != 0 && biol == nthTerm->getBiologicalQualifierType())
       {
         for (int r = 0; r < term->getResources()->getLength(); r++)
         {
@@ -2783,7 +2783,7 @@ int SBase::addTermToExistingBag(CVTerm *term, Qualifie
     {
       nthTerm = static_cast <CVTerm *>(mCVTerms->get(n));
 
-      if (nthTerm != NULL && model == nthTerm->getModelQualifierType())
+      if (nthTerm != 0 && model == nthTerm->getModelQualifierType())
       {
         for (int r = 0; r < term->getResources()->getLength(); r++)
         {
@@ -2811,7 +2811,7 @@ SBase::addCVTerm(CVTerm * term, bool newBag)
     return LIBSBML_MISSING_METAID;
   }
 
-  if (term == NULL)
+  if (term == 0)
   {
     return LIBSBML_OPERATION_FAILED;
   }
@@ -2825,7 +2825,7 @@ SBase::addCVTerm(CVTerm * term, bool newBag)
    */
   CVTerm * copyTerm = term->clone();
 
-  if (mCVTerms == NULL)
+  if (mCVTerms == 0)
   {
     mCVTerms = new List();
     mCVTerms->add((void *) term->clone());
@@ -2890,7 +2890,7 @@ SBase::getCVTerms() const
 unsigned int
 SBase::getNumCVTerms() const
 {
-  if (mCVTerms != NULL)
+  if (mCVTerms != 0)
   {
     return mCVTerms->getSize();
   }
@@ -2912,7 +2912,7 @@ SBase::getNumCVTerms() const
 CVTerm*
 SBase::getCVTerm(unsigned int n)
 {
-  return (mCVTerms) ? static_cast <CVTerm*> (mCVTerms->get(n)) : NULL;
+  return (mCVTerms) ? static_cast <CVTerm*> (mCVTerms->get(n)) : 0;
 }
 
 
@@ -2923,16 +2923,16 @@ SBase::getCVTerm(unsigned int n)
 int
 SBase::unsetCVTerms()
 {
-  if (mCVTerms != NULL)
+  if (mCVTerms != 0)
   {
     unsigned int size = mCVTerms->getSize();
     while (size--) delete static_cast<CVTerm*>( mCVTerms->remove(0) );
     delete mCVTerms;
     mCVTermsChanged = true;
   }
-  mCVTerms = NULL;
+  mCVTerms = 0;
 
-  if (mCVTerms != NULL)
+  if (mCVTerms != 0)
     return LIBSBML_OPERATION_FAILED;
   else
     return LIBSBML_OPERATION_SUCCESS;
@@ -2942,11 +2942,11 @@ SBase::unsetCVTerms()
 int
 SBase::unsetModelHistory()
 {
-  if (mHistory != NULL)
+  if (mHistory != 0)
     mHistoryChanged = true;
 
   delete mHistory;
-  mHistory = NULL;
+  mHistory = 0;
 
   /* ModelHistory is only allowed on Model in L2
    * but on any element in L3
@@ -2956,7 +2956,7 @@ SBase::unsetModelHistory()
     return LIBSBML_UNEXPECTED_ATTRIBUTE;
   }
 
-  if (mHistory != NULL)
+  if (mHistory != 0)
   {
     return LIBSBML_OPERATION_FAILED;
   }
@@ -2970,7 +2970,7 @@ SBase::unsetModelHistory()
 int
 SBase::unsetCreatedDate()
 {
-  if (mHistory != NULL && mHistory->isSetCreatedDate())
+  if (mHistory != 0 && mHistory->isSetCreatedDate())
   {
     mHistoryChanged = true;
   }
@@ -2989,7 +2989,7 @@ SBase::unsetCreatedDate()
 
   Date* created = mHistory->getCreatedDate();
   delete created;
-  mHistory->mCreatedDate = NULL;
+  mHistory->mCreatedDate = 0;
 
   if (mHistory->isSetCreatedDate() == true)
   {
@@ -3005,7 +3005,7 @@ SBase::unsetCreatedDate()
 int
 SBase::unsetModifiedDates()
 {
-  if (mHistory != NULL && mHistory->isSetModifiedDate())
+  if (mHistory != 0 && mHistory->isSetModifiedDate())
   {
     mHistoryChanged = true;
   }
@@ -3047,7 +3047,7 @@ SBase::unsetModifiedDates()
 BiolQualifierType_t
 SBase::getResourceBiologicalQualifier(std::string resource) const
 {
-  if (mCVTerms != NULL)
+  if (mCVTerms != 0)
   {
     for (unsigned int n = 0; n < mCVTerms->getSize(); n++)
     {
@@ -3084,7 +3084,7 @@ SBase::getResourceBiologicalQualifier(std::string reso
 ModelQualifierType_t
 SBase::getResourceModelQualifier(std::string resource) const
 {
-  if (mCVTerms != NULL)
+  if (mCVTerms != 0)
   {
     for (unsigned int n = 0; n < mCVTerms->getSize(); n++)
     {
@@ -3116,7 +3116,7 @@ SBase::getResourceModelQualifier(std::string resource)
 const Model*
 SBase::getModel () const
 {
-  return (mSBML != NULL) ? mSBML->getModel() : NULL;
+  return (mSBML != 0) ? mSBML->getModel() : 0;
 }
 
 
@@ -3126,9 +3126,9 @@ SBase::getModel () const
 unsigned int
 SBase::getLevel () const
 {
-  if (mSBML != NULL)
+  if (mSBML != 0)
     return mSBML->mLevel;
-  else if (mSBMLNamespaces != NULL)
+  else if (mSBMLNamespaces != 0)
     return mSBMLNamespaces->getLevel();
   else
     return SBMLDocument::getDefaultLevel();
@@ -3141,9 +3141,9 @@ SBase::getLevel () const
 unsigned int
 SBase::getVersion () const
 {
-  if (mSBML != NULL)
+  if (mSBML != 0)
     return mSBML->mVersion;
-  else if (mSBMLNamespaces != NULL)
+  else if (mSBMLNamespaces != 0)
     return mSBMLNamespaces->getVersion();
   else
     return SBMLDocument::getDefaultVersion();
@@ -3370,7 +3370,7 @@ SBase::unsetAttribute(const std::string& attributeName
 SBase* 
 SBase::createChildObject(const std::string& elementName)
 {
-  return NULL;
+  return 0;
 }
 /** @endcond */
 
@@ -3386,7 +3386,7 @@ SBase::addChildObject(const std::string& elementName, 
 SBase*
 SBase::removeChildObject(const std::string& elementName, const std::string& id)
 {
-  return NULL;
+  return 0;
 }
 /** @endcond */
 
@@ -3405,7 +3405,7 @@ unsigned int
 SBase* 
 SBase::getObject(const std::string& objectName, unsigned int index)
 {
-  return NULL;
+  return 0;
 }
 
   /** @endcond */
@@ -3433,14 +3433,14 @@ SBase::getMessageString () const
 const ASTNode*
 SBase::getMath() const
 {
-  return NULL;
+  return 0;
 }
 
 
 bool
 SBase::isSetMath() const
 {
-  return getMath() != NULL;
+  return getMath() != 0;
 }
 
 
@@ -3567,7 +3567,7 @@ SBase::getPlugin(const std::string& package) const
 SBasePlugin*
 SBase::getPlugin(unsigned int n)
 {
-  if (n>=getNumPlugins()) return NULL;
+  if (n>=getNumPlugins()) return 0;
   return mPlugins[n];
 }
 
@@ -3575,7 +3575,7 @@ SBase::getPlugin(unsigned int n)
 SBasePlugin*
 SBase::getDisabledPlugin(unsigned int n)
 {
-  if (n>=getNumDisabledPlugins()) return NULL;
+  if (n>=getNumDisabledPlugins()) return 0;
   return mDisabledPlugins[n];
 }
 
@@ -3662,7 +3662,7 @@ SBase::enablePackage(const std::string& pkgURI, const 
     {
       return success;
     }
-    else if (mSBML != NULL && mSBML->isIgnoredPackage(pkgURI) == true)
+    else if (mSBML != 0 && mSBML->isIgnoredPackage(pkgURI) == true)
     {
       return success;
     }
@@ -3671,7 +3671,7 @@ SBase::enablePackage(const std::string& pkgURI, const 
   {
     if (!isPackageURIEnabled(pkgURI))
     {
-      if (mSBML == NULL)
+      if (mSBML == 0)
       {
         return success;
 
@@ -3684,8 +3684,8 @@ SBase::enablePackage(const std::string& pkgURI, const 
   }
 
   // if we are dealing with an unknown package it will not be in the register
-  if (mSBML == NULL 
-    || (mSBML != NULL && mSBML->isIgnoredPackage(pkgURI) == false 
+  if (mSBML == 0 
+    || (mSBML != 0 && mSBML->isIgnoredPackage(pkgURI) == false 
    && mSBML->isDisabledIgnoredPackage(pkgURI) == false))
   {
   //
@@ -3787,9 +3787,9 @@ SBase::enablePackageInternal(const std::string& pkgURI
         SBaseExtensionPoint extPoint(getPackageName(), getTypeCode(), getElementName());
         const SBasePluginCreatorBase* sbPluginCreator = sbmlext->getSBasePluginCreator(extPoint);
         // trully awful hack for the case where we are adding a plugin to a modelDefinition
-        // since these do not have plugins the plugin creator is NULL
+        // since these do not have plugins the plugin creator is 0
         // we have to force it to realise it is also a core model
-        if (sbPluginCreator == NULL && getPackageName() == "comp" && getElementName() == "modelDefinition")
+        if (sbPluginCreator == 0 && getPackageName() == "comp" && getElementName() == "modelDefinition")
         {
           SBaseExtensionPoint coreextPoint("core", SBML_MODEL, "model");
           sbPluginCreator = sbmlext->getSBasePluginCreator(coreextPoint);
@@ -4165,7 +4165,7 @@ SBase::hasValidLevelVersionNamespaceCombination(int ty
   std::string declaredURI("");
   unsigned int version = getVersion();
 
-  if (xmlns != NULL)
+  if (xmlns != 0)
   {
     //
     // checks defined SBML XMLNamespace
@@ -4383,7 +4383,7 @@ SBase::hasValidLevelVersionNamespaceCombination(int ty
   // if this is an extension namespace, this method will return the wrong answer,
   // so instead return true
   const ISBMLExtensionNamespaces* test = dynamic_cast<ISBMLExtensionNamespaces*> (mSBMLNamespaces);
-  if (!valid && test != NULL)
+  if (!valid && test != 0)
     return true;
 
   return valid;
@@ -4393,7 +4393,7 @@ SBase::hasValidLevelVersionNamespaceCombination(int ty
 int
 SBase::setSBMLNamespaces(const SBMLNamespaces * sbmlns)
 {
-  if (sbmlns == NULL)
+  if (sbmlns == 0)
     return LIBSBML_INVALID_OBJECT;
 
   SBMLNamespaces* sbmlnsClone = (sbmlns) ? sbmlns->clone() : 0;
@@ -4412,7 +4412,7 @@ SBase::setSBMLNamespacesAndOwn(SBMLNamespaces * sbmlns
   delete mSBMLNamespaces;
   mSBMLNamespaces = sbmlns;
 
-  if(sbmlns != NULL)
+  if(sbmlns != 0)
     setElementNamespace(sbmlns->getURI());
 }
 
@@ -4421,11 +4421,11 @@ SBase::setSBMLNamespacesAndOwn(SBMLNamespaces * sbmlns
 SBMLNamespaces *
 SBase::getSBMLNamespaces() const
 {
-  if (mSBML != NULL)
+  if (mSBML != 0)
     return mSBML->mSBMLNamespaces;
   
   // initialize SBML namespace if need be
-  if (mSBMLNamespaces == NULL)
+  if (mSBMLNamespaces == 0)
     const_cast<SBase*>(this)->mSBMLNamespaces = new SBMLNamespaces();
   return mSBMLNamespaces;  
 }
@@ -4478,7 +4478,7 @@ SBase::read (XMLInputStream& stream)
     // remembering the horrible situation where the sbmlns might be declared
     // with more than one prefix
     const XMLNamespaces * xmlns = this->getSBMLNamespaces()->getNamespaces();
-    if (xmlns != NULL)
+    if (xmlns != 0)
     {
       int i = xmlns->getIndexByPrefix(element.getPrefix());
       if (i < xmlns->getNumNamespaces())
@@ -4550,7 +4550,7 @@ SBase::read (XMLInputStream& stream)
   {
     if (CallbackRegistry::invokeCallbacks(getSBMLDocument()) != LIBSBML_OPERATION_SUCCESS)
     {
-      if (getErrorLog() != NULL && !getErrorLog()->contains(OperationInterrupted))
+      if (getErrorLog() != 0 && !getErrorLog()->contains(OperationInterrupted))
         logError(OperationInterrupted, getLevel(), getVersion());
       break;
     }
@@ -4581,14 +4581,14 @@ SBase::read (XMLInputStream& stream)
            << stream.peek().getURI() << endl;
 #endif
 
-      SBase * object = NULL;
+      SBase * object = 0;
       try
       {
         object = createObject(stream);
       }
       catch (const SBMLExtensionException&)
       {
-        object = NULL;
+        object = 0;
       }
 
       if (!object)
@@ -4596,7 +4596,7 @@ SBase::read (XMLInputStream& stream)
         object = createExtensionObject(stream);
       }
 
-      if (object != NULL)
+      if (object != 0)
       {
         checkOrderAndLogError(object, position);
         position = object->getElementPosition();
@@ -4684,7 +4684,7 @@ SBase::write (XMLOutputStream& stream) const
 void
 SBase::writeElements (XMLOutputStream& stream) const
 {
-  if (mNotes != NULL)
+  if (mNotes != 0)
   {
     mNotes->writeToStream(stream);
   }
@@ -4694,7 +4694,7 @@ SBase::writeElements (XMLOutputStream& stream) const
    */
 
   const_cast <SBase *> (this)->syncAnnotation();
-  if (mAnnotation != NULL) stream << *mAnnotation;
+  if (mAnnotation != 0) stream << *mAnnotation;
 }
 
 void
@@ -4733,19 +4733,19 @@ SBase::writeExtensionElements (XMLOutputStream& stream
  * XMLInputStream.
  *
  * @return the SBML object corresponding to next XMLToken in the
- * XMLInputStream or @c NULL if the token was not recognized.
+ * XMLInputStream or @c 0 if the token was not recognized.
  */
 SBase*
 SBase::createObject (XMLInputStream&)
 {
-  return NULL;
+  return 0;
 }
 
 
 SBase*
 SBase::createExtensionObject (XMLInputStream& stream)
 {
-  SBase* object = NULL;
+  SBase* object = 0;
 
   /* ---------------------------------------------------------
    *
@@ -4755,7 +4755,7 @@ SBase::createExtensionObject (XMLInputStream& stream)
    */
 
   const string& uri  = stream.peek().getURI();
-  SBasePlugin* sbext = NULL;
+  SBasePlugin* sbext = 0;
 
   for (size_t i=0; i < mPlugins.size(); i++)
   {
@@ -4778,14 +4778,14 @@ SBase::createExtensionObject (XMLInputStream& stream)
     }
     catch (const SBMLExtensionException&)
     {
-      object = NULL;
+      object = 0;
     }
   }
 #if 0
   else
   {
     std::cout << "[DEBUG] SBase::createExtensionObject " << getElementName()
-              << " " << uri << " is NULL" << std::endl;
+              << " " << uri << " is 0" << std::endl;
   }
 #endif
 
@@ -4852,7 +4852,7 @@ SBase::readAnnotation (XMLInputStream& stream)
     // If an annotation already exists, log it as an error and replace
     // the content of the existing annotation with the new one.
 
-    if (mAnnotation != NULL)
+    if (mAnnotation != 0)
     {
       string msg = "An SBML <" + getElementName() + "> element ";
       switch(getTypeCode()) {
@@ -4884,7 +4884,7 @@ SBase::readAnnotation (XMLInputStream& stream)
     delete mAnnotation;
     mAnnotation = new XMLNode(stream);
     checkAnnotation();
-    if(mCVTerms != NULL)
+    if(mCVTerms != 0)
     {
       unsigned int size = mCVTerms->getSize();
       while (size--) delete static_cast<CVTerm*>( mCVTerms->remove(0) );
@@ -4899,7 +4899,7 @@ SBase::readAnnotation (XMLInputStream& stream)
       {
         mHistory = RDFAnnotationParser::parseRDFAnnotation(mAnnotation,
                                                 getMetaId().c_str(), &(stream), this);
-        if (mHistory != NULL && mHistory->hasRequiredAttributes() == false)
+        if (mHistory != 0 && mHistory->hasRequiredAttributes() == false)
         {
           logError(RDFNotCompleteModelHistory, level, version,
             "An invalid ModelHistory element has been stored.");
@@ -4908,7 +4908,7 @@ SBase::readAnnotation (XMLInputStream& stream)
       }
       else
       {
-        mHistory = NULL;
+        mHistory = 0;
       }
     }
     if (RDFAnnotationParser::hasCVTermRDFAnnotation(mAnnotation))
@@ -4982,7 +4982,7 @@ SBase::readNotes (XMLInputStream& stream)
     // If an annotation element already exists, then the ordering is wrong.
     // In either case, replace existing content with the new notes read.
 
-    if (mNotes != NULL)
+    if (mNotes != 0)
     {
       if (getLevel() < 3)
       {
@@ -4995,7 +4995,7 @@ SBase::readNotes (XMLInputStream& stream)
         logError(OnlyOneNotesElementAllowed, getLevel(), getVersion());
       }
     }
-    else if (mAnnotation != NULL)
+    else if (mAnnotation != 0)
     {
       logError(NotSchemaConformant, getLevel(), getVersion(),
                "Incorrect ordering of <annotation> and <notes> elements -- "
@@ -5013,7 +5013,7 @@ SBase::readNotes (XMLInputStream& stream)
     const XMLNamespaces &xmlns = mNotes->getNamespaces();
     checkDefaultNamespace(&xmlns,"notes");
 
-    if (getSBMLDocument() != NULL && getSBMLDocument()->getNumErrors() == 0)
+    if (getSBMLDocument() != 0 && getSBMLDocument()->getNumErrors() == 0)
     {
       checkXHTML(mNotes);
     }
@@ -5048,7 +5048,7 @@ SBase::getElementPosition () const
 SBMLErrorLog*
 SBase::getErrorLog ()
 {
-  return (mSBML != NULL) ? mSBML->getErrorLog() : NULL;
+  return (mSBML != 0) ? mSBML->getErrorLog() : 0;
 }
 /** @endcond */
 
@@ -5075,7 +5075,7 @@ SBase::logUnknownAttribute( const string& attribute,
           << " Version " << version << " Package "
           << getPackageName() << " Version " << getPackageVersion() << " <"
           << element << "> element.";
-      if (mSBML != NULL)
+      if (mSBML != 0)
       {
         getErrorLog()->logError(UnknownPackageAttribute,
               level, version, msg.str(), getLine(), getColumn());
@@ -5088,7 +5088,7 @@ SBase::logUnknownAttribute( const string& attribute,
           << " Version " << version << " Package "
           << getPackageName() << " Version " << getPackageVersion() << " <"
           << element << "> element.";
-      if (mSBML != NULL)
+      if (mSBML != 0)
       {
         getErrorLog()->logError(UnknownCoreAttribute,
               level, version, msg.str(), getLine(), getColumn());
@@ -5462,7 +5462,7 @@ SBase::logUnknownElement( const string& element,
         << " Package " << getPackageName()
         << " Version " << getPackageVersion() << ".";
 
-    if (mSBML != NULL)
+    if (mSBML != 0)
     {
       getErrorLog()->logError(UnrecognizedElement,
           level, version, msg1.str(), getLine(), getColumn());
@@ -5476,7 +5476,7 @@ SBase::logUnknownElement( const string& element,
     msg1 << "Element '" << element << "' is not part of the definition of "
         << "SBML Level " << level << " Version " << version << ".";
 
-    if (mSBML != NULL)
+    if (mSBML != 0)
     {
       getErrorLog()->logError(UnrecognizedElement,
             level, version, msg1.str(), getLine(), getColumn());
@@ -5507,7 +5507,7 @@ SBase::logEmptyString( const string& attribute,
   // (TODO) Needs to be fixed so that error can be added when
   // no SBMLDocument attached.
   //
-  if (mSBML != NULL)
+  if (mSBML != 0)
     getErrorLog()->logError(NotSchemaConformant,
                             level, version, msg.str(), getLine(), getColumn());
 }
@@ -5531,7 +5531,7 @@ SBase::logError (  unsigned int       id
   // (TODO) Needs to be fixed so that error can be added when
   // no SBMLDocument attached.
   //
-  if ( SBase::getErrorLog() != NULL && mSBML != NULL)
+  if ( SBase::getErrorLog() != 0 && mSBML != 0)
     getErrorLog()->logError(id, getLevel(), getVersion(), details, getLine(), getColumn());
 }
 /** @endcond */
@@ -5731,7 +5731,7 @@ SBase::readExtensionAttributes (const XMLAttributes& a
    *
    * ----------------------------------------------------------
    */
-    const ExpectedAttributes* base = expectedAttributes  != NULL ?
+    const ExpectedAttributes* base = expectedAttributes  != 0 ?
 expectedAttributes : new ExpectedAttributes();
 
 
@@ -5749,7 +5749,7 @@ expectedAttributes : new ExpectedAttributes();
     mPlugins[i]->readAttributes(attributes,ea);
   }
 
-  if (expectedAttributes  == NULL )
+  if (expectedAttributes  == 0 )
     delete base;
 
   /////////////////////////////////////////////////////////////////////////
@@ -5810,7 +5810,7 @@ SBase::storeUnknownExtElement(XMLInputStream &stream)
   {
     return false;
   }
-  else if (mSBML != NULL && mSBML->isIgnoredPackage(uri))
+  else if (mSBML != 0 && mSBML->isIgnoredPackage(uri))
   {
 
     XMLNode xmlnode(stream);
@@ -5873,7 +5873,7 @@ SBase::getSBMLPrefix() const
   std::string prefix = "";
 
   const XMLNamespaces *xmlns = getNamespaces();
-  if (xmlns == NULL)
+  if (xmlns == 0)
     return getPrefix();
 
   for (int i = 0; i < xmlns->getNumNamespaces(); i++)
@@ -5891,7 +5891,7 @@ SBase::getSBMLPrefix() const
  *
  * @note The root element may not be an SBMLDocument element. For example,
  * this element is the root element if this element doesn't have a parent
- * SBML object (i.e. mParentSBMLObject is NULL)
+ * SBML object (i.e. mParentSBMLObject is 0)
  */
 SBase*
 SBase::getRootElement()
@@ -6063,7 +6063,7 @@ SBase::syncAnnotation ()
 {
   // look to see whether an existing history has been altered
   if (!mHistoryChanged
-      && getModelHistory() != NULL
+      && getModelHistory() != 0
       && getModelHistory()->hasBeenModified()
       )
   {
@@ -6088,7 +6088,7 @@ SBase::syncAnnotation ()
     reconstructRDFAnnotation();
     mHistoryChanged = false;
     mCVTermsChanged = false;
-    if (getModelHistory() != NULL)
+    if (getModelHistory() != 0)
     {
       getModelHistory()->resetModifiedFlags();
     }
@@ -6098,7 +6098,7 @@ SBase::syncAnnotation ()
     }
   }
 
-  if (mAnnotation == NULL)
+  if (mAnnotation == 0)
   {
     XMLToken ann_token = XMLToken(XMLTriple("annotation", "", ""),
                                       XMLAttributes());
@@ -6112,10 +6112,10 @@ SBase::syncAnnotation ()
   }
 
   // if annotation still empty delete the annotation
-  if (mAnnotation != NULL && mAnnotation->getNumChildren() == 0)
+  if (mAnnotation != 0 && mAnnotation->getNumChildren() == 0)
   {
     delete mAnnotation;
-    mAnnotation = NULL;
+    mAnnotation = 0;
   }
 
 }
@@ -6130,7 +6130,7 @@ SBase::reconstructRDFAnnotation()
   bool hasAdditionalRDF = false;
 
   // determine status of existing annotation before doing anything
-  if (mAnnotation != NULL)
+  if (mAnnotation != 0)
   {
     hasRDF = RDFAnnotationParser::hasRDFAnnotation(mAnnotation);
     hasAdditionalRDF =
@@ -6175,9 +6175,9 @@ SBase::reconstructRDFAnnotation()
   }
 
   // look at whether the user has changed the RDF elements
-  if(mAnnotation != NULL && hasRDF)
+  if(mAnnotation != 0 && hasRDF)
   {
-    XMLNode* new_annotation = NULL;
+    XMLNode* new_annotation = 0;
     if (mHistoryChanged == true)
     {
       if (mCVTermsChanged == true)
@@ -6200,7 +6200,7 @@ SBase::reconstructRDFAnnotation()
       }
     }
 
-    if(new_annotation != NULL)
+    if(new_annotation != 0)
     {
       *mAnnotation = *new_annotation;
       delete new_annotation;
@@ -6212,11 +6212,11 @@ SBase::reconstructRDFAnnotation()
 
   XMLNode * cvTerms = RDFAnnotationParser::parseCVTerms(this);
 
-  if (history != NULL &&  mHistoryChanged == true && mCVTermsChanged == false)
+  if (history != 0 &&  mHistoryChanged == true && mCVTermsChanged == false)
   {
-    if (cvTerms == NULL)
+    if (cvTerms == 0)
     {
-      if (mAnnotation == NULL)
+      if (mAnnotation == 0)
       {
         // if there was no annotation before a user added history/cvterms
         mAnnotation = history->clone(); //noannot.xml
@@ -6266,7 +6266,7 @@ SBase::reconstructRDFAnnotation()
       // test file: histCVAddRDF/histCVOnly/histCVOther
       unsigned int noChild
         = history->getChild("RDF").getChild("Description").getNumChildren();
-      if (mAnnotation != NULL)
+      if (mAnnotation != 0)
         for (unsigned int i = noChild; i > 0; i--)
         {
           ((mAnnotation->getChild("RDF")).getChild("Description")).insertChild(
@@ -6275,11 +6275,11 @@ SBase::reconstructRDFAnnotation()
     }
   }
 
-  if (cvTerms != NULL &&  mCVTermsChanged == true && mHistoryChanged == false)
+  if (cvTerms != 0 &&  mCVTermsChanged == true && mHistoryChanged == false)
   {
-    if (history == NULL)
+    if (history == 0)
     {
-      if (mAnnotation == NULL)
+      if (mAnnotation == 0)
       {
         // if there was no annotation before a user added history/cvterms
         mAnnotation = cvTerms->clone(); //noannot.xml
@@ -6329,7 +6329,7 @@ SBase::reconstructRDFAnnotation()
       // test file: histCVAddRDF/histCVOnly/histCVOther
       unsigned int noChild
         = cvTerms->getChild("RDF").getChild("Description").getNumChildren();
-      if (mAnnotation != NULL)
+      if (mAnnotation != 0)
         for (unsigned int i = 0; i < noChild; i++)
         {
           ((mAnnotation->getChild("RDF")).getChild("Description")).addChild(
@@ -6340,15 +6340,15 @@ SBase::reconstructRDFAnnotation()
 
   if (mCVTermsChanged == true && mHistoryChanged == true)
   {
-    if (mAnnotation == NULL)
+    if (mAnnotation == 0)
     {
       // if there was no annotation before a user changed history/cvterms
       // need to catch case where user in fact unset history/cvterms
       // test file noannot.xml
-      if (history != NULL)
+      if (history != 0)
       {
         mAnnotation = history->clone();
-        if (cvTerms != NULL)
+        if (cvTerms != 0)
         {
           unsigned int noChild
             = cvTerms->getChild("RDF").getChild("Description").getNumChildren();
@@ -6361,7 +6361,7 @@ SBase::reconstructRDFAnnotation()
       }
       else
       {
-        if (cvTerms != NULL)
+        if (cvTerms != 0)
         {
           mAnnotation = cvTerms->clone();
         }
@@ -6385,11 +6385,11 @@ SBase::reconstructRDFAnnotation()
         // description element
         // <rdf><some-non-miriam-rdf> needs to become
         // <rdf><HistoryAndCVTerms/><some-non-...
-        if (history != NULL)
+        if (history != 0)
         {
           mAnnotation->getChild("RDF").insertChild(0,
             history->getChild("RDF").getChild("Description"));
-          if (cvTerms != NULL)
+          if (cvTerms != 0)
           {
             unsigned int noChild
               = cvTerms->getChild("RDF").getChild("Description").getNumChildren();
@@ -6402,7 +6402,7 @@ SBase::reconstructRDFAnnotation()
         }
         else
         {
-          if (cvTerms != NULL)
+          if (cvTerms != 0)
           {
            mAnnotation->getChild("RDF").insertChild(0,
             cvTerms->getChild("RDF").getChild("Description"));
@@ -6415,10 +6415,10 @@ SBase::reconstructRDFAnnotation()
         // empty annotation element OR one with other top level annotations
         // <annotation/> OR <annotation><someAnnotations/>
         // just add the whole history and cvterms
-        if (history != NULL)
+        if (history != 0)
         {
           mAnnotation->addChild(history->getChild("RDF"));
-          if (cvTerms != NULL)
+          if (cvTerms != 0)
           {
             unsigned int noChild
               = cvTerms->getChild("RDF").getChild("Description").getNumChildren();
@@ -6431,7 +6431,7 @@ SBase::reconstructRDFAnnotation()
         }
         else
         {
-          if (cvTerms != NULL)
+          if (cvTerms != 0)
           {
             mAnnotation->addChild(cvTerms->getChild("RDF"));
           }
@@ -6442,8 +6442,8 @@ SBase::reconstructRDFAnnotation()
 }
 
 
-  if (history != NULL) delete history;
-  if (cvTerms != NULL) delete cvTerms;
+  if (history != 0) delete history;
+  if (cvTerms != 0) delete cvTerms;
 }
 /** @endcond */
 
@@ -6631,7 +6631,7 @@ SBase::checkListOfPopulated(SBase* object)
 UnitDefinition* 
 SBase::getDerivedUnitDefinition() 
 { 
-  return NULL; 
+  return 0; 
 }
 /** @endcond */
 
@@ -6653,9 +6653,9 @@ SBase::containsUndeclaredUnits() 
 int SBase::removeFromParentAndDelete()
 {
   SBase* parent = getParentSBMLObject();
-  if (parent==NULL) return LIBSBML_OPERATION_FAILED;
+  if (parent==0) return LIBSBML_OPERATION_FAILED;
   ListOf* parentList = static_cast<ListOf*>(parent);
-  if (parentList == NULL) return LIBSBML_OPERATION_FAILED;
+  if (parentList == 0) return LIBSBML_OPERATION_FAILED;
   for (unsigned int i=0; i<parentList->size(); i++) {
     const SBase* sibling = parentList->get(i);
     if (sibling == this) {
@@ -6686,7 +6686,7 @@ SBase::checkMathMLNamespace(const XMLToken &elem)
       }
     }
   }
-  if (match == 0 && mSBML->getNamespaces() != NULL)
+  if (match == 0 && mSBML->getNamespaces() != 0)
   {
     for (n = 0; n < mSBML->getNamespaces()->getLength(); n++)
     {
@@ -6723,7 +6723,7 @@ SBase::checkDefaultNamespace(const XMLNamespaces* xmln
   // checks if the given default namespace (if any) is a valid
   // SBML namespace
   //
-  if (xmlns == NULL || xmlns->getLength() == 0)
+  if (xmlns == 0 || xmlns->getLength() == 0)
     return;
 
   const std::string defaultURI = xmlns->getURI(prefix);
@@ -6753,7 +6753,7 @@ SBase::read(const XMLNode& node, XMLErrorSeverityOverr
 
   // set override for error messages
   XMLErrorSeverityOverride_t old = LIBSBML_OVERRIDE_DISABLED;
-  if (log != NULL )
+  if (log != 0 )
   {
     old = log->getSeverityOverride();
     log->setSeverityOverride(flag);
@@ -6767,7 +6767,7 @@ SBase::read(const XMLNode& node, XMLErrorSeverityOverr
   read(stream);
 
   // restore logging
-  if (log != NULL )
+  if (log != 0 )
   {
     log->setSeverityOverride(old);
   }
@@ -6784,7 +6784,7 @@ SBase::toXMLNode()
   // XMLNamespaces would then assign the actual default namespace, which is in most cases
   // the SBML namespace. In that case we adjust the default namespace here
   const ISBMLExtensionNamespaces *extns = dynamic_cast<ISBMLExtensionNamespaces*>(sbmlns);
-  if (extns != NULL)
+  if (extns != 0)
   {
     xmlns.remove("");
     xmlns.add(xmlns.getURI(extns->getPackageName()), "");
@@ -6807,7 +6807,7 @@ SBase::checkAnnotation()
   std::vector<std::string> uri_list;
   uri_list.clear();
 
-  if (mAnnotation == NULL) return;
+  if (mAnnotation == 0) return;
 
   //
   // checks if the given default namespace (if any) is a valid
@@ -6873,7 +6873,7 @@ SBase::checkAnnotation()
     if (topLevel.getNamespaces().getLength() == 0)
     {
       // not on actual element - is it explicit ??
-      if( mSBML->getNamespaces() != NULL)
+      if( mSBML->getNamespaces() != 0)
       /* check for implicit declaration */
       {
         for (n = 0; n < mSBML->getNamespaces()->getLength(); n++)
@@ -6965,7 +6965,7 @@ SBase::checkAnnotation()
 void
 SBase::checkXHTML(const XMLNode * xhtml)
 {
-  if (xhtml == NULL) return;
+  if (xhtml == 0) return;
 
   const string&  name = xhtml->getName();
   unsigned int errorNS, errorXML, errorDOC, errorELEM;
@@ -7009,7 +7009,7 @@ SBase::checkXHTML(const XMLNode * xhtml)
     }
   }
 
-  const XMLNamespaces* toplevelNS = (mSBML) ? mSBML->getNamespaces() : NULL;
+  const XMLNamespaces* toplevelNS = (mSBML) ? mSBML->getNamespaces() : 0;
 
   /*
   * namespace declaration is variable
@@ -7083,7 +7083,7 @@ SBase::hasRequiredElements() const
 int
 SBase::checkCompatibility(const SBase * object) const
 {
-  if (object == NULL)
+  if (object == 0)
   {
     return LIBSBML_OPERATION_FAILED;
   }
@@ -7119,7 +7119,7 @@ SBase::removeDuplicateAnnotations()
     "http://www.sbml.org/libsbml/annotation", "");
   XMLAttributes att = XMLAttributes();
   XMLToken token = XMLToken(triple, att, xmlns);
-  XMLNode * newNode = NULL;
+  XMLNode * newNode = 0;
   if (isSetAnnotation())
   {
     //make a copy to work with
@@ -7140,7 +7140,7 @@ SBase::removeDuplicateAnnotations()
         {
           resetNecessary = true;
           duplicate = true;
-          if (newNode == NULL)
+          if (newNode == 0)
           {
             // need to  create the new node
             newNode = new XMLNode(token);
@@ -7189,7 +7189,7 @@ SBase::setSBaseFields (const XMLToken& element)
   }
   else
   {
-    setNamespaces(NULL);
+    setNamespaces(0);
   }
 }
 /** @endcond */
@@ -7268,13 +7268,13 @@ SBase::updateSBMLNamespace(const std::string& package,
         getVersion());
     std::string currentSBMLCorePrefix = "";
 
-    if (mSBMLNamespaces == NULL)
+    if (mSBMLNamespaces == 0)
     {
       mSBMLNamespaces = new SBMLNamespaces(level, version);
     }
 
 
-    if (mSBMLNamespaces->getNamespaces() != NULL && 
+    if (mSBMLNamespaces->getNamespaces() != 0 && 
       mSBMLNamespaces->getNamespaces()->getLength() > 0)
     {
       currentSBMLCorePrefix = mSBMLNamespaces->getNamespaces()->
@@ -7372,7 +7372,7 @@ LIBSBML_EXTERN
 int
 SBase_addCVTerm(SBase_t *sb, CVTerm_t *term)
 {
-  return (sb != NULL) ? sb->addCVTerm(term) : LIBSBML_INVALID_OBJECT;
+  return (sb != 0) ? sb->addCVTerm(term) : LIBSBML_INVALID_OBJECT;
 }
 
 
@@ -7380,7 +7380,7 @@ LIBSBML_EXTERN
 int
 SBase_addCVTermNewBag(SBase_t *sb, CVTerm_t *term)
 {
-  return (sb != NULL) ? sb->addCVTerm(term, true) : LIBSBML_INVALID_OBJECT;
+  return (sb != 0) ? sb->addCVTerm(term, true) : LIBSBML_INVALID_OBJECT;
 }
 
 
@@ -7388,7 +7388,7 @@ LIBSBML_EXTERN
 List_t*
 SBase_getCVTerms(SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getCVTerms() : 0;
+  return (sb != 0) ? sb->getCVTerms() : 0;
 }
 
 
@@ -7396,21 +7396,21 @@ LIBSBML_EXTERN
 unsigned int
 SBase_getNumCVTerms(SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getNumCVTerms() : SBML_INT_MAX;
+  return (sb != 0) ? sb->getNumCVTerms() : SBML_INT_MAX;
 }
 
 LIBSBML_EXTERN
 CVTerm_t*
 SBase_getCVTerm(SBase_t *sb, unsigned int n)
 {
-  return (sb != NULL) ? static_cast <CVTerm_t *> (sb->getCVTerm(n)) : NULL;
+  return (sb != 0) ? static_cast <CVTerm_t *> (sb->getCVTerm(n)) : 0;
 }
 
 LIBSBML_EXTERN
 int
 SBase_unsetCVTerms(SBase_t *sb)
 {
-  return (sb != NULL) ? sb->unsetCVTerms() : LIBSBML_INVALID_OBJECT;
+  return (sb != 0) ? sb->unsetCVTerms() : LIBSBML_INVALID_OBJECT;
 }
 
 
@@ -7418,14 +7418,14 @@ LIBSBML_EXTERN
 ModelHistory_t *
 SBase_getModelHistory(SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getModelHistory() : NULL;
+  return (sb != 0) ? sb->getModelHistory() : 0;
 }
 
 LIBSBML_EXTERN
 int
 SBase_isSetModelHistory(SBase_t *sb)
 {
-  return (sb != NULL) ? static_cast<int>( sb->isSetModelHistory() ) : 0;
+  return (sb != 0) ? static_cast<int>( sb->isSetModelHistory() ) : 0;
 }
 
 
@@ -7433,14 +7433,14 @@ LIBSBML_EXTERN
 int
 SBase_setModelHistory(SBase_t *sb, ModelHistory_t *history)
 {
-  return (sb != NULL) ? sb->setModelHistory(history) : LIBSBML_INVALID_OBJECT;
+  return (sb != 0) ? sb->setModelHistory(history) : LIBSBML_INVALID_OBJECT;
 }
 
 LIBSBML_EXTERN
 int
 SBase_unsetModelHistory(SBase_t *sb)
 {
-  return (sb != NULL) ? sb->unsetModelHistory() : LIBSBML_INVALID_OBJECT;
+  return (sb != 0) ? sb->unsetModelHistory() : LIBSBML_INVALID_OBJECT;
 }
 
 
@@ -7448,8 +7448,8 @@ LIBSBML_EXTERN
 BiolQualifierType_t
 SBase_getResourceBiologicalQualifier(SBase_t *sb, const char * resource)
 {
-  if (sb != NULL)
-    return (resource != NULL) ?
+  if (sb != 0)
+    return (resource != 0) ?
     sb->getResourceBiologicalQualifier(resource) : BQB_UNKNOWN;
   else
     return BQB_UNKNOWN;
@@ -7460,8 +7460,8 @@ LIBSBML_EXTERN
 ModelQualifierType_t
 SBase_getResourceModelQualifier(SBase_t *sb, const char * resource)
 {
-  if (sb != NULL)
-    return (resource != NULL) ?
+  if (sb != 0)
+    return (resource != 0) ?
     sb->getResourceModelQualifier(resource) : BQM_UNKNOWN;
   else
     return BQM_UNKNOWN;
@@ -7472,7 +7472,7 @@ LIBSBML_EXTERN
 const char *
 SBase_getMetaId (SBase_t *sb)
 {
-  return (sb != NULL && sb->isSetMetaId()) ? sb->getMetaId().c_str() : NULL;
+  return (sb != 0 && sb->isSetMetaId()) ? sb->getMetaId().c_str() : 0;
 }
 
 
@@ -7480,7 +7480,7 @@ LIBSBML_EXTERN
 const char *
 SBase_getIdAttribute (const SBase_t *sb)
 {
-  return (sb != NULL && sb->isSetIdAttribute()) ? sb->getIdAttribute().c_str() : NULL;
+  return (sb != 0 && sb->isSetIdAttribute()) ? sb->getIdAttribute().c_str() : 0;
 }
 
 
@@ -7488,7 +7488,7 @@ LIBSBML_EXTERN
 const char *
 SBase_getName (const SBase_t *sb)
 {
-  return (sb != NULL && sb->isSetName()) ? sb->getName().c_str() : NULL;
+  return (sb != 0 && sb->isSetName()) ? sb->getName().c_str() : 0;
 }
 
 
@@ -7496,7 +7496,7 @@ LIBSBML_EXTERN
 const SBMLDocument_t *
 SBase_getSBMLDocument (SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getSBMLDocument() : NULL;
+  return (sb != 0) ? sb->getSBMLDocument() : 0;
 }
 
 
@@ -7504,7 +7504,7 @@ LIBSBML_EXTERN
 const SBase_t *
 SBase_getParentSBMLObject (SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getParentSBMLObject() : NULL;
+  return (sb != 0) ? sb->getParentSBMLObject() : 0;
 }
 
 
@@ -7512,7 +7512,7 @@ LIBSBML_EXTERN
 const SBase_t *
 SBase_getAncestorOfType (SBase_t *sb, int type, const char* pkgName)
 {
-  return (sb != NULL) ? sb->getAncestorOfType(type, pkgName) : NULL;
+  return (sb != 0) ? sb->getAncestorOfType(type, pkgName) : 0;
 }
 
 
@@ -7520,7 +7520,7 @@ LIBSBML_EXTERN
 int
 SBase_getSBOTerm (const SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getSBOTerm() : SBML_INT_MAX;
+  return (sb != 0) ? sb->getSBOTerm() : SBML_INT_MAX;
 }
 
 
@@ -7528,8 +7528,8 @@ LIBSBML_EXTERN
 char*
 SBase_getSBOTermID (const SBase_t *sb)
 {
-  return (sb != NULL && sb->isSetSBOTerm())?
-    safe_strdup(sb->getSBOTermID().c_str()) : NULL;
+  return (sb != 0 && sb->isSetSBOTerm())?
+    safe_strdup(sb->getSBOTermID().c_str()) : 0;
 }
 
 
@@ -7537,8 +7537,8 @@ LIBSBML_EXTERN
 char*
 SBase_getSBOTermAsURL (const SBase_t *sb)
 {
-  return (sb != NULL && sb->isSetSBOTerm())?
-    safe_strdup(sb->getSBOTermAsURL().c_str()) : NULL;
+  return (sb != 0 && sb->isSetSBOTerm())?
+    safe_strdup(sb->getSBOTermAsURL().c_str()) : 0;
 }
 
 
@@ -7546,7 +7546,7 @@ LIBSBML_EXTERN
 unsigned int
 SBase_getLevel (const SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getLevel() : SBML_INT_MAX;
+  return (sb != 0) ? sb->getLevel() : SBML_INT_MAX;
 }
 
 
@@ -7554,7 +7554,7 @@ LIBSBML_EXTERN
 unsigned int
 SBase_getVersion (const SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getVersion() : SBML_INT_MAX;
+  return (sb != 0) ? sb->getVersion() : SBML_INT_MAX;
 }
 
 
@@ -7562,7 +7562,7 @@ LIBSBML_EXTERN
 XMLNode_t *
 SBase_getNotes (SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getNotes() : NULL;
+  return (sb != 0) ? sb->getNotes() : 0;
 }
 
 
@@ -7570,8 +7570,8 @@ LIBSBML_EXTERN
 char*
 SBase_getNotesString (SBase_t *sb)
 {
-  return (sb != NULL && sb->isSetNotes()) ?
-    safe_strdup(sb->getNotesString().c_str()) : NULL;
+  return (sb != 0 && sb->isSetNotes()) ?
+    safe_strdup(sb->getNotesString().c_str()) : 0;
 }
 
 
@@ -7579,7 +7579,7 @@ LIBSBML_EXTERN
 XMLNode_t *
 SBase_getAnnotation (SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getAnnotation() : NULL;
+  return (sb != 0) ? sb->getAnnotation() : 0;
 }
 
 
@@ -7587,8 +7587,8 @@ LIBSBML_EXTERN
 char*
 SBase_getAnnotationString (SBase_t *sb)
 {
-  return (sb != NULL && sb->isSetAnnotation()) ?
-    safe_strdup(sb->getAnnotationString().c_str()) : NULL;
+  return (sb != 0 && sb->isSetAnnotation()) ?
+    safe_strdup(sb->getAnnotationString().c_str()) : 0;
 }
 
 
@@ -7596,7 +7596,7 @@ LIBSBML_EXTERN
 int
 SBase_isSetMetaId (const SBase_t *sb)
 {
-  return (sb != NULL) ? static_cast<int>( sb->isSetMetaId() ) : 0;
+  return (sb != 0) ? static_cast<int>( sb->isSetMetaId() ) : 0;
 }
 
 
@@ -7604,7 +7604,7 @@ LIBSBML_EXTERN
 int
 SBase_isSetIdAttribute (const SBase_t *sb)
 {
-  return (sb != NULL) ? static_cast<int>( sb->isSetIdAttribute() ) : 0;
+  return (sb != 0) ? static_cast<int>( sb->isSetIdAttribute() ) : 0;
 }
 
 
@@ -7612,7 +7612,7 @@ LIBSBML_EXTERN
 int
 SBase_isSetName (const SBase_t *sb)
 {
-  return (sb != NULL) ? static_cast<int>( sb->isSetName() ) : 0;
+  return (sb != 0) ? static_cast<int>( sb->isSetName() ) : 0;
 }
 
 
@@ -7620,7 +7620,7 @@ LIBSBML_EXTERN
 int
 SBase_isSetNotes (const SBase_t *sb)
 {
-  return (sb != NULL) ? static_cast<int>( sb->isSetNotes() ) : 0;
+  return (sb != 0) ? static_cast<int>( sb->isSetNotes() ) : 0;
 }
 
 
@@ -7628,7 +7628,7 @@ LIBSBML_EXTERN
 int
 SBase_isSetAnnotation (const SBase_t *sb)
 {
-  return (sb != NULL) ? static_cast<int>( sb->isSetAnnotation() ) : 0;
+  return (sb != 0) ? static_cast<int>( sb->isSetAnnotation() ) : 0;
 }
 
 
@@ -7636,7 +7636,7 @@ LIBSBML_EXTERN
 int
 SBase_isSetSBOTerm (const SBase_t *sb)
 {
-  return (sb != NULL) ? static_cast<int>( sb->isSetSBOTerm() ) : 0;
+  return (sb != 0) ? static_cast<int>( sb->isSetSBOTerm() ) : 0;
 }
 
 
@@ -7644,8 +7644,8 @@ LIBSBML_EXTERN
 int
 SBase_setMetaId (SBase_t *sb, const char *metaid)
 {
-  if (sb != NULL)
-    return (metaid == NULL) ? sb->unsetMetaId() : sb->setMetaId(metaid);
+  if (sb != 0)
+    return (metaid == 0) ? sb->unsetMetaId() : sb->setMetaId(metaid);
   else
     return LIBSBML_INVALID_OBJECT;
 }
@@ -7655,8 +7655,8 @@ LIBSBML_EXTERN
 int
 SBase_setIdAttribute (SBase_t *sb, const char *id)
 {
-  if (sb != NULL)
-    return (id == NULL) ? sb->unsetIdAttribute() : sb->setIdAttribute(id);
+  if (sb != 0)
+    return (id == 0) ? sb->unsetIdAttribute() : sb->setIdAttribute(id);
   else
     return LIBSBML_INVALID_OBJECT;
 }
@@ -7666,8 +7666,8 @@ LIBSBML_EXTERN
 int
 SBase_setName (SBase_t *sb, const char *name)
 {
-  if (sb != NULL)
-    return (name == NULL) ? sb->unsetName() : sb->setName(name);
+  if (sb != 0)
+    return (name == 0) ? sb->unsetName() : sb->setName(name);
   else
     return LIBSBML_INVALID_OBJECT;
 }
@@ -7677,7 +7677,7 @@ LIBSBML_EXTERN
 int
 SBase_setSBOTerm (SBase_t *sb, int value)
 {
-  if (sb != NULL)
+  if (sb != 0)
     return sb->setSBOTerm(value);
   else
     return LIBSBML_INVALID_OBJECT;
@@ -7688,7 +7688,7 @@ LIBSBML_EXTERN
 int
 SBase_setSBOTermID (SBase_t *sb, const char* sboid)
 {
-  if (sb != NULL)
+  if (sb != 0)
     return sb->setSBOTerm(sboid);
   else
     return LIBSBML_INVALID_OBJECT;
@@ -7699,7 +7699,7 @@ LIBSBML_EXTERN
 int
 SBase_setNamespaces (SBase_t *sb, XMLNamespaces_t *xmlns)
 {
-  if (sb != NULL)
+  if (sb != 0)
     return sb->setNamespaces(xmlns);
   else
     return LIBSBML_INVALID_OBJECT;
@@ -7710,7 +7710,7 @@ LIBSBML_EXTERN
 int
 SBase_setNotes (SBase_t *sb, const XMLNode_t *notes)
 {
-  if (sb != NULL)
+  if (sb != 0)
     return sb->setNotes(notes);
   else
     return LIBSBML_INVALID_OBJECT;
@@ -7721,9 +7721,9 @@ LIBSBML_EXTERN
 int
 SBase_setNotesString (SBase_t *sb, const char *notes)
 {
-  if (sb != NULL)
+  if (sb != 0)
   {
-    if(notes == NULL)
+    if(notes == 0)
     {
       return sb->unsetNotes();
     }
@@ -7741,9 +7741,9 @@ LIBSBML_EXTERN
 int
 SBase_setNotesStringAddMarkup (SBase_t *sb, const char *notes)
 {
-  if (sb != NULL)
+  if (sb != 0)
   {
-    if(notes == NULL)
+    if(notes == 0)
     {
       return sb->unsetNotes();
     }
@@ -7761,7 +7761,7 @@ LIBSBML_EXTERN
 int
 SBase_appendNotes (SBase_t *sb, const XMLNode_t *notes)
 {
-  if (sb != NULL)
+  if (sb != 0)
     return sb->appendNotes(notes);
   else
     return LIBSBML_INVALID_OBJECT;
@@ -7772,9 +7772,9 @@ LIBSBML_EXTERN
 int
 SBase_appendNotesString (SBase_t *sb, const char *notes)
 {
-  if (sb != NULL)
+  if (sb != 0)
   {
-    if (notes != NULL)
+    if (notes != 0)
       return sb->appendNotes(notes);
     else
       return LIBSBML_INVALID_OBJECT;
@@ -7788,7 +7788,7 @@ LIBSBML_EXTERN
 int
 SBase_setAnnotation (SBase_t *sb, const XMLNode_t *annotation)
 {
-  if (sb != NULL)
+  if (sb != 0)
     return sb->setAnnotation(annotation);
   else
     return LIBSBML_INVALID_OBJECT;
@@ -7799,9 +7799,9 @@ LIBSBML_EXTERN
 int
 SBase_setAnnotationString (SBase_t *sb, const char *annotation)
 {
-  if (sb != NULL)
+  if (sb != 0)
   {
-    if(annotation == NULL)
+    if(annotation == 0)
     {
       return sb->unsetAnnotation();
     }
@@ -7819,7 +7819,7 @@ LIBSBML_EXTERN
 int
 SBase_appendAnnotation (SBase_t *sb, const XMLNode_t *annotation)
 {
-  if (sb != NULL)
+  if (sb != 0)
     return sb->appendAnnotation(annotation);
   else
     return LIBSBML_INVALID_OBJECT;
@@ -7830,9 +7830,9 @@ LIBSBML_EXTERN
 int
 SBase_appendAnnotationString (SBase_t *sb, const char *annotation)
 {
-  if (sb != NULL)
+  if (sb != 0)
   {
-    if (annotation != NULL)
+    if (annotation != 0)
       return sb->appendAnnotation(annotation);
     else
       return LIBSBML_INVALID_OBJECT;
@@ -7845,9 +7845,9 @@ LIBSBML_EXTERN
 int
 SBase_removeTopLevelAnnotationElement (SBase_t *sb, const char *name)
 {
-  if (sb != NULL)
+  if (sb != 0)
   {
-    if (name != NULL)
+    if (name != 0)
       return sb->removeTopLevelAnnotationElement(name);
     else
       return LIBSBML_INVALID_OBJECT;
@@ -7862,9 +7862,9 @@ int
 SBase_removeTopLevelAnnotationElementWithURI (SBase_t *sb, const char *name,
                                               const char *uri)
 {
-  if (sb != NULL)
+  if (sb != 0)
   {
-    if (name != NULL && uri != NULL)
+    if (name != 0 && uri != 0)
       return sb->removeTopLevelAnnotationElement(name, uri);
     else
       return LIBSBML_INVALID_OBJECT;
@@ -7878,9 +7878,9 @@ LIBSBML_EXTERN
 int
 SBase_replaceTopLevelAnnotationElement (SBase_t *sb, const XMLNode_t *annotation)
 {
-  if (sb != NULL)
+  if (sb != 0)
   {
-    if (annotation != NULL)
+    if (annotation != 0)
       return sb->replaceTopLevelAnnotationElement(annotation);
     else
       return LIBSBML_INVALID_OBJECT;
@@ -7894,9 +7894,9 @@ LIBSBML_EXTERN
 int
 SBase_replaceTopLevelAnnotationElementString (SBase_t *sb, const char *annotation)
 {
-  if (sb != NULL)
+  if (sb != 0)
   {
-    if (annotation != NULL)
+    if (annotation != 0)
       return sb->replaceTopLevelAnnotationElement(annotation);
     else
       return LIBSBML_INVALID_OBJECT;
@@ -7910,7 +7910,7 @@ LIBSBML_EXTERN
 int
 SBase_unsetMetaId (SBase_t *sb)
 {
-  if (sb != NULL)
+  if (sb != 0)
     return sb->unsetMetaId();
   else
     return LIBSBML_INVALID_OBJECT;
@@ -7921,7 +7921,7 @@ LIBSBML_EXTERN
 int
 SBase_unsetIdAttribute (SBase_t *sb)
 {
-  if (sb != NULL)
+  if (sb != 0)
     return sb->unsetIdAttribute();
   else
     return LIBSBML_INVALID_OBJECT;
@@ -7932,7 +7932,7 @@ LIBSBML_EXTERN
 int
 SBase_unsetName (SBase_t *sb)
 {
-  if (sb != NULL)
+  if (sb != 0)
     return sb->unsetName();
   else
     return LIBSBML_INVALID_OBJECT;
@@ -7943,7 +7943,7 @@ LIBSBML_EXTERN
 int
 SBase_unsetNotes (SBase_t *sb)
 {
-  if (sb != NULL)
+  if (sb != 0)
     return sb->unsetNotes();
   else
     return LIBSBML_INVALID_OBJECT;
@@ -7954,7 +7954,7 @@ LIBSBML_EXTERN
 int
 SBase_unsetAnnotation (SBase_t *sb)
 {
-  if (sb != NULL)
+  if (sb != 0)
     return sb->unsetAnnotation();
   else
     return LIBSBML_INVALID_OBJECT;
@@ -7965,7 +7965,7 @@ LIBSBML_EXTERN
 int
 SBase_unsetSBOTerm (SBase_t *sb)
 {
-  if (sb != NULL)
+  if (sb != 0)
     return sb->unsetSBOTerm();
   else
     return LIBSBML_INVALID_OBJECT;
@@ -7976,14 +7976,14 @@ LIBSBML_EXTERN
 const Model_t *
 SBase_getModel (const SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getModel() : NULL;
+  return (sb != 0) ? sb->getModel() : 0;
 }
 
 LIBSBML_EXTERN
 int
 SBase_getTypeCode (const SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getTypeCode() : SBML_UNKNOWN;
+  return (sb != 0) ? sb->getTypeCode() : SBML_UNKNOWN;
 }
 
 
@@ -7991,8 +7991,8 @@ LIBSBML_EXTERN
 const char *
 SBase_getElementName (const SBase_t *sb)
 {
-  return (sb != NULL && !(sb->getElementName().empty())) ?
-    sb->getElementName().c_str() : NULL;
+  return (sb != 0 && !(sb->getElementName().empty())) ?
+    sb->getElementName().c_str() : 0;
 }
 
 
@@ -8000,7 +8000,7 @@ LIBSBML_EXTERN
 char *
 SBase_getPackageName(const SBaseExtensionPoint_t *sb)
 {
-  if (sb == NULL) return NULL;
+  if (sb == 0) return 0;
   return safe_strdup(sb->getPackageName().c_str());
 }
 
@@ -8009,7 +8009,7 @@ LIBSBML_EXTERN
 unsigned int
 SBase_getLine (const SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getLine() : 0;
+  return (sb != 0) ? sb->getLine() : 0;
 }
 
 
@@ -8017,7 +8017,7 @@ LIBSBML_EXTERN
 unsigned int
 SBase_getColumn (const SBase_t *sb)
 {
-  return (sb != NULL) ? sb->getColumn() : 0;
+  return (sb != 0) ? sb->getColumn() : 0;
 }
 
 
@@ -8025,7 +8025,7 @@ LIBSBML_EXTERN
 int
 SBase_hasValidLevelVersionNamespaceCombination(SBase_t *sb)
 {
-  return (sb != NULL) ?
+  return (sb != 0) ?
     static_cast <int> (sb->hasValidLevelVersionNamespaceCombination()) : 0;
 }
 
@@ -8034,7 +8034,7 @@ LIBSBML_EXTERN
 int
 SBase_getNumPlugins(const SBase_t *sb)
 {
-  return (sb != NULL) ? (int)sb->getNumPlugins() : 0;
+  return (sb != 0) ? (int)sb->getNumPlugins() : 0;
 }
 
 
@@ -8042,14 +8042,14 @@ LIBSBML_EXTERN
 SBasePlugin_t*
 SBase_getPlugin(SBase_t *sb, const char *package)
 {
-  return (sb != NULL) ? sb->getPlugin(package) : NULL;
+  return (sb != 0) ? sb->getPlugin(package) : 0;
 }
 
 LIBSBML_EXTERN
 int
 SBase_setUserData(SBase_t* sb, void *userData)
 {
-  if (sb == NULL) return LIBSBML_INVALID_OBJECT;
+  if (sb == 0) return LIBSBML_INVALID_OBJECT;
   return sb->setUserData(userData);
 }
 
@@ -8058,7 +8058,7 @@ LIBSBML_EXTERN
 void *
 SBase_getUserData(const SBase_t* sb)
 {
-  if (sb == NULL) return NULL;
+  if (sb == 0) return 0;
   return sb->getUserData();
 }
 
@@ -8066,7 +8066,7 @@ LIBSBML_EXTERN
 int
 SBase_isSetUserData(const SBase_t* sb)
 {
-  if (sb == NULL) return 0;
+  if (sb == 0) return 0;
   return static_cast <int>(sb->isSetUserData());
 }
 
@@ -8074,7 +8074,7 @@ LIBSBML_EXTERN
 int
 SBase_unsetUserData(SBase_t* sb)
 {
-  if (sb == NULL) return LIBSBML_INVALID_OBJECT;
+  if (sb == 0) return LIBSBML_INVALID_OBJECT;
   return sb->unsetUserData();
 }
 
@@ -8082,7 +8082,7 @@ LIBSBML_EXTERN
 SBase_t*
 SBase_getElementBySId(SBase_t* sb, const char* id)
 {
-  if (sb == NULL) return NULL;
+  if (sb == 0) return 0;
   return sb->getElementBySId(id);
 }
 
@@ -8090,7 +8090,7 @@ LIBSBML_EXTERN
 SBase_t*
 SBase_getElementByMetaId(SBase_t* sb, const char* metaid)
 {
-  if (sb == NULL) return NULL;
+  if (sb == 0) return 0;
   return sb->getElementByMetaId(metaid);
 }
 
@@ -8098,7 +8098,7 @@ LIBSBML_EXTERN
 List_t*
 SBase_getAllElements(SBase_t* sb)
 {
-  if (sb == NULL) return NULL;
+  if (sb == 0) return 0;
   return sb->getAllElements();
 }
 
@@ -8106,7 +8106,7 @@ LIBSBML_EXTERN
 void
 SBase_renameSIdRefs(SBase_t* sb, const char* oldid, const char* newid)
 {
-  if (sb == NULL) return;
+  if (sb == 0) return;
   return sb->renameSIdRefs(oldid, newid);
 }
 
@@ -8114,7 +8114,7 @@ LIBSBML_EXTERN
 void
 SBase_renameMetaIdRefs(SBase_t* sb, const char* oldid, const char* newid)
 {
-  if (sb == NULL) return;
+  if (sb == 0) return;
   return sb->renameMetaIdRefs(oldid, newid);
 }
 
@@ -8122,7 +8122,7 @@ LIBSBML_EXTERN
 void
 SBase_renameUnitSIdRefs(SBase_t* sb, const char* oldid, const char* newid)
 {
-  if (sb == NULL) return;
+  if (sb == 0) return;
   return sb->renameUnitSIdRefs(oldid, newid);
 }
 
@@ -8130,7 +8130,7 @@ LIBSBML_EXTERN
 SBase_t*
 SBase_getElementFromPluginsBySId(SBase_t* sb, const char* id)
 {
-  if (sb == NULL) return NULL;
+  if (sb == 0) return 0;
   return sb->getElementFromPluginsBySId(id);
 }
 
@@ -8138,7 +8138,7 @@ LIBSBML_EXTERN
 SBase_t*
 SBase_getElementFromPluginsByMetaId(SBase_t* sb, const char* metaid)
 {
-  if (sb == NULL) return NULL;
+  if (sb == 0) return 0;
   return sb->getElementFromPluginsByMetaId(metaid);
 }
 
@@ -8146,7 +8146,7 @@ LIBSBML_EXTERN
 List_t*
 SBase_getAllElementsFromPlugins(SBase_t* sb)
 {
-  if (sb == NULL) return NULL;
+  if (sb == 0) return 0;
   return sb->getAllElementsFromPlugins();
 }
 /** @endcond */
