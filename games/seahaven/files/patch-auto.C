--- auto.C	Sun Apr 22 09:37:27 2001
+++ auto.C	Tue Aug  6 11:46:09 2002
@@ -1,7 +1,9 @@
-#include <stream.h>
+#include <iostream>
+using namespace std;
 
 #include <string.h>
 #include <stdlib.h>
+#include <err.h>
 
 #include <sys/types.h>
 #include <sys/time.h>
@@ -9,7 +11,7 @@
 #include <fcntl.h>
 //#include <osfcn.h>
 
-//#include <stdlib.h>		// for getenv()
+#include <stdlib.h>		// for getenv()
 
 
 #include "auto.h"
@@ -51,11 +53,6 @@
 
 const int NumRanks = RankLast+1;
 
-void Error(char *s1 = "", char *s2 = "", char *s3 = "") {
-    cerr << "\n" << s1 << s2 << s3 << "\n";
-    exit(-1);
-}
-
 class Tableaux;
 
 inline unsigned short Fold(long l) {
@@ -76,7 +73,7 @@
     unsigned short Short() const { return Fold(l1)^Fold(l2)^Fold(l3); }
     bool EmptyP() const { return (l1 == 0) && (l2 == 0) && (l3 == 0); }
     bool BadP() const { return (l3 < 0); }
-    void Print(ostream &os) const {os<<hex(l1, 8) << hex(l2, 8) << hex(l3,8); }
+    void Print(ostream &os) const {os<<hex<<l1<<hex<<l2<<hex<<l3; }
 };
 
 ostream& operator<< (ostream &os, Hash& h) { h.Print(os); return os; }
@@ -149,7 +146,7 @@
 }
 
 int HashList::Add(const Hash& h) {
-    if (!this) Error("Add to NULL HashList.");
+    if (!this) errx(1, "Add to NULL HashList.");
     if (HashVal().EmptyP()) hash = h;
     else next = new HashList(h, next);
     return depth++;
@@ -184,7 +181,7 @@
     HashList* hll = &ht[size];
     for (HashList* hlt = ht; hlt != hll; hlt++)
 	if (! hlt->EmptyP())
-	    os << "\n" << dec(hlt-ht,5) << ": " << *hlt;
+	    os << "\n" << dec << hlt-ht << ": " << *hlt;
 }
 
 static HashTable hashTable(65536);
@@ -201,8 +198,8 @@
     void MoveTo(CardRange&);
 };
 
-void Dest::MoveTo(Card&) { Error("Dest::MoveTo(Card&)"); }
-void Dest::MoveTo(CardRange&) { Error("Dest::MoveTo(CardRange&)"); }
+void Dest::MoveTo(Card&) { errx(1, "Dest::MoveTo(Card&)"); }
+void Dest::MoveTo(CardRange&) { errx(1, "Dest::MoveTo(CardRange&)"); }
 
 typedef void (Dest::* MoveCardToMemberFunction)(Card&);
 typedef void (Dest::* MoveCardRangeToMemberFunction)(CardRange&);
@@ -214,9 +211,9 @@
   public:
     Card(Suit suit, Rank rank) {
 	if ((suit < SuitFirst) || (suit > SuitLast))
-	    Error("Bad suit ", dec((int)suit), " in Card constructor.");
+	    errx(1, "Bad suit %d in Card constructor.", (int)suit);
 	if ((rank < RankFirst) || (rank > RankLast))
-	    Error("Bad rank ", dec((int)rank), " in Card constructor.");
+	    errx(1, "Bad rank %d in Card constructor.", (int)rank);
 	thisSuit = suit; thisRank = rank; empty = 0;
     }
     Card(char *st);
@@ -248,16 +245,16 @@
 
 void Card::Print(ostream &os) const {
     if (EmptyP()) os << "--";
-    else os << chr(rankName[rank()]) << chr(suitName[suit()]);
+    else os << rankName[rank()] << suitName[suit()];
 }
 
 Card::Card(char* st) {
     char *c;
     c = strchr(suitName, st[1]);
-    if (! c) Error("Bad suit ", chr(st[1]), " in Card string constructor.");
+    if (! c) errx(1, "Bad suit %c in Card string constructor.", st[1]);
     thisSuit = Suit(c-suitName);
     c = strchr(rankName, st[0]);
-    if (! c) Error("Bad rank ", chr(st[0]), " in Card string constructor.");
+    if (! c) errx(1, "Bad rank %c in Card string constructor.", st[0]);
     thisRank = Rank(c - rankName);
     empty = 0;
 }
@@ -275,7 +272,7 @@
     void Init(Card c, CountType count) { thisCard = c; thisCount = count; }
   public:
     CardRange(Suit s, Rank rank1, Rank rank2) {
-	if (rank2 < rank1) Error("rank2 < rank1 in CardRange constructor.");
+	if (rank2 < rank1) errx(1, "rank2 < rank1 in CardRange constructor.");
 	Init(Card(s, rank1), rank2-rank1+1);
     }
     CardRange(Suit s, Rank rank, CountType count = 1) {
@@ -290,7 +287,7 @@
     Card next() const { return thisCard.next(thisCount); }
     CountType Count() const { return thisCount; }
     void Prepend(const CardRange& cr) {
-	if (!cr.nextP(First())) Error("CardRange::Prepend, not next.");
+	if (!cr.nextP(First())) errx(1, "CardRange::Prepend, not next.");
 	thisCount += cr.Count();
 	thisCard = cr.First();
     }
@@ -416,7 +413,7 @@
 };
 
 void Spaces::MoveTo(CardRange& from) { MoveToSpace(from); }
-void Spaces::MoveTo(Card&) { Error("Spaces::MoveTo(Card&)"); }
+void Spaces::MoveTo(Card&) { errx(1, "Spaces::MoveTo(Card&)"); }
 
 const int NumPiles = 10;
 
@@ -484,7 +481,7 @@
     Dest& dest;
   public:
     Move(Dest& d) : dest(d) { }
-    virtual void DoIt() { Error("Move::DoIt()"); };
+    virtual void DoIt() { errx(1, "Move::DoIt()"); };
 };
 
 class MoveCard : public Move {
@@ -569,7 +566,7 @@
     }
 
     if ((l1==0)&&(l2==0)&&(l3==0))
-	Error("Tableaux hashes to NULL.");
+	errx(1, "Tableaux hashes to NULL.");
 }
 
 bool Tableaux::WonP() {
@@ -853,8 +850,9 @@
     for (Suit s = SuitFirst; s <= SuitLast; s = Suit(s+1))
 	for (Rank r = RankFirst; r <= RankLast; r = Rank(r+1))
 	    if (deck[s][r] != 1) {
-		cerr << "\n" << Card(s, r) << " count is " << deck[s][r];
-		Error();
+		cerr << "\n" << Card(s, r) << " count is " << deck[s][r]
+		     << endl;
+		exit(-1);
 	    }
 
     CanonicalForm();
@@ -915,7 +913,7 @@
 #ifdef AUTO
 
 #include <stdio.h>
-#include <fstream.h>
+#include <fstream>
 
 int AutoPlay() {
 
@@ -924,7 +922,7 @@
     sprintf(savefile, "%s/.seahavensave", getenv("HOME"));
 
     ifstream in(savefile, ios::in);
-    if (!in) Error("Can't open", savefile);
+    if (!in) errx(1, "Can't open %s", savefile);
 
     Tableaux t(in);
 
