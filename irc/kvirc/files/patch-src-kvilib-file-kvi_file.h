*** src/kvilib/file/kvi_file.h.orig	Fri Feb 27 17:56:33 2004
--- src/kvilib/file/kvi_file.h	Fri Feb 27 17:10:05 2004
***************
*** 59,66 ****
  	bool save(kvi_u8_t t){ return save((kvi_i8_t)t); };
  	bool load(kvi_u8_t &t){ return load((kvi_i8_t)t); };;
  
! 	bool save(time_t t){ return save((kvi_i32_t)t); };
! 	bool load(time_t &t){ return load((kvi_i32_t)t); };
  
  	bool save(const KviStr &szData);
  	bool load(KviStr &szData);
--- 59,66 ----
  	bool save(kvi_u8_t t){ return save((kvi_i8_t)t); };
  	bool load(kvi_u8_t &t){ return load((kvi_i8_t)t); };;
  
! 	//bool save(time_t t){ return save((kvi_i32_t)t); };
! 	//bool load(time_t &t){ return load((kvi_i32_t)t); };
  
  	bool save(const KviStr &szData);
  	bool load(KviStr &szData);
