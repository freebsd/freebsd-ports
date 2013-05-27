--- ./mp3_check_misc.c.orig	2000-09-16 05:36:01.000000000 +0200
+++ ./mp3_check_misc.c	2013-05-27 14:05:42.403067935 +0200
@@ -11,7 +11,7 @@
 #include "support_functions.h"
 
 //  Function prototypes go here. 
-inline int		move_to_next_frame(char *possible_mp3_tag, frame_info *mp3_i, gen_info *file_info, command_flags *flags, FILE *);
+int		move_to_next_frame(char *possible_mp3_tag, frame_info *mp3_i, gen_info *file_info, command_flags *flags, FILE *);
 int			get_char_from_file(FILE *, unsigned int *header_value, gen_info *file_info, command_flags *flags, char *possible_mp3_tag);
 int			scan_file(FILE *, char *filename, meta_options *flag_options, command_flags *flags);
 int			parse_args(char **argv, meta_options *flag_options, command_flags *flags);
@@ -670,7 +670,7 @@
 		return(PASS);
 }
 
-inline int
+int
 move_to_next_frame(possible_mp3_tag, mp3_i, file_info, flags, fp)
 	char		*possible_mp3_tag;
 	frame_info	*mp3_i;
