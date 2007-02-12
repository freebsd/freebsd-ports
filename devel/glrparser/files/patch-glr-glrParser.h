--- glr/glrParser.h.orig	Wed Mar 26 15:26:15 2003
+++ glr/glrParser.h	Thu Dec 23 16:27:38 2004
@@ -502,7 +502,7 @@
 glrParser<glrNodeType,glrStateType>::printTable
 (ostream &output){
   output << states.size() << endl;
-  for(vector<glrStateType*>::iterator i=states.begin();i!=states.end();++i) {
+  for(typename vector<glrStateType*>::iterator i=states.begin();i!=states.end();++i) {
     if(*i){
       (*i)->print(symbols,output);
     }else{
@@ -635,7 +635,7 @@
   }
 
 
-  for(deque<glrStateType*>::iterator state=activeStates.begin();state!=activeStates.end();++state){
+  for(typename deque<glrStateType*>::iterator state=activeStates.begin();state!=activeStates.end();++state){
     (*state)->stack->release();
     (*state)->stack=NULL;
     (*state)->crossEdges.clear();
@@ -1793,7 +1793,7 @@
     }
 
     for(map<glrSymbolTable::glrSymbol,glrItemSet*>::iterator tran=compState->transitions.begin();tran!=compState->transitions.end();++tran){
-      glrCompStatesMap<glrStateType>::iterator iNextState=compStatesMap.find(tran->second);
+      typename glrCompStatesMap<glrStateType>::iterator iNextState=compStatesMap.find(tran->second);
       if(iNextState==compStatesMap.end()){
 
 	glrStateType *newState=new glrStateType(states.size(),symbols);
@@ -1871,7 +1871,7 @@
 template<class glrNodeType,class glrStateType> void
 glrParser<glrNodeType,glrStateType>::clearTable
 (){
-  for(vector<glrStateType*>::iterator iState=states.begin();iState!=states.end();++iState){
+  for(typename vector<glrStateType*>::iterator iState=states.begin();iState!=states.end();++iState){
     delete (*iState);
   }
   states.clear();
@@ -1892,8 +1892,8 @@
 template<class glrStateType> void
 glrCompStatesMap<glrStateType>::releaseItemSets
 (){
-  for(glrCompStatesMap<glrStateType>::iterator i=begin();i!=end();++i)delete i->first;
-  clear();
+  for(typename glrCompStatesMap<glrStateType>::iterator i=this->begin();i!=this->end();++i)delete i->first;
+  this->clear();
 }
 
 #ifdef CHECK_CONSISTENCY
