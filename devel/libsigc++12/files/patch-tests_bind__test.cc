libc++ doesn't like "using namespace std" in C++11

bind_test.cc:24:17: error: no viable conversion from '__bind<SigC::Slot1<void, int>, int>' to 'Slot0<void>'
    Slot0<void> s=bind(slot(&foo),1);
                ^ ~~~~~~~~~~~~~~~~~~
../sigc++/slot.h:207:7: note: candidate constructor not viable: no known conversion from '__bind<SigC::Slot1<void, int>, int>' to 'const SigC::Slot0<void> &' for 1st argument
      Slot0(const Slot0& s) 
      ^
../sigc++/slot.h:210:7: note: candidate constructor not viable: no known conversion from '__bind<SigC::Slot1<void, int>, int>' to 'SigC::SlotNode *' for 1st argument
      Slot0(SlotNode* node)
      ^
../sigc++/slot.h:213:7: note: candidate constructor not viable: no known conversion from '__bind<SigC::Slot1<void, int>, int>' to 'SigC::Slot0<void>::Callback' (aka 'void (*)()') for 1st argument
      Slot0(Callback callback)
      ^

--- tests/bind_test.cc.orig	2002-10-11 12:42:15 UTC
+++ tests/bind_test.cc
@@ -21,10 +21,10 @@ void foo2(A) { cout << "foo2(A)" <<endl; result+=3;}
 int main()
   {
     cout << ">>test 1"<<endl;
-    Slot0<void> s=bind(slot(&foo),1);
+    Slot0<void> s=SigC::bind(slot(&foo),1);
     s();
     cout << ">>test 2"<<endl;
-    s=bind(slot(&foo2),1);
+    s=SigC::bind(slot(&foo2),1);
     s();
     cout << ">>test 3"<<endl;
     s.clear();
