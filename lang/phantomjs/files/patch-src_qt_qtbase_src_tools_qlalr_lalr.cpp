--- src/qt/qtbase/src/tools/qlalr/lalr.cpp.orig	2015-01-24 02:19:52 UTC
+++ src/qt/qtbase/src/tools/qlalr/lalr.cpp
@@ -246,11 +246,11 @@ void Grammar::buildExtendedGrammar ()
   non_terminals.insert (accept_symbol);
 }
 
-struct _Nullable: public std::unary_function<Name, bool>
+struct Nullable: public std::unary_function<Name, bool>
 {
   Automaton *_M_automaton;
 
-  _Nullable (Automaton *aut):
+  Nullable (Automaton *aut):
     _M_automaton (aut) {}
 
   bool operator () (Name name) const
@@ -308,7 +308,7 @@ void Automaton::buildNullables ()
 
       for (RulePointer rule = _M_grammar->rules.begin (); rule != _M_grammar->rules.end (); ++rule)
         {
-          NameList::iterator nn = std::find_if (rule->rhs.begin (), rule->rhs.end (), std::not1 (_Nullable (this)));
+          NameList::iterator nn = std::find_if (rule->rhs.begin (), rule->rhs.end (), std::not1 (Nullable (this)));
 
           if (nn == rule->rhs.end ())
             changed |= nullables.insert (rule->lhs).second;
@@ -643,7 +643,7 @@ void Automaton::buildIncludesDigraph ()
                   if (! _M_grammar->isNonTerminal (*A))
                     continue;
 
-                  NameList::iterator first_not_nullable = std::find_if (dot, rule->rhs.end (), std::not1 (_Nullable (this)));
+                  NameList::iterator first_not_nullable = std::find_if (dot, rule->rhs.end (), std::not1 (Nullable (this)));
                   if (first_not_nullable != rule->rhs.end ())
                     continue;
 
