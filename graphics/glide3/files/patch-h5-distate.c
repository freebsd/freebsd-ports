--- h5/glide3/src/distate.c.orig	Sun Sep 28 22:36:52 2003
+++ h5/glide3/src/distate.c	Sun Sep 28 22:37:05 2003
@@ -350,31 +350,31 @@
  */
 
 #define STOREARG_TMU(function, tmu, arg) \
-gc->state.stateArgs.##function##Args.arg[tmu] = arg
+gc->state.stateArgs.function##Args.arg[tmu] = arg
 
 #define LOADARG_TMU(function, tmu, arg) \
-gc->state.stateArgs.##function##Args.arg[tmu]
+gc->state.stateArgs.function##Args.arg[tmu]
 
 #define STOREARG(function, arg) \
-gc->state.stateArgs.##function##Args.arg = arg
+gc->state.stateArgs.function##Args.arg = arg
 
 #define LOADARG(function, arg) \
-gc->state.stateArgs.##function##Args.arg
+gc->state.stateArgs.function##Args.arg
 
 #define NOTVALID(regset) \
-(gc->state.invalid & ##regset##BIT)
+(gc->state.invalid & regset##BIT)
 
 #define NOTVALID_TMU(tmu, regset) \
-(gc->state.tmuInvalid[tmu] & ##regset##BIT)
+(gc->state.tmuInvalid[tmu] & regset##BIT)
 
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
