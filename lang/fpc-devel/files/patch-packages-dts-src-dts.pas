--- packages/dts/src/dts.pas	2010-04-21 20:42:31.000000000 +0100
+++ packages/dts/src/dts.pas	2010-04-21 20:52:51.000000000 +0100
@@ -272,7 +272,7 @@
 {$IF Defined(WINDOWS)}
   dtslib = 'dts.dll';
 {$ELSEIF Defined(UNIX)}
-  dtslib = 'libdts.so';
+  dtslib = 'libdca.so';
 {$ELSE}
   {$MESSAGE ERROR 'DYNLINK not supported'}
 {$IFEND}
@@ -331,14 +331,14 @@
   DTS_ADJUST_LEVEL    = $100;
 
 
-function dts_init(mm_accel: cuint32): pdts_state_t; cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
-function dts_syncinfo(state: pdts_state_t; buf: pcuint8; var flags: cint; var sample_rate: cint; var bit_rate: cint; var frame_length: cint): cint; cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
-function dts_frame(state: pdts_state_t; buf: pcuint8; var flags: cint; var level: dts_level_t; bias: dts_sample_t): cint; cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
-procedure dts_dynrng(state: pdts_state_t; call: dts_dynrng_call; data: pointer); cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
-function dts_blocks_num(state: pdts_state_t): cint; cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
-function dts_block(state: pdts_state_t): cint; cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
-function dts_samples(state: pdts_state_t): pdts_sample_t; cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
-procedure dts_free(state: pdts_state_t); cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
+function dca_init(mm_accel: cuint32): pdts_state_t; cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
+function dca_syncinfo(state: pdts_state_t; buf: pcuint8; var flags: cint; var sample_rate: cint; var bit_rate: cint; var frame_length: cint): cint; cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
+function dca_frame(state: pdts_state_t; buf: pcuint8; var flags: cint; var level: dts_level_t; bias: dts_sample_t): cint; cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
+procedure dca_dynrng(state: pdts_state_t; call: dts_dynrng_call; data: pointer); cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
+function dca_blocks_num(state: pdts_state_t): cint; cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
+function dca_block(state: pdts_state_t): cint; cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
+function dca_samples(state: pdts_state_t): pdts_sample_t; cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
+procedure dca_free(state: pdts_state_t); cdecl; external {$IFDEF DYNLINK}dtslib{$ENDIF};
 
 
 
@@ -378,12 +378,61 @@
   end;
 
 
+function dts_init(mm_accel: cuint32): pdts_state_t;
+function dts_syncinfo(state: pdts_state_t; buf: pcuint8; var flags: cint; var sample_rate: cint; var bit_rate: cint; var frame_length: cint): cint;
+function dts_frame(state: pdts_state_t; buf: pcuint8; var flags: cint; var level: dts_level_t; bias: dts_sample_t): cint;
+procedure dts_dynrng(state: pdts_state_t; call: dts_dynrng_call; data: pointer);
+function dts_blocks_num(state: pdts_state_t): cint;
+function dts_block(state: pdts_state_t): cint;
+function dts_samples(state: pdts_state_t): pdts_sample_t;
+procedure dts_free(state: pdts_state_t);
+
 function dts_decoder_init(mm_accel: cuint32; user: pointer; read: dts_read_func; seek: dts_seek_func; close: dts_close_func; tell: dts_tell_func): pdts_decoder;
 function dts_decoder_read(decoder: pdts_decoder; buffer: pointer; length: cint): cint;
 procedure dts_decoder_free(decoder: pdts_decoder);
 
 implementation
 
+function dts_init(mm_accel: cuint32): pdts_state_t;
+begin
+   Result := dca_init(mm_accel);
+end;
+
+function dts_syncinfo(state: pdts_state_t; buf: pcuint8; var flags: cint; var sample_rate: cint; var bit_rate: cint; var frame_length: cint): cint;
+begin
+   Result := dca_syncinfo(state, buf, flags, sample_rate, bit_rate, frame_length);
+end;
+
+function dts_frame(state: pdts_state_t; buf: pcuint8; var flags: cint; var level: dts_level_t; bias: dts_sample_t): cint;
+begin
+   Result := dca_frame(state, buf, flags, level, bias);
+end;
+
+procedure dts_dynrng(state: pdts_state_t; call: dts_dynrng_call; data: pointer);
+begin
+   dca_dynrng(state, call, data);
+end;
+
+function dts_blocks_num(state: pdts_state_t): cint;
+begin
+   Result := dca_blocks_num(state);
+end;
+
+function dts_block(state: pdts_state_t): cint;
+begin
+   Result := dca_block(state);
+end;
+
+function dts_samples(state: pdts_state_t): pdts_sample_t;
+begin
+   Result := dca_samples(state)
+end;
+
+procedure dts_free(state: pdts_state_t);
+begin
+   dca_free(state);
+end;
+
 function dts_decoder_init(mm_accel: cuint32; user: pointer; read: dts_read_func; seek: dts_seek_func; close: dts_close_func; tell: dts_tell_func): pdts_decoder;
 begin
   GetMem(Result, Sizeof(dts_decoder));
Only in work.new/fpc-2.4.0/packages/dts/src: dts.pas~
