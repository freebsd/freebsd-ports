--- kaptain/grammar.h.orig	Wed Aug 14 12:17:49 2002
+++ kaptain/grammar.h	Fri Dec 20 16:14:31 2002
@@ -6,7 +6,6 @@
 #include <string>
 #include <map>
 
-using namespace std;
 
 class Grammar;
 class Rule;
@@ -33,12 +32,12 @@
   friend class Intermediate;
 
   Grammar * grammar;
-  list<string *> * modifiers;
-  string textinfo[3];
+  std::list<std::string *> * modifiers;
+  std::string textinfo[3];
   int nonterminal;
 
 public:
-  Description(Grammar *, string *, list<string *> *, string **);
+  Description(Grammar *, std::string *, std::list<std::string *> *, std::string **);
   ~Description();
 };
 
@@ -54,18 +53,18 @@
   Grammar * grammar;
   int type;
   int value;
-  string data;
-  string data2;
+  std::string data;
+  std::string data2;
 
 public: 
   Parameter(Grammar *);
 
   void set_numeral(int);
-  void set_string(string *);
-  void set_nonterminal(string *);
-  void set_regexp(string *);
-  void set_substitution(string **);  
-  void set_transliteration(string **);
+  void set_string(std::string *);
+  void set_nonterminal(std::string *);
+  void set_regexp(std::string *);
+  void set_substitution(std::string **);  
+  void set_transliteration(std::string **);
 
 };
 
@@ -75,18 +74,18 @@
 {
   /* Broker of string<->int transformations */
 
-  vector<string> nonterminal_table;
-  vector<string> terminal_table;
+  std::vector<std::string> nonterminal_table;
+  std::vector<std::string> terminal_table;
 
 public:
 
   Broker();
   ~Broker();
 
-  int get_nonterminal(string *); /* returns the number of a nonterminal */
-  int get_terminal(string *); /* returns the number of a terminal */
+  int get_nonterminal(std::string *); /* returns the number of a nonterminal */
+  int get_terminal(std::string *); /* returns the number of a terminal */
 
-  string get_string(int); /* returns the name of a nonterminal
+  std::string get_string(int); /* returns the name of a nonterminal
                              or the value of a terminal */
 
   int get_nt_num() { return nonterminal_table.size(); }
@@ -103,22 +102,22 @@
 
   Grammar * grammar;
 
-  list<int> symbols;
+  std::list<int> symbols;
   bool is_default;
 
 public:
   Conjunction(Grammar *);
   ~Conjunction();
 
-  void add_nonterminal(string *);
-  void add_terminal(string *);
+  void add_nonterminal(std::string *);
+  void add_terminal(std::string *);
 
   void set_default();
   bool get_default() { return is_default; }
 
-  void add_special(string *, list<Parameter *> *, Parameter *);
+  void add_special(std::string *, std::list<Parameter *> *, Parameter *);
 
-  string evaluate(bool);
+  std::string evaluate(bool);
 
 };
 
@@ -132,7 +131,7 @@
 
   Grammar * grammar;
 
-  list<Conjunction *> conjunctions;
+  std::list<Conjunction *> conjunctions;
   int default_num;
 
 public:
@@ -158,17 +157,17 @@
   Disjunction * disjunction; /* the right hand side */
 
   int type; /* special(>0) or normal(0) */
-  string special_type;
-  list<Parameter *> * parameters; /* parameter list */
+  std::string special_type;
+  std::list<Parameter *> * parameters; /* parameter list */
   Parameter  * initvalue;
-  list<string *> * modifiers;
+  std::list<std::string *> * modifiers;
   int mods; /* modifier bits */
 
   /* textual information for the rule */
-  string textinfo[3];
+  std::string textinfo[3];
 
   /* transformations for the rule */
-  list<Parameter *> * transformations;
+  std::list<Parameter *> * transformations;
 
   Intermediate * my_intermediate;
 
@@ -177,12 +176,12 @@
   Rule(Grammar *);
   ~Rule();
 
-  void set_left(string *);
+  void set_left(std::string *);
   void set_disjunction(Disjunction *);
-  void set_special(string *, list<Parameter *> *, Parameter *);
-  void add_modifiers(list<string *> *);
-  void set_textinfo(string ** ti);
-  void set_transformations(list<Parameter *> *);
+  void set_special(std::string *, std::list<Parameter *> *, Parameter *);
+  void add_modifiers(std::list<std::string *> *);
+  void set_textinfo(std::string ** ti);
+  void set_transformations(std::list<Parameter *> *);
   
   int get_left() { return left; }
   Intermediate * get_intermediate() { return my_intermediate; }
@@ -191,10 +190,10 @@
 
   void verify_rule();
 
-  string evaluate(bool);
+  std::string evaluate(bool);
 
-  void send(string message, bool prefix_sender=true);
-  void recieve(char, string);
+  void send(std::string message, bool prefix_sender=true);
+  void recieve(char, std::string);
 
 };
 
@@ -204,9 +203,9 @@
 {
   friend class Intermediate;
 
-  list<Rule *> rules;
-  multimap<int, int> constraints;
-  list<Description *> descriptions;
+  std::list<Rule *> rules;
+  std::multimap<int, int> constraints;
+  std::list<Description *> descriptions;
   Rule * start_rule;
 
 public:
@@ -217,8 +216,8 @@
   bool was_default_widget_done; // global variable for a Kaptain tree
 
   void add_rule(Rule *);
-  void add_description(string *, list<string *> *, string **);
-  void add_constraint(string *, string *);
+  void add_description(std::string *, std::list<std::string *> *, std::string **);
+  void add_constraint(std::string *, std::string *);
   
   Rule * get_rule(int);
   Rule * get_start_rule() { return start_rule; }
@@ -234,11 +233,11 @@
   void unify_rules();
   void unify_descriptions();
 
-  string evaluate_nonterminal(int, bool);
+  std::string evaluate_nonterminal(int, bool);
   int get_constraint_for(int);
 
-  void send(string);
-  void recieve(string);
+  void send(std::string);
+  void recieve(std::string);
 };
 
 
