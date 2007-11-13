
$FreeBSD$

--- src/metaflac/options.c.orig
+++ src/metaflac/options.c
@@ -20,6 +20,7 @@
 #include "usage.h"
 #include "utils.h"
 #include "FLAC/assert.h"
+#include "share/alloc.h"
 #include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -183,7 +184,7 @@
 
 	if(options->num_files > 0) {
 		unsigned i = 0;
-		if(0 == (options->filenames = (char**)malloc(sizeof(char*) * options->num_files)))
+		if(0 == (options->filenames = (char**)safe_malloc_mul_2op_(sizeof(char*), /*times*/options->num_files)))
 			die("out of memory allocating space for file names list");
 		while(share__optind < argc)
 			options->filenames[i++] = local_strdup(argv[share__optind++]);
@@ -661,8 +662,10 @@
 	}
 	if(options->ops.capacity <= options->ops.num_operations) {
 		unsigned original_capacity = options->ops.capacity;
-		options->ops.capacity *= 4;
-		if(0 == (options->ops.operations = (Operation*)realloc(options->ops.operations, sizeof(Operation) * options->ops.capacity)))
+		if(options->ops.capacity > SIZE_MAX / 2) /* overflow check */
+			die("out of memory allocating space for option list");
+		options->ops.capacity *= 2;
+		if(0 == (options->ops.operations = (Operation*)safe_realloc_mul_2op_(options->ops.operations, sizeof(Operation), /*times*/options->ops.capacity)))
 			die("out of memory allocating space for option list");
 		memset(options->ops.operations + original_capacity, 0, sizeof(Operation) * (options->ops.capacity - original_capacity));
 	}
@@ -680,8 +683,10 @@
 	}
 	if(options->args.capacity <= options->args.num_arguments) {
 		unsigned original_capacity = options->args.capacity;
-		options->args.capacity *= 4;
-		if(0 == (options->args.arguments = (Argument*)realloc(options->args.arguments, sizeof(Argument) * options->args.capacity)))
+		if(options->args.capacity > SIZE_MAX / 2) /* overflow check */
+			die("out of memory allocating space for option list");
+		options->args.capacity *= 2;
+		if(0 == (options->args.arguments = (Argument*)safe_realloc_mul_2op_(options->args.arguments, sizeof(Argument), /*times*/options->args.capacity)))
 			die("out of memory allocating space for option list");
 		memset(options->args.arguments + original_capacity, 0, sizeof(Argument) * (options->args.capacity - original_capacity));
 	}
@@ -897,7 +902,7 @@
 
 	/* make space */
 	FLAC__ASSERT(out->num_entries > 0);
-	if(0 == (out->entries = (unsigned*)malloc(sizeof(unsigned) * out->num_entries)))
+	if(0 == (out->entries = (unsigned*)safe_malloc_mul_2op_(sizeof(unsigned), /*times*/out->num_entries)))
 		die("out of memory allocating space for option list");
 
 	/* load 'em up */
@@ -936,7 +941,7 @@
 
 	/* make space */
 	FLAC__ASSERT(out->num_entries > 0);
-	if(0 == (out->entries = (Argument_BlockTypeEntry*)malloc(sizeof(Argument_BlockTypeEntry) * out->num_entries)))
+	if(0 == (out->entries = (Argument_BlockTypeEntry*)safe_malloc_mul_2op_(sizeof(Argument_BlockTypeEntry), /*times*/out->num_entries)))
 		die("out of memory allocating space for option list");
 
 	/* load 'em up */
