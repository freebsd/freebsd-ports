--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/SetsDrv2.c	Sat Sep 11 00:58:46 2004
+++ ./reuse/m2c/SetsDrv2.c	Thu Aug  5 18:49:36 2004
@@ -0,0 +1,160 @@
+#include "SYSTEM_.h"
+
+#ifndef DEFINITION_Sets
+#include "Sets.h"
+#endif
+
+#ifndef DEFINITION_IO
+#include "IO.h"
+#endif
+
+#include <stdio.h>
+#include <assert.h>
+
+int sizes[] = { 1, 2, 3, 4, 5,
+		7, 8, 9, 
+		15, 16, 17, 
+		31, 32, 33, 
+		63, 64, 65, 
+		127, 128, 129, 
+		254, 255, 256, 
+		511, 512, 513,
+		1023, 1024, 1025,
+		0 };
+
+#define MAXSET 1026
+int myset[MAXSET];
+
+static Sets_tSet s, t, u, v;
+static IO_tFile f;
+
+static void SetInfo( Sets_tSet s )
+{
+  Sets_WriteSet((rSystem_tFile)IO_StdOutput, s);
+  IO_WriteS((rSystem_tFile)IO_StdOutput, (STRING)" Card = ", 8L);
+  IO_WriteI((rSystem_tFile)IO_StdOutput, (LONGINT)Sets_Card(&s), 0L);
+  IO_WriteNl((rSystem_tFile)IO_StdOutput);
+}
+
+static BOOLEAN TestOdd(int i)
+{
+	return (i%2) == 1;
+}
+
+static BOOLEAN TestEven(int i)
+{
+	return (i%2) == 0;
+}
+
+static void CleanMyset(void)
+{
+	int i;
+	for (i=0; i++; i<MAXSET) {
+	    myset[i] = 0;
+	}
+}
+
+static void SetMyset(int i)
+{
+	myset[i] = 1;
+}
+
+void BEGIN_MODULE()
+{
+  int i, j, size, sizeindex = 0;
+
+  BEGIN_Sets();
+  BEGIN_IO();
+  
+  while (sizes[sizeindex] != 0 ) {
+    size = sizes[sizeindex]-1;
+    printf("Upperbound: %d\n", size);
+
+    Sets_MakeSet(&s, (LONGCARD)size);
+    for (i = 0; i <= size; i += 1) {
+      Sets_Include(&s,i);
+    }
+    for (i = 0; i <= size; i += 1) {
+      assert(Sets_IsElement(i, &s));	/* a full filed set */
+    }
+
+    Sets_MakeSet(&t, (LONGCARD)size); 
+    for (i = 0; i <= size; i += 2) {
+      Sets_Include(&t,i);		/* all even elements */
+    }
+    Sets_Difference(&s,t);		/* s = all odd elements */
+    for (i = 1; i <= size; i += 2) {
+      assert(Sets_IsElement(i, &s));
+    }
+/*    SetInfo(s);
+/*    SetInfo(t);
+ */
+
+    Sets_Intersection(&t,s);
+    assert(Sets_IsEmpty(t));		/* even and odd do not mix */
+    
+    Sets_MakeSet(&u, (LONGCARD)size);
+    Sets_Assign(&t,s);
+    Sets_Complement(&t);		/* t = all even */
+    Sets_Assign(&u,t);			/* keep a copy */
+    for (i = 0; i <= size; i += 2) {
+      assert(Sets_IsElement(i, &t));
+    }
+    Sets_Intersection(&t,s);
+    assert(Sets_IsEmpty(t));
+
+    Sets_Union(&s,u);			/* odd and even gives a full set */
+    assert(!Sets_IsEmpty(s));
+    for (i = 0; i <= size; i += 1) {
+      assert(Sets_IsElement(i, &s));
+    }
+    Sets_Assign(&t,s);
+
+    for (i = 0; i <= size; i += 1) {
+      assert(Sets_IsElement(i, &s));
+      Sets_Exclude(&s, i);
+      assert(!Sets_IsElement(i, &s));
+    }
+    assert(Sets_IsEmpty(s));
+   
+    while( !Sets_IsEmpty(t) ) {
+	Sets_Include(&s, Sets_Extract(&t));
+    } 
+    assert(Sets_IsEmpty(t));
+    for (i = 0; i <= size; i += 1) {
+      assert(Sets_IsElement(i, &s));
+    }
+
+    while( !Sets_IsEmpty(s) ) {
+        j = Sets_Select(&s);
+	Sets_Include(&t, j);
+	Sets_Exclude(&s, j);
+    } 
+    assert(Sets_IsEmpty(s));
+    for (i = 0; i <= size; i += 1) {
+      assert(Sets_IsElement(i, &t));
+    }
+
+    Sets_AssignEmpty(&t);
+    for (i = 0; i <= size; i += 2) {
+      Sets_Include(&t, i);
+    }
+    Sets_Exists(t,(Sets_ProcOfCardToBool)(TestEven));
+
+    CleanMyset();
+    Sets_ForallDo(t, (Sets_ProcOfCard)(SetMyset));
+
+    for (i = 0; i <= size; i += 1) {
+      assert(Sets_IsElement(i, &t)==(myset[i]==1));
+    }
+    for (i = 0; i <= size; i += 1) {
+      assert((!Sets_IsElement(i, &t))==(myset[i]==0));
+    }
+
+    /* next size */
+    sizeindex++;
+    Sets_ReleaseSet(&s);
+    Sets_ReleaseSet(&t);
+    Sets_ReleaseSet(&u);
+  }
+}
