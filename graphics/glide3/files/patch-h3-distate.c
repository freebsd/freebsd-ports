--- h3/glide3/src/distate.c.orig	Sun Sep 28 22:48:55 2003
+++ h3/glide3/src/distate.c	Sun Sep 28 22:49:07 2003
@@ -206,23 +206,23 @@
  */
 
 #define STOREARG(function, arg) \
-gc->state.stateArgs.##function##Args.arg = arg
+gc->state.stateArgs.function##Args.arg = arg
 
 #define LOADARG(function, arg) \
-gc->state.stateArgs.##function##Args.arg
+gc->state.stateArgs.function##Args.arg
 
 
 #define NOTVALID(regset) \
-(gc->state.invalid & ##regset##BIT)
+(gc->state.invalid & regset##BIT)
 
 #define SETVALID(regset) \
-(gc->state.invalid &= ~(##regset##BIT))
+(gc->state.invalid &= ~(regset##BIT))
 
 #define ENABLEMODE(mode) \
-gc->state.grEnableArgs.##mode## = GR_MODE_ENABLE;
+gc->state.grEnableArgs.mode = GR_MODE_ENABLE;
 
 #define DISABLEMODE(mode) \
-gc->state.grEnableArgs.##mode## = GR_MODE_DISABLE;
+gc->state.grEnableArgs.mode = GR_MODE_DISABLE;
 
 /*-------------------------------------------------------------------
   Function: grAlphaBlendFunction
