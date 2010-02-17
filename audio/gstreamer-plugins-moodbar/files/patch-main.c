diff -crB analyzer/main.c analyzer_patched/main.c
*** analyzer/main.c	2006-10-12 07:43:30.000000000 +0200
--- analyzer_patched/main.c	2010-02-15 20:24:57.000000000 +0100
***************
*** 261,267 ****
      };
    GOptionContext *ctx;
    GError *err = NULL;
! 
    ctx = g_option_context_new ("[INFILE] - Run moodbar analyzer");
    g_option_context_add_group (ctx, gst_init_get_option_group ());
    g_option_context_add_main_entries (ctx, entries, NULL);
--- 261,267 ----
      };
    GOptionContext *ctx;
    GError *err = NULL;
!   g_thread_init(NULL);
    ctx = g_option_context_new ("[INFILE] - Run moodbar analyzer");
    g_option_context_add_group (ctx, gst_init_get_option_group ());
    g_option_context_add_main_entries (ctx, entries, NULL);
