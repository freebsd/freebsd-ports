--- src/ixlib_re_impl.hh.orig	Fri Nov 28 11:43:40 2003
+++ src/ixlib_re_impl.hh	Fri Nov 28 12:55:23 2003
@@ -38,7 +38,7 @@
 
 
 template<class T>
-ixion::regex<T>::backref_stack::rewind_info 
+typename ixion::regex<T>::backref_stack::rewind_info 
 ixion::regex<T>::backref_stack::getRewindInfo() const {
   return Stack.size();
   }
@@ -65,7 +65,7 @@
 template<class T>
 ixion::TSize ixion::regex<T>::backref_stack::size() {
   TSize result = 0;
-  FOREACH_CONST(first,Stack,internal_stack)
+  FOREACH_CONST_T(first,Stack,internal_stack)
     if (first->Type == backref_entry::OPEN) result++;
   return result;
   }
@@ -79,7 +79,7 @@
   TIndex start;
   TIndex startlevel;
   
-  internal_stack::const_iterator first = Stack.begin(),last = Stack.end();
+  typename internal_stack::const_iterator first = Stack.begin(),last = Stack.end();
   while (first != last) {
     if (first->Type == backref_entry::OPEN) {
       if (number == next_index) {
@@ -201,7 +201,7 @@
 
 
 template<class T>
-ixion::regex<T>::matcher *ixion::regex<T>::quantifier::duplicate() const {
+typename ixion::regex<T>::matcher *ixion::regex<T>::quantifier::duplicate() const {
   quantifier *dupe = new quantifier();
   dupe->copy(this);
   return dupe;
@@ -328,7 +328,7 @@
 
 
 template<class T>
-ixion::regex<T>::matcher *ixion::regex<T>::sequence_matcher::duplicate() const {
+typename ixion::regex<T>::matcher *ixion::regex<T>::sequence_matcher::duplicate() const {
   sequence_matcher *dupe = new sequence_matcher(MatchStr);
   dupe->copy(this);
   return dupe;
@@ -349,7 +349,7 @@
 
 // regex::any_matcher ---------------------------------------------------------
 template<class T>
-ixion::regex<T>::matcher *ixion::regex<T>::any_matcher::duplicate() const {
+typename ixion::regex<T>::matcher *ixion::regex<T>::any_matcher::duplicate() const {
   any_matcher *dupe = new any_matcher();
   dupe->copy(this);
   return dupe;
@@ -360,7 +360,7 @@
 
 // regex::start_matcher ---------------------------------------------------------
 template<class T>
-ixion::regex<T>::matcher *ixion::regex<T>::start_matcher::duplicate() const {
+typename ixion::regex<T>::matcher *ixion::regex<T>::start_matcher::duplicate() const {
   start_matcher *dupe = new start_matcher();
   dupe->copy(this);
   return dupe;
@@ -379,7 +379,7 @@
 
 // regex::end_matcher ---------------------------------------------------------
 template<class T>
-ixion::regex<T>::matcher *ixion::regex<T>::end_matcher::duplicate() const {
+typename ixion::regex<T>::matcher *ixion::regex<T>::end_matcher::duplicate() const {
   end_matcher *dupe = new end_matcher();
   dupe->copy(this);
   return dupe;
@@ -398,7 +398,7 @@
 
 // regex::backref_open_matcher ------------------------------------------------
 template<class T>
-ixion::regex<T>::matcher *ixion::regex<T>::backref_open_matcher::duplicate() const {
+typename ixion::regex<T>::matcher *ixion::regex<T>::backref_open_matcher::duplicate() const {
   backref_open_matcher *dupe = new backref_open_matcher();
   dupe->copy(this);
   return dupe;
@@ -409,7 +409,7 @@
 
 template<class T>
 bool ixion::regex<T>::backref_open_matcher::match(backref_stack &brstack,T const &candidate,TIndex at) {
-  backref_stack::rewind_info ri = brstack.getRewindInfo();
+  typename backref_stack::rewind_info ri = brstack.getRewindInfo();
   brstack.open(at);
   
   bool result = matchNext(brstack,candidate,at);
@@ -424,7 +424,7 @@
 
 // regex::backref_close_matcher -----------------------------------------------
 template<class T>
-ixion::regex<T>::matcher *ixion::regex<T>::backref_close_matcher::duplicate() const {
+typename ixion::regex<T>::matcher *ixion::regex<T>::backref_close_matcher::duplicate() const {
   backref_close_matcher *dupe = new backref_close_matcher();
   dupe->copy(this);
   return dupe;
@@ -435,7 +435,7 @@
 
 template<class T>
 bool ixion::regex<T>::backref_close_matcher::match(backref_stack &brstack,T const &candidate,TIndex at) {
-  backref_stack::rewind_info ri = brstack.getRewindInfo();
+  typename backref_stack::rewind_info ri = brstack.getRewindInfo();
   brstack.close(at);
   
   bool result = matchNext(brstack,candidate,at);
@@ -470,7 +470,7 @@
 
 
 template<class T>
-ixion::regex<T>::matcher *ixion::regex<T>::alternative_matcher::duplicate() const {
+typename ixion::regex<T>::matcher *ixion::regex<T>::alternative_matcher::duplicate() const {
   alternative_matcher *dupe = new alternative_matcher();
   dupe->copy(this);
   return dupe;
@@ -484,7 +484,7 @@
   TSize result = 0;
   bool is_first = true;
   
-  FOREACH_CONST(first,AltList,alt_list)
+  FOREACH_CONST_T(first,AltList,alt_list)
     if (is_first) {
       result = (*first)->minimumMatchLength();
       is_first = true;
@@ -500,7 +500,7 @@
 
 
 template<class T>
-void ixion::regex<T>::alternative_matcher::setNext(matcher *next,bool ownnext = true) {
+void ixion::regex<T>::alternative_matcher::setNext(matcher *next,bool ownnext) {
   matcher::setNext(next);
   Connector.setNext(next,false);
   }
@@ -524,7 +524,7 @@
 
 template<class T>
 bool ixion::regex<T>::alternative_matcher::match(backref_stack &brstack,T const &candidate,TIndex at) {
-  std::vector<matcher *>::iterator first = AltList.begin(),last = AltList.end();
+  typename std::vector<matcher *>::iterator first = AltList.begin(),last = AltList.end();
   while (first != last) {
     if ((*first)->match(brstack,candidate,at)) {
       MatchLength = 0;
@@ -548,7 +548,7 @@
   super::copy(src);
   Connector.setNext(Next,false);
   
-  FOREACH_CONST(first,src->AltList,alt_list)
+  FOREACH_CONST_T(first,src->AltList,alt_list)
     addAlternative((*first)->duplicate());
   }
 
@@ -565,7 +565,7 @@
 
 
 template<class T>
-ixion::regex<T>::matcher *ixion::regex<T>::backref_matcher::duplicate() const {
+typename ixion::regex<T>::matcher *ixion::regex<T>::backref_matcher::duplicate() const {
   backref_matcher *dupe = new backref_matcher(Backref);
   dupe->copy(this);
   return dupe;
