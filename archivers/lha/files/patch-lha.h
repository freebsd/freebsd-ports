--- src/lha.h.orig	2000-10-05 17:35:38 UTC
+++ src/lha.h
@@ -11,11 +11,14 @@
 		lharc.h		interface.h		slidehuf.h
 */
 #include <stdio.h>
+#include <stdlib.h>
 #include <errno.h>
 #include <ctype.h>
 #include <sys/types.h>
 #include <sys/file.h>
 #include <sys/stat.h>
+#include <unistd.h>
+#include <utime.h>
 
 #include <signal.h>
 
@@ -135,6 +138,7 @@ EXTERN char     temporary_name[FILENAME_
 EXTERN char     backup_archive_name[FILENAME_LENGTH];
 
 EXTERN char		*reading_filename, *writting_filename;
+EXTERN char	*extract_directory;
 
 /* 1996.8.13 t.okamoto */
 #if 0
@@ -191,128 +195,147 @@ EXTERN FILE		*temporary_fp;
 /* ------------------------------------------------------------------------ */
 /*	Functions																*/
 /* ------------------------------------------------------------------------ */
+
+/* from patmatch.c */
+extern int	patmatch(register char *p, register char *s, int f);
+
+
 /* from lharc.c */
-extern int		patmatch();
+extern void	message(char *subject, char *name);
+extern void	warning(char *subject, char *name);
+extern void	error(char *subject, char *msg);
+extern void	fatal_error(char *msg);
 
-extern void		interrupt();
+extern void	interrupt(int signo);
 
-extern void		message();
-extern void		warning();
-extern void		error();
-extern void		fatal_error();
+extern void	init_sp(struct string_pool *sp);
+extern void	add_sp(struct string_pool *sp, char *name, int len);
+extern void	finish_sp(register struct string_pool *sp, int *v_count, char ***v_vector);
+extern void	free_sp(char **vector);
 
-extern boolean	need_file();
-extern int		inquire();
-extern FILE		*xfopen();
+extern void	cleaning_files(int *v_filec, char ***v_filev);
+extern boolean	find_files(char *name, int *v_filec, char ***v_filev);
+extern void	free_files(int filec, char **filev);
 
-extern boolean	find_files();
-extern void		free_files();
+extern void	build_temporary_name(void);
+extern void	build_backup_name(char *buffer, char *original);
+extern void	build_standard_archive_name(char *buffer, char *original);
+extern boolean	need_file(char *name);
+extern FILE	*xfopen(char *name, char *mode);
+extern FILE	*open_old_archive(void);
 
-extern void		init_sp();
-extern void		add_sp();
-extern void		finish_sp();
-extern void		free_sp();
-extern void		cleaning_files();
+extern int	inquire(char *msg, char *name, char *selective);
+extern void	write_archive_tail(FILE *nafp);
+extern void	copy_old_one(FILE *oafp, FILE *nafp, LzHeader *hdr);
 
-extern void		build_temporary_name();
-extern void		build_backup_file_name();
-extern void		build_standard_archive_name();
 
-extern FILE		*open_old_archive();
-extern void		init_header();
-extern boolean	get_header();
-extern boolean	archive_is_msdos_sfx1();
-extern boolean	skip_msdos_sfx1_code();
-extern void		write_header();
-extern void		write_archive_tail();
-extern void		copy_old_one();
-extern unsigned char *convdelim();
-extern long		copyfile();
+/* from header.c */
+extern int	calc_sum(register char *p, register int len);
+extern boolean	get_header(FILE *fp, register LzHeader *hdr);
+extern void	init_header(char *name, struct stat *v_stat, LzHeader *hdr);
+extern void	write_header(FILE *nafp, LzHeader *hdr);
 
-extern void		cmd_list(), cmd_extract(), cmd_add(), cmd_delete();
 
-extern boolean	ignore_directory;
-extern boolean	compress_method;
-extern boolean	verify_mode;
+/* from util.c */
+extern long	copyfile(FILE *f1, FILE *f2, long size, int crc_flg);
+extern int      encode_stored_crc(FILE *ifp, FILE *ofp, long size, long *original_size_var, long *write_size_var);
+extern unsigned char *convdelim(unsigned char *path, unsigned char delim);
+extern boolean	archive_is_msdos_sfx1(char *name);
+extern boolean	skip_msdos_sfx1_code(FILE *fp);
+
+
+/* from lhlist.c */
+extern void	cmd_list(void);
+
+
+/* from lhext.c */
+extern void	cmd_extract(void);
+extern int	is_directory_traversal(char *string);
+
+
+/* from extrac.c */
+extern int      decode_lzhuf(FILE *infp, FILE *outfp, long original_size, long packed_size, char *name, int method);
 
-extern char		*extract_directory;
 
 /* from slide.c */
+extern int	encode_alloc(int method);
+extern void	encode(struct interfacing *interface);
+extern void	decode(struct interfacing *interface);
 
-extern int		encode_alloc();
-extern void		encode();
-extern void		decode();
 
 /* from append.c */
-extern void     start_indicator();
-extern void     finish_indicator();
-extern void     finish_indicator2();
+extern int	encode_lzhuf(FILE *infp, FILE *outfp, long size, long *original_size_var, long *packed_size_var, char *name, char *hdr_method);
+extern void     start_indicator(char *name, long size, char *msg, long def_indicator_threshold);
+extern void     finish_indicator2(char *name, char *msg, int pcnt);
+extern void     finish_indicator(char *name, char *msg);
+
+
+/* from huf.c */
+extern void     output_st1(unsigned short c, unsigned short p);
+extern unsigned char *alloc_buf(void);
+extern void     encode_start_st1(void);
+extern void     encode_end_st1(void);
+extern unsigned short decode_c_st1(void);
+extern unsigned short decode_p_st1(void);
+extern void     decode_start_st1(void);
 
-/* slide.c */
-extern void     output_st1();
-extern unsigned char *alloc_buf();
-extern void     encode_start_st1();
-extern void     encode_end_st1();
-extern unsigned short decode_c_st1();
-extern unsigned short decode_p_st1();
-extern void     decode_start_st1();
 
 /* from shuf.c */
-extern void     decode_start_st0();
-extern void     encode_p_st0( /* unsigned short j */ );
-extern void     encode_start_fix();
-extern void     decode_start_fix();
-extern unsigned short decode_c_st0();
-extern unsigned short decode_p_st0();
+extern void     decode_start_st0(void);
+extern void     encode_p_st0(unsigned short j);
+extern void     encode_start_fix(void);
+extern void     decode_start_fix(void);
+extern unsigned short decode_c_st0(void);
+extern unsigned short decode_p_st0(void);
+
 
 /* from dhuf.c */
-extern void     start_c_dyn();
-extern void     decode_start_dyn();
-extern unsigned short decode_c_dyn();
-extern unsigned short decode_p_dyn();
-extern void     output_dyn( /* int code, unsigned int pos */ );
-extern void     encode_end_dyn();
+extern void     start_c_dyn(void);
+extern void     decode_start_dyn(void);
+extern unsigned short decode_c_dyn(void);
+extern unsigned short decode_p_dyn(void);
+extern void     output_dyn(unsigned int code, unsigned int pos);
+extern void     encode_end_dyn(void);
 
-extern int      decode_lzhuf();
 
 /* from larc.c */
-
-extern unsigned short decode_c_lzs();
-extern unsigned short decode_p_lzs();
-extern unsigned short decode_c_lz5();
-extern unsigned short decode_p_lz5();
-extern void			  decode_start_lzs();
-extern void			  decode_start_lz5();
+extern unsigned short decode_c_lzs(void);
+extern unsigned short decode_p_lzs(void);
+extern void			  decode_start_lzs(void);
+extern unsigned short decode_c_lz5(void);
+extern unsigned short decode_p_lz5(void);
+extern void			  decode_start_lz5(void);
 
 extern void	make_table(	/* int nchar, uchar bitlen[], int tablebits,
 							ushort table[] */ );
 
 /* from maketree.c */
-/*
- * void make_code(short n, uchar len[], ushort code[]); short make_tree(short
- * nparm, ushort freqparm[], uchar lenparm[], ushort codeparam[]);
- */
-extern void		make_code( /* int n, uchar len[], ushort code[] */ );
-extern short	make_tree( /* int nparm, ushort freqparm[], uchar lenparm[],
-								ushort codeparam[] */ );
+extern void	make_code(int n, unsigned char len[], unsigned short code[]);
+extern short	make_tree(int nparm, unsigned short freqparm[], unsigned char lenparm[], unsigned short codeparam[]);
+
 
 /* from crcio.c */
-extern void				make_crctable();
-extern unsigned short	calccrc( /* uchar *p, uint n */ );
-extern void				fillbuf( /* uchar n */ );
-extern unsigned short	getbits( /* uchar n */ );
-extern void				putcode( /* uchar n, ushort x */ );
-extern void				putbits( /* uchar n, ushort x */ );
-extern int				fread_crc( /* uchar *p, int n, FILE *f */ );
-extern void				fwrite_crc( /* uchar *p, int n, FILE *f */ );
-extern void				init_getbits();
-extern void				init_putbits();
-extern void     		make_crctable();
-extern unsigned 		short calccrc();
+extern void		make_crctable(void);
+extern unsigned short	calccrc(unsigned char *p, unsigned int n);
+extern void		fillbuf(unsigned char n);
+extern unsigned short	getbits(unsigned char n);
+extern void		putcode(unsigned char n, unsigned short x);
+extern void		putbits(unsigned char n, unsigned short x);
+extern int		fread_crc(unsigned char *p, int n, FILE *f);
+extern void		fwrite_crc(unsigned char *p, int n, FILE *f);
+extern void		init_code_cache(void);
+extern void		init_getbits(void);
+extern void		init_putbits(void);
+extern int		fwrite_txt(unsigned char *p, int n, FILE *fp);
+extern int		fread_txt(unsigned char *p, int n, FILE *fp);
+extern unsigned short	calc_header_crc(unsigned char *p, unsigned int n);
+
 
 /* from lhadd.c */
-extern int		encode_lzhuf();
-extern int      encode_stored_crc();
+extern void	cmd_add(void);
+extern void	cmd_delete(void);
+extern int	strcmp_filename(char *str1, char *str2);
+
 
 /* Local Variables: */
 /* mode:c */
