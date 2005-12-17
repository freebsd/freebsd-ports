--- vm/base/Coro.c.orig	Sat Dec 17 12:04:01 2005
+++ vm/base/Coro.c	Sat Dec 17 12:04:11 2005
@@ -9,7 +9,7 @@
 {
 	Coro *self = (Coro *)calloc(1, sizeof(Coro));
 	self->stackSize = CSTACK_STACKSIZE;
-	self->stack = calloc(1, self->stackSize);
+	self->stack = calloc(1, self->stackSize+1);
 	Coro_loop(self);
 	Coro_label_(self, "");
 	return self;
