--- tests/testit.sh.orig	2020-06-24 22:53:32 UTC
+++ tests/testit.sh
@@ -114,63 +114,6 @@ run test1 "test1 - 56" "arg1: 0 arg2: (none) aFlag: 0x
 
 run test1 "test1 - 57" "arg1: 0 arg2: (none) aBits: foo,baz" --bits foo,bar,baz,!bar
 
-run test1 "test1 - 58" "\
-Usage: lt-test1 [-I?] [-c|--cb2=STRING] [--arg1] [-2|--arg2=ARG]
-        [-3|--arg3=ANARG] [-onedash] [--optional=STRING] [--val]
-        [-i|--int=INT] [-s|--short=SHORT] [-l|--long=LONG]
-        [-L|--longlong=LONGLONG] [-f|--float=FLOAT] [-d|--double=DOUBLE]
-        [--randint=INT] [--randshort=SHORT] [--randlong=LONG]
-        [--randlonglong=LONGLONG] [--argv=STRING] [--bitset] [--bitclr]
-        [--bitxor] [--nstr=STRING] [--lstr=STRING] [-I|--inc]
-        [-c|--cb=STRING] [--longopt] [-?|--help] [--usage] [--simple=ARG]" --usage
-run test1 "test1 - 59" "\
-Usage: lt-test1 [OPTION...]
-      --arg1                      First argument with a really long
-                                  description. After all, we have to test
-                                  argument help wrapping somehow, right?
-  -2, --arg2=ARG                  Another argument (default: \"(none)\")
-  -3, --arg3=ANARG                A third argument
-      -onedash                    POPT_ARGFLAG_ONEDASH: Option takes a single -
-      --optional[=STRING]         POPT_ARGFLAG_OPTIONAL: Takes an optional
-                                  string argument
-      --val                       POPT_ARG_VAL: 125992 141421
-  -i, --int=INT                   POPT_ARG_INT: 271828 (default: 271828)
-  -s, --short=SHORT               POPT_ARG_SHORT: 4523 (default: 4523)
-  -l, --long=LONG                 POPT_ARG_LONG: 738905609 (default: 738905609)
-  -L, --longlong=LONGLONG         POPT_ARG_LONGLONG: 738905609 (default:
-                                  738905609)
-  -f, --float=FLOAT               POPT_ARG_FLOAT: 3.14159 (default: 3.14159)
-  -d, --double=DOUBLE             POPT_ARG_DOUBLE: 9.8696 (default: 9.8696)
-      --randint=INT               POPT_ARGFLAG_RANDOM: experimental
-      --randshort=SHORT           POPT_ARGFLAG_RANDOM: experimental
-      --randlong=LONG             POPT_ARGFLAG_RANDOM: experimental
-      --randlonglong=LONGLONG     POPT_ARGFLAG_RANDOM: experimental
-      --argv STRING               POPT_ARG_ARGV: append string to argv array
-                                  (can be used multiple times)
-      --[no]bitset                POPT_BIT_SET: |= 0x7777
-      --[no]bitclr                POPT_BIT_CLR: &= ~0xf842
-      --bitxor                    POPT_ARGFLAG_XOR: ^= (0x8ace^0xfeed)
-      --nstr=STRING               POPT_ARG_STRING: (null) (default: null)
-      --lstr=STRING               POPT_ARG_STRING: \"123456789...\" (default:
-                                  \"This tests default strings and exceeds the
-                                  ... limit.
-                                  123456789+123456789+123456789+123456789+123456789+ 123456789+123456789+123456789+123456789+123456789+ 1234567...\")
-
-arg for cb2
-  -c, --cb2=STRING                Test argument callbacks
-  -I, --inc                       An included argument
-
-Callback arguments
-  -c, --cb=STRING                 Test argument callbacks
-      --longopt                   Unused option for help testing
-
-Options implemented via popt alias/exec:
-      --simple=ARG                simple description
-
-Help options:
-  -?, --help                      Show this help message
-      --usage                     Display brief usage message" --help
-
 #run_diff test3 "test3 - 51" test3-data/01.input test3-data/01.answer
 #run_diff test3 "test3 - 52" test3-data/02.input test3-data/02.answer
 #run_diff test3 "test3 - 53" test3-data/03.input test3-data/03.answer
