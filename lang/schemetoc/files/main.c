
/* SCHEME->C */

#include <objects.h>

DEFSTATICTSCP( sc_2dlog_2ddefault_v );
DEFSTATICTSCP( with_2dmodules_v );
DEFSTATICTSCP( initialize_2dcompile_v );
DEFSTATICTSCP( do_2ddefine_2dconstant_v );
DEFSTATICTSCP( sc_2dinclude_2ddirs_v );
DEFSTATICTSCP( sc_2dinput_v );
DEFSTATICTSCP( sc_2dsource_2dname_v );
DEFSTATICTSCP( sc_2dicode_v );
DEFSTATICTSCP( sc_2derror_v );
DEFSTATICTSCP( sc_2dlog_v );
DEFSTATICTSCP( sc_2dstack_2dtrace_v );
DEFSTATICTSCP( sc_2dinterpreter_v );
DEFSTATICTSCP( docompile_v );
DEFSTATICTSCP( sc_2derror_2dcnt_v );
DEFSTATICTSCP( module_2dname_v );
DEFSTATICTSCP( close_2dsc_2dfiles_v );
DEFCSTRING( t2604, "Argument is not a STRING: ~s" );
DEFSTATICTSCP( c2558 );
DEFSTATICTSCP( c2557 );
DEFCSTRING( t2605, ".S2C" );
DEFSTATICTSCP( c2540 );
DEFCSTRING( t2606, ".c" );
DEFSTATICTSCP( c2539 );
DEFCSTRING( t2607, "~a:~%" );
DEFSTATICTSCP( c2490 );
DEFCSTRING( t2608, ".sc" );
DEFSTATICTSCP( c2488 );
DEFCSTRING( t2609, "gcc" );
DEFSTATICTSCP( c2456 );
DEFCSTRING( t2610, "SC-TO-C.o" );
DEFSTATICTSCP( c2455 );
DEFCSTRING( t2611, "SC-TO-C.c" );
DEFSTATICTSCP( c2454 );
DEFCSTRING( t2612, "-L/usr/X11R6/lib -lX11" );
DEFSTATICTSCP( c2450 );
DEFCSTRING( t2613, "-lm" );
DEFSTATICTSCP( c2447 );
DEFCSTRING( t2614, "-pg" );
DEFSTATICTSCP( c2444 );
DEFCSTRING( t2615, "-L/usr/X11R6/lib -lsc -lscxl -lX11" );
DEFSTATICTSCP( c2443 );
DEFCSTRING( t2616, "-lsc" );
DEFSTATICTSCP( c2440 );
DEFCSTRING( t2617, "xlib" );
DEFSTATICTSCP( c2436 );
DEFCSTRING( t2618, "-c" );
DEFSTATICTSCP( c2435 );
DEFCSTRING( t2619, " -I" );
DEFSTATICTSCP( c2390 );
DEFCSTRING( t2620, "}~%" );
DEFSTATICTSCP( c2384 );
DEFCSTRING( t2621, "   SCHEMEEXIT();~%" );
DEFSTATICTSCP( c2383 );
DEFCSTRING( t2622, 
            "   screp_read_2deval_2dprint( sc_clarguments( argc, argv ) );~%\
" );
DEFSTATICTSCP( c2382 );
DEFCSTRING( t2623, "screp" );
DEFSTATICTSCP( c2381 );
DEFCSTRING( t2624, "   ~a__init();~%" );
DEFSTATICTSCP( c2380 );
DEFCSTRING( t2625, "Argument not a PAIR: ~s" );
DEFSTATICTSCP( c2369 );
DEFSTATICTSCP( c2368 );
DEFCSTRING( t2626, 
            "   INITHEAP( 0, argc, argv, screp_read_2deval_2dprint );~%" );
DEFSTATICTSCP( c2333 );
DEFCSTRING( t2627, "{~%" );
DEFSTATICTSCP( c2332 );
DEFCSTRING( t2628, "   int argc; char *argv[];~%" );
DEFSTATICTSCP( c2331 );
DEFCSTRING( t2629, "main( argc, argv )~%" );
DEFSTATICTSCP( c2330 );
DEFCSTRING( t2630, "extern TSCP screp_read_2deval_2dprint();~%" );
DEFSTATICTSCP( c2329 );
DEFCSTRING( t2631, "#include \"~a/~a\"~%" );
DEFSTATICTSCP( c2328 );
DEFCSTRING( t2632, ")" );
DEFSTATICTSCP( c2312 );
DEFCSTRING( t2633, " " );
DEFSTATICTSCP( c2311 );
DEFCSTRING( t2634, "(define-constant " );
DEFSTATICTSCP( c2300 );
DEFCSTRING( t2635, "/" );
DEFSTATICTSCP( c2283 );
DEFSTATICTSCP( c2181 );
DEFSTATICTSCP( t2636 );
DEFCSTRING( t2638, "-peep" );
DEFSTATICTSCP( t2637 );
DEFSTATICTSCP( t2639 );
DEFCSTRING( t2641, "-lap" );
DEFSTATICTSCP( t2640 );
DEFSTATICTSCP( t2642 );
DEFCSTRING( t2644, "-tree" );
DEFSTATICTSCP( t2643 );
DEFSTATICTSCP( t2645 );
DEFCSTRING( t2647, "-lambda" );
DEFSTATICTSCP( t2646 );
DEFSTATICTSCP( t2648 );
DEFCSTRING( t2650, "-transform" );
DEFSTATICTSCP( t2649 );
DEFSTATICTSCP( t2651 );
DEFCSTRING( t2653, "-closed" );
DEFSTATICTSCP( t2652 );
DEFSTATICTSCP( t2654 );
DEFCSTRING( t2656, "-expand" );
DEFSTATICTSCP( t2655 );
DEFSTATICTSCP( t2657 );
DEFCSTRING( t2659, "-macro" );
DEFSTATICTSCP( t2658 );
DEFSTATICTSCP( t2660 );
DEFCSTRING( t2662, "-source" );
DEFSTATICTSCP( t2661 );
DEFCSTRING( t2663, "(define-constant *type-check* #f)" );
DEFSTATICTSCP( c2166 );
DEFCSTRING( t2664, "(define-constant *bounds-check* #f)" );
DEFSTATICTSCP( c2155 );
DEFCSTRING( t2665, "(define-constant *fixed-only* #t)" );
DEFSTATICTSCP( c2144 );
DEFCSTRING( t2666, "-cc" );
DEFSTATICTSCP( c2105 );
DEFCSTRING( t2667, "-C" );
DEFSTATICTSCP( c2101 );
DEFCSTRING( t2668, "-On" );
DEFSTATICTSCP( c2100 );
DEFCSTRING( t2669, "-Og" );
DEFSTATICTSCP( c2099 );
DEFCSTRING( t2670, "-Ob" );
DEFSTATICTSCP( c2098 );
DEFCSTRING( t2671, "-static" );
DEFSTATICTSCP( c2097 );
DEFCSTRING( t2672, "-Ot" );
DEFSTATICTSCP( c2096 );
DEFCSTRING( t2673, "-log" );
DEFSTATICTSCP( c2093 );
DEFCSTRING( t2674, "-LIBDIR" );
DEFSTATICTSCP( c2087 );
DEFCSTRING( t2675, "-m" );
DEFSTATICTSCP( c2078 );
DEFCSTRING( t2676, "-I" );
DEFSTATICTSCP( c2069 );
DEFCSTRING( t2677, "-i" );
DEFSTATICTSCP( c2065 );
DEFCSTRING( t2678, "-f" );
DEFSTATICTSCP( c2045 );
DEFSTATICTSCP( c2019 );
DEFCSTRING( t2679, "libsc_p.a" );
DEFSTATICTSCP( c2015 );
DEFCSTRING( t2680, "scxl.a" );
DEFSTATICTSCP( c2013 );
DEFCSTRING( t2681, "libsc.a" );
DEFSTATICTSCP( c2011 );
DEFCSTRING( t2682, "objects.h" );
DEFSTATICTSCP( c2008 );
DEFCSTRING( t2683, "predef.sc" );
DEFSTATICTSCP( c2006 );
DEFCSTRING( t2684, "15mar93-FreeBSD" );
DEFSTATICTSCP( c2003 );
DEFCSTRING( t2685, "/usr/local/lib/schemetoc/" );
DEFSTATICTSCP( c2001 );

static void  init_constants()
{
        TSCP  X1;

        sc_2dlog_2ddefault_v = STRINGTOSYMBOL( CSTRING_TSCP( "SC-LOG-DEFAULT\
" ) );
        CONSTANTEXP( ADR( sc_2dlog_2ddefault_v ) );
        with_2dmodules_v = STRINGTOSYMBOL( CSTRING_TSCP( "WITH-MODULES" ) );
        CONSTANTEXP( ADR( with_2dmodules_v ) );
        initialize_2dcompile_v = STRINGTOSYMBOL( CSTRING_TSCP( "INITIALIZE-C\
OMPILE" ) );
        CONSTANTEXP( ADR( initialize_2dcompile_v ) );
        do_2ddefine_2dconstant_v = STRINGTOSYMBOL( CSTRING_TSCP( "DO-DEFINE-\
CONSTANT" ) );
        CONSTANTEXP( ADR( do_2ddefine_2dconstant_v ) );
        sc_2dinclude_2ddirs_v = STRINGTOSYMBOL( CSTRING_TSCP( "SC-INCLUDE-DI\
RS" ) );
        CONSTANTEXP( ADR( sc_2dinclude_2ddirs_v ) );
        sc_2dinput_v = STRINGTOSYMBOL( CSTRING_TSCP( "SC-INPUT" ) );
        CONSTANTEXP( ADR( sc_2dinput_v ) );
        sc_2dsource_2dname_v = STRINGTOSYMBOL( CSTRING_TSCP( "SC-SOURCE-NAME\
" ) );
        CONSTANTEXP( ADR( sc_2dsource_2dname_v ) );
        sc_2dicode_v = STRINGTOSYMBOL( CSTRING_TSCP( "SC-ICODE" ) );
        CONSTANTEXP( ADR( sc_2dicode_v ) );
        sc_2derror_v = STRINGTOSYMBOL( CSTRING_TSCP( "SC-ERROR" ) );
        CONSTANTEXP( ADR( sc_2derror_v ) );
        sc_2dlog_v = STRINGTOSYMBOL( CSTRING_TSCP( "SC-LOG" ) );
        CONSTANTEXP( ADR( sc_2dlog_v ) );
        sc_2dstack_2dtrace_v = STRINGTOSYMBOL( CSTRING_TSCP( "SC-STACK-TRACE\
" ) );
        CONSTANTEXP( ADR( sc_2dstack_2dtrace_v ) );
        sc_2dinterpreter_v = STRINGTOSYMBOL( CSTRING_TSCP( "SC-INTERPRETER" ) );
        CONSTANTEXP( ADR( sc_2dinterpreter_v ) );
        docompile_v = STRINGTOSYMBOL( CSTRING_TSCP( "DOCOMPILE" ) );
        CONSTANTEXP( ADR( docompile_v ) );
        sc_2derror_2dcnt_v = STRINGTOSYMBOL( CSTRING_TSCP( "SC-ERROR-CNT" ) );
        CONSTANTEXP( ADR( sc_2derror_2dcnt_v ) );
        module_2dname_v = STRINGTOSYMBOL( CSTRING_TSCP( "MODULE-NAME" ) );
        CONSTANTEXP( ADR( module_2dname_v ) );
        close_2dsc_2dfiles_v = STRINGTOSYMBOL( CSTRING_TSCP( "CLOSE-SC-FILES\
" ) );
        CONSTANTEXP( ADR( close_2dsc_2dfiles_v ) );
        c2558 = CSTRING_TSCP( t2604 );
        CONSTANTEXP( ADR( c2558 ) );
        c2557 = STRINGTOSYMBOL( CSTRING_TSCP( "STRING-LENGTH" ) );
        CONSTANTEXP( ADR( c2557 ) );
        c2540 = CSTRING_TSCP( t2605 );
        CONSTANTEXP( ADR( c2540 ) );
        c2539 = CSTRING_TSCP( t2606 );
        CONSTANTEXP( ADR( c2539 ) );
        c2490 = CSTRING_TSCP( t2607 );
        CONSTANTEXP( ADR( c2490 ) );
        c2488 = CSTRING_TSCP( t2608 );
        CONSTANTEXP( ADR( c2488 ) );
        c2456 = CSTRING_TSCP( t2609 );
        CONSTANTEXP( ADR( c2456 ) );
        c2455 = CSTRING_TSCP( t2610 );
        CONSTANTEXP( ADR( c2455 ) );
        c2454 = CSTRING_TSCP( t2611 );
        CONSTANTEXP( ADR( c2454 ) );
        c2450 = CSTRING_TSCP( t2612 );
        CONSTANTEXP( ADR( c2450 ) );
        c2447 = CSTRING_TSCP( t2613 );
        CONSTANTEXP( ADR( c2447 ) );
        c2444 = CSTRING_TSCP( t2614 );
        CONSTANTEXP( ADR( c2444 ) );
        c2443 = CSTRING_TSCP( t2615 );
        CONSTANTEXP( ADR( c2443 ) );
        c2440 = CSTRING_TSCP( t2616 );
        CONSTANTEXP( ADR( c2440 ) );
        c2436 = CSTRING_TSCP( t2617 );
        CONSTANTEXP( ADR( c2436 ) );
        c2435 = CSTRING_TSCP( t2618 );
        CONSTANTEXP( ADR( c2435 ) );
        c2390 = CSTRING_TSCP( t2619 );
        CONSTANTEXP( ADR( c2390 ) );
        c2384 = CSTRING_TSCP( t2620 );
        CONSTANTEXP( ADR( c2384 ) );
        c2383 = CSTRING_TSCP( t2621 );
        CONSTANTEXP( ADR( c2383 ) );
        c2382 = CSTRING_TSCP( t2622 );
        CONSTANTEXP( ADR( c2382 ) );
        c2381 = CSTRING_TSCP( t2623 );
        CONSTANTEXP( ADR( c2381 ) );
        c2380 = CSTRING_TSCP( t2624 );
        CONSTANTEXP( ADR( c2380 ) );
        c2369 = CSTRING_TSCP( t2625 );
        CONSTANTEXP( ADR( c2369 ) );
        c2368 = STRINGTOSYMBOL( CSTRING_TSCP( "SET-CDR!" ) );
        CONSTANTEXP( ADR( c2368 ) );
        c2333 = CSTRING_TSCP( t2626 );
        CONSTANTEXP( ADR( c2333 ) );
        c2332 = CSTRING_TSCP( t2627 );
        CONSTANTEXP( ADR( c2332 ) );
        c2331 = CSTRING_TSCP( t2628 );
        CONSTANTEXP( ADR( c2331 ) );
        c2330 = CSTRING_TSCP( t2629 );
        CONSTANTEXP( ADR( c2330 ) );
        c2329 = CSTRING_TSCP( t2630 );
        CONSTANTEXP( ADR( c2329 ) );
        c2328 = CSTRING_TSCP( t2631 );
        CONSTANTEXP( ADR( c2328 ) );
        c2312 = CSTRING_TSCP( t2632 );
        CONSTANTEXP( ADR( c2312 ) );
        c2311 = CSTRING_TSCP( t2633 );
        CONSTANTEXP( ADR( c2311 ) );
        c2300 = CSTRING_TSCP( t2634 );
        CONSTANTEXP( ADR( c2300 ) );
        c2283 = CSTRING_TSCP( t2635 );
        CONSTANTEXP( ADR( c2283 ) );
        c2181 = EMPTYLIST;
        t2636 = STRINGTOSYMBOL( CSTRING_TSCP( "PEEP" ) );
        X1 = t2636;
        t2637 = CSTRING_TSCP( t2638 );
        X1 = CONS( t2637, X1 );
        c2181 = CONS( X1, c2181 );
        t2639 = STRINGTOSYMBOL( CSTRING_TSCP( "LAP" ) );
        X1 = t2639;
        t2640 = CSTRING_TSCP( t2641 );
        X1 = CONS( t2640, X1 );
        c2181 = CONS( X1, c2181 );
        t2642 = STRINGTOSYMBOL( CSTRING_TSCP( "TREE" ) );
        X1 = t2642;
        t2643 = CSTRING_TSCP( t2644 );
        X1 = CONS( t2643, X1 );
        c2181 = CONS( X1, c2181 );
        t2645 = STRINGTOSYMBOL( CSTRING_TSCP( "LAMBDA" ) );
        X1 = t2645;
        t2646 = CSTRING_TSCP( t2647 );
        X1 = CONS( t2646, X1 );
        c2181 = CONS( X1, c2181 );
        t2648 = STRINGTOSYMBOL( CSTRING_TSCP( "TRANSFORM" ) );
        X1 = t2648;
        t2649 = CSTRING_TSCP( t2650 );
        X1 = CONS( t2649, X1 );
        c2181 = CONS( X1, c2181 );
        t2651 = STRINGTOSYMBOL( CSTRING_TSCP( "CLOSED" ) );
        X1 = t2651;
        t2652 = CSTRING_TSCP( t2653 );
        X1 = CONS( t2652, X1 );
        c2181 = CONS( X1, c2181 );
        t2654 = STRINGTOSYMBOL( CSTRING_TSCP( "EXPAND" ) );
        X1 = t2654;
        t2655 = CSTRING_TSCP( t2656 );
        X1 = CONS( t2655, X1 );
        c2181 = CONS( X1, c2181 );
        t2657 = STRINGTOSYMBOL( CSTRING_TSCP( "MACRO" ) );
        X1 = t2657;
        t2658 = CSTRING_TSCP( t2659 );
        X1 = CONS( t2658, X1 );
        c2181 = CONS( X1, c2181 );
        t2660 = STRINGTOSYMBOL( CSTRING_TSCP( "SOURCE" ) );
        X1 = t2660;
        t2661 = CSTRING_TSCP( t2662 );
        X1 = CONS( t2661, X1 );
        c2181 = CONS( X1, c2181 );
        CONSTANTEXP( ADR( c2181 ) );
        c2166 = CSTRING_TSCP( t2663 );
        CONSTANTEXP( ADR( c2166 ) );
        c2155 = CSTRING_TSCP( t2664 );
        CONSTANTEXP( ADR( c2155 ) );
        c2144 = CSTRING_TSCP( t2665 );
        CONSTANTEXP( ADR( c2144 ) );
        c2105 = CSTRING_TSCP( t2666 );
        CONSTANTEXP( ADR( c2105 ) );
        c2101 = CSTRING_TSCP( t2667 );
        CONSTANTEXP( ADR( c2101 ) );
        c2100 = CSTRING_TSCP( t2668 );
        CONSTANTEXP( ADR( c2100 ) );
        c2099 = CSTRING_TSCP( t2669 );
        CONSTANTEXP( ADR( c2099 ) );
        c2098 = CSTRING_TSCP( t2670 );
        CONSTANTEXP( ADR( c2098 ) );
        c2097 = CSTRING_TSCP( t2671 );
        CONSTANTEXP( ADR( c2097 ) );
        c2096 = CSTRING_TSCP( t2672 );
        CONSTANTEXP( ADR( c2096 ) );
        c2093 = CSTRING_TSCP( t2673 );
        CONSTANTEXP( ADR( c2093 ) );
        c2087 = CSTRING_TSCP( t2674 );
        CONSTANTEXP( ADR( c2087 ) );
        c2078 = CSTRING_TSCP( t2675 );
        CONSTANTEXP( ADR( c2078 ) );
        c2069 = CSTRING_TSCP( t2676 );
        CONSTANTEXP( ADR( c2069 ) );
        c2065 = CSTRING_TSCP( t2677 );
        CONSTANTEXP( ADR( c2065 ) );
        c2045 = CSTRING_TSCP( t2678 );
        CONSTANTEXP( ADR( c2045 ) );
        c2019 = EMPTYLIST;
        c2019 = CONS( EMPTYSTRING, c2019 );
        CONSTANTEXP( ADR( c2019 ) );
        c2015 = CSTRING_TSCP( t2679 );
        CONSTANTEXP( ADR( c2015 ) );
        c2013 = CSTRING_TSCP( t2680 );
        CONSTANTEXP( ADR( c2013 ) );
        c2011 = CSTRING_TSCP( t2681 );
        CONSTANTEXP( ADR( c2011 ) );
        c2008 = CSTRING_TSCP( t2682 );
        CONSTANTEXP( ADR( c2008 ) );
        c2006 = CSTRING_TSCP( t2683 );
        CONSTANTEXP( ADR( c2006 ) );
        c2003 = CSTRING_TSCP( t2684 );
        CONSTANTEXP( ADR( c2003 ) );
        c2001 = CSTRING_TSCP( t2685 );
        CONSTANTEXP( ADR( c2001 ) );
}

DEFTSCP( main_scheme__dir_v );
DEFCSTRING( t2686, "SCHEME_DIR" );
DEFTSCP( main_scc_2dversion_v );
DEFCSTRING( t2687, "SCC-VERSION" );
DEFTSCP( main_force_2dld_2dof_2drep_v );
DEFCSTRING( t2688, "FORCE-LD-OF-REP" );
EXTERNTSCPP( screp_read_2deval_2dprint, XAL1( TSCP ) );
EXTERNTSCP( screp_read_2deval_2dprint_v );
DEFTSCP( main_predef_2ddefault_v );
DEFCSTRING( t2689, "PREDEF-DEFAULT" );
EXTERNTSCPP( scrt3_string_2dappend, XAL1( TSCP ) );
EXTERNTSCP( scrt3_string_2dappend_v );
DEFTSCP( main_c_2dinclude_2dfile_v );
DEFCSTRING( t2690, "C-INCLUDE-FILE" );
DEFTSCP( main_c_2dinclude_2ddir_v );
DEFCSTRING( t2691, "C-INCLUDE-DIR" );
DEFTSCP( main_sc_2dlibrary_v );
DEFCSTRING( t2692, "SC-LIBRARY" );
DEFTSCP( main_scxl_2dlibrary_v );
DEFCSTRING( t2693, "SCXL-LIBRARY" );
DEFTSCP( main_sc_2dlibrary__p_v );
DEFCSTRING( t2694, "SC-LIBRARY_P" );
DEFTSCP( main_compile_2dstatic_v );
DEFCSTRING( t2695, "COMPILE-STATIC" );
DEFTSCP( main_module_2dnames_v );
DEFCSTRING( t2696, "MODULE-NAMES" );
DEFTSCP( main_include_2ddirs_v );
DEFCSTRING( t2697, "INCLUDE-DIRS" );
DEFTSCP( main_scc_v );
DEFCSTRING( t2698, "SCC" );
EXTERNTSCPP( scrt1__24__cdr_2derror, XAL1( TSCP ) );
EXTERNTSCP( scrt1__24__cdr_2derror_v );
EXTERNTSCPP( scrt1__24__car_2derror, XAL1( TSCP ) );
EXTERNTSCP( scrt1__24__car_2derror_v );
EXTERNTSCPP( scrt1_equal_3f, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_equal_3f_v );
EXTERNTSCPP( sc_cons, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_cons_v );
EXTERNTSCPP( scrt1_caddr, XAL1( TSCP ) );
EXTERNTSCP( scrt1_caddr_v );
EXTERNTSCPP( scrt1_cdddr, XAL1( TSCP ) );
EXTERNTSCP( scrt1_cdddr_v );
EXTERNTSCPP( scrt1_append_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_append_2dtwo_v );
EXTERNTSCPP( scrt1_assoc, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_assoc_v );
EXTERNTSCPP( main_do_2dc_2dflag, 
             XAL5( TSCP, TSCP, TSCP, TSCP, TSCP ) );
EXTERNTSCP( main_do_2dc_2dflag_v );
EXTERNTSCP( screp_exit_v );
EXTERNTSCP( screp_reset_v );
EXTERNTSCPP( scrt4_catch_2derror, XAL1( TSCP ) );
EXTERNTSCP( scrt4_catch_2derror_v );
EXTERNTSCPP( scrt6_remove_2dfile, XAL1( TSCP ) );
EXTERNTSCP( scrt6_remove_2dfile_v );

TSCP  main_l2325( c2868 )
        TSCP  c2868;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "main_l2325 [inside SCC]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c2868, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c2868, 1 );
        scrt6_remove_2dfile( DISPLAY( 0 ) );
        X3 = scrt6_remove_2dfile( DISPLAY( 1 ) );
        DISPLAY( 0 ) = X1;
        DISPLAY( 1 ) = X2;
        POPSTACKTRACE( X3 );
}

TSCP  main_l2324( c2866 )
        TSCP  c2866;
{
        TSCP  X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( "main_l2324 [inside SCC]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c2866, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c2866, 1 );
        X3 = DISPLAY( 2 );
        DISPLAY( 2 ) = CLOSURE_VAR( c2866, 2 );
        X5 = MAKEPROCEDURE( 0, 
                            0, 
                            main_l2325, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ) ) );
        scrt4_catch_2derror( X5 );
        X5 = DISPLAY( 2 );
        X5 = UNKNOWNCALL( X5, 0 );
        X4 = VIA( PROCEDURE_CODE( X5 ) )( PROCEDURE_CLOSURE( X5 ) );
        DISPLAY( 0 ) = X1;
        DISPLAY( 1 ) = X2;
        DISPLAY( 2 ) = X3;
        POPSTACKTRACE( X4 );
}

EXTERNTSCPP( scrt5_open_2doutput_2dfile, XAL1( TSCP ) );
EXTERNTSCP( scrt5_open_2doutput_2dfile_v );
EXTERNTSCPP( scrt6_format, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt6_format_v );
EXTERNTSCPP( scrt1_reverse, XAL1( TSCP ) );
EXTERNTSCP( scrt1_reverse_v );
EXTERNTSCPP( scdebug_error, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scdebug_error_v );
EXTERNTSCPP( scrt5_close_2doutput_2dport, XAL1( TSCP ) );
EXTERNTSCP( scrt5_close_2doutput_2dport_v );
EXTERNTSCPP( scrt4_system, XAL1( TSCP ) );
EXTERNTSCP( scrt4_system_v );
EXTERNTSCPP( sc_apply_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( sc_apply_2dtwo_v );
EXTERNTSCPP( scrt1_cons_2a, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_cons_2a_v );
EXTERNTSCPP( scrt1_member, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt1_member_v );

TSCP  main_l2453( c2925 )
        TSCP  c2925;
{
        TSCP  X3, X2, X1;

        PUSHSTACKTRACE( "main_l2453 [inside SCC]" );
        X1 = DISPLAY( 0 );
        DISPLAY( 0 ) = CLOSURE_VAR( c2925, 0 );
        X2 = DISPLAY( 1 );
        DISPLAY( 1 ) = CLOSURE_VAR( c2925, 1 );
        scrt6_remove_2dfile( DISPLAY( 0 ) );
        X3 = scrt6_remove_2dfile( DISPLAY( 1 ) );
        DISPLAY( 0 ) = X1;
        DISPLAY( 1 ) = X2;
        POPSTACKTRACE( X3 );
}

TSCP  main_scc( c2022 )
        TSCP  c2022;
{
        TSCP  X19, 
              X18, 
              X17, 
              X16, 
              X15, 
              X14, 
              X13, 
              X12, 
              X11, 
              X10, 
              X9, 
              X8, X7, X6, X5, X4, X3, X2, X1;
        TSCP  SD0 = DISPLAY( 0 );
        TSCP  SD1 = DISPLAY( 1 );
        TSCP  SD2 = DISPLAY( 2 );
        TSCP  SDVAL;

        PUSHSTACKTRACE( t2698 );
        X1 = EMPTYLIST;
        X2 = FALSEVALUE;
        X3 = TRUEVALUE;
        X4 = FALSEVALUE;
        X5 = EMPTYLIST;
        DISPLAY( 0 ) = c2454;
        DISPLAY( 1 ) = c2455;
        X6 = EMPTYLIST;
        X7 = c2456;
        X7 = CONS( X7, EMPTYLIST );
        X6 = CONS( X6, EMPTYLIST );
        X5 = CONS( X5, EMPTYLIST );
        X4 = CONS( X4, EMPTYLIST );
        X3 = CONS( X3, EMPTYLIST );
        X2 = CONS( X2, EMPTYLIST );
        X1 = CONS( X1, EMPTYLIST );
        if  ( EQ( TSCPTAG( c2022 ), PAIRTAG ) )  goto L2702;
        scrt1__24__cdr_2derror( c2022 );
L2702:
        X8 = PAIR_CDR( c2022 );
        X9 = X8;
L2706:
        if  ( FALSE( X9 ) )  goto L2735;
        if  ( EQ( TSCPTAG( X9 ), PAIRTAG ) )  goto L2710;
        scrt1__24__car_2derror( X9 );
L2710:
        X10 = PAIR_CAR( X9 );
        X11 = scrt1_equal_3f( X10, c2045 );
        if  ( FALSE( X11 ) )  goto L2734;
        X12 = PAIR_CDR( X9 );
        if  ( FALSE( X12 ) )  goto L2734;
        X13 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X13 ), PAIRTAG ) )  goto L2724;
        scrt1__24__cdr_2derror( X13 );
L2724:
        if  ( FALSE( PAIR_CDR( X13 ) ) )  goto L2734;
        X16 = CONS( c2312, EMPTYLIST );
        X16 = CONS( scrt1_caddr( X9 ), X16 );
        X16 = CONS( c2311, X16 );
        X17 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X17 ), PAIRTAG ) )  goto L2731;
        scrt1__24__car_2derror( X17 );
L2731:
        X16 = CONS( PAIR_CAR( X17 ), X16 );
        X15 = scrt3_string_2dappend( CONS( c2300, X16 ) );
        X14 = sc_cons( X15, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X1 ), X14 );
        X9 = scrt1_cdddr( X9 );
        GOBACK( L2706 );
L2734:
        if  ( FALSE( scrt1_equal_3f( X10, c2065 ) ) )  goto L2736;
        X11 = TRUEVALUE;
        SETGEN( PAIR_CAR( X2 ), X11 );
        X9 = PAIR_CDR( X9 );
        GOBACK( L2706 );
L2736:
        X11 = scrt1_equal_3f( X10, c2069 );
        if  ( FALSE( X11 ) )  goto L2757;
        if  ( FALSE( PAIR_CDR( X9 ) ) )  goto L2757;
        X15 = CONS( c2283, EMPTYLIST );
        X16 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X16 ), PAIRTAG ) )  goto L2750;
        scrt1__24__car_2derror( X16 );
L2750:
        X14 = scrt3_string_2dappend( CONS( PAIR_CAR( X16 ), X15 ) );
        X13 = sc_cons( X14, EMPTYLIST );
        X12 = X13;
        main_include_2ddirs_v = scrt1_append_2dtwo( main_include_2ddirs_v, 
                                                    X12 );
        X12 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X12 ), PAIRTAG ) )  goto L2755;
        scrt1__24__cdr_2derror( X12 );
L2755:
        X9 = PAIR_CDR( X12 );
        GOBACK( L2706 );
L2757:
        X11 = scrt1_equal_3f( X10, c2078 );
        if  ( FALSE( X11 ) )  goto L2774;
        if  ( FALSE( PAIR_CDR( X9 ) ) )  goto L2774;
        X13 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X13 ), PAIRTAG ) )  goto L2768;
        scrt1__24__car_2derror( X13 );
L2768:
        X12 = PAIR_CAR( X13 );
        main_module_2dnames_v = sc_cons( X12, main_module_2dnames_v );
        X12 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X12 ), PAIRTAG ) )  goto L2772;
        scrt1__24__cdr_2derror( X12 );
L2772:
        X9 = PAIR_CDR( X12 );
        GOBACK( L2706 );
L2774:
        X11 = scrt1_equal_3f( X10, c2087 );
        if  ( FALSE( X11 ) )  goto L2807;
        if  ( FALSE( PAIR_CDR( X9 ) ) )  goto L2807;
        X12 = CONS( c2006, EMPTYLIST );
        X12 = CONS( c2283, X12 );
        X13 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X13 ), PAIRTAG ) )  goto L2785;
        scrt1__24__car_2derror( X13 );
L2785:
        main_predef_2ddefault_v = scrt3_string_2dappend( CONS( PAIR_CAR( X13 ), 
                                                               X12 ) );
        X12 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X12 ), PAIRTAG ) )  goto L2789;
        scrt1__24__car_2derror( X12 );
L2789:
        main_c_2dinclude_2ddir_v = PAIR_CAR( X12 );
        X12 = CONS( c2011, EMPTYLIST );
        X12 = CONS( c2283, X12 );
        X13 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X13 ), PAIRTAG ) )  goto L2793;
        scrt1__24__car_2derror( X13 );
L2793:
        main_sc_2dlibrary_v = scrt3_string_2dappend( CONS( PAIR_CAR( X13 ), 
                                                           X12 ) );
        X12 = CONS( c2015, EMPTYLIST );
        X12 = CONS( c2283, X12 );
        X13 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X13 ), PAIRTAG ) )  goto L2797;
        scrt1__24__car_2derror( X13 );
L2797:
        main_sc_2dlibrary__p_v = scrt3_string_2dappend( CONS( PAIR_CAR( X13 ), 
                                                              X12 ) );
        X12 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X12 ), PAIRTAG ) )  goto L2801;
        scrt1__24__car_2derror( X12 );
L2801:
        main_c_2dinclude_2ddir_v = PAIR_CAR( X12 );
        X12 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X12 ), PAIRTAG ) )  goto L2805;
        scrt1__24__cdr_2derror( X12 );
L2805:
        X9 = PAIR_CDR( X12 );
        GOBACK( L2706 );
L2807:
        if  ( FALSE( scrt1_equal_3f( X10, c2093 ) ) )  goto L2808;
        X11 = SYMBOL_VALUE( sc_2dlog_2ddefault_v );
        SETGEN( PAIR_CAR( X6 ), X11 );
        X9 = PAIR_CDR( X9 );
        GOBACK( L2706 );
L2808:
        X11 = scrt1_assoc( X10, c2181 );
        if  ( FALSE( X11 ) )  goto L2813;
        if  ( EQ( TSCPTAG( X11 ), PAIRTAG ) )  goto L2817;
        scrt1__24__cdr_2derror( X11 );
L2817:
        X13 = PAIR_CDR( X11 );
        X12 = sc_cons( X13, PAIR_CAR( X6 ) );
        SETGEN( PAIR_CAR( X6 ), X12 );
        X9 = PAIR_CDR( X9 );
        GOBACK( L2706 );
L2813:
        if  ( FALSE( scrt1_equal_3f( X10, c2096 ) ) )  goto L2820;
        X12 = sc_cons( c2166, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X1 ), X12 );
        X9 = PAIR_CDR( X9 );
        GOBACK( L2706 );
L2820:
        if  ( FALSE( scrt1_equal_3f( X10, c2097 ) ) )  goto L2824;
        main_compile_2dstatic_v = TRUEVALUE;
        X9 = PAIR_CDR( X9 );
        GOBACK( L2706 );
L2824:
        if  ( FALSE( scrt1_equal_3f( X10, c2098 ) ) )  goto L2828;
        X12 = sc_cons( c2155, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X1 ), X12 );
        X9 = PAIR_CDR( X9 );
        GOBACK( L2706 );
L2828:
        if  ( FALSE( scrt1_equal_3f( X10, c2099 ) ) )  goto L2832;
        X12 = FALSEVALUE;
        SETGEN( PAIR_CAR( X3 ), X12 );
        X9 = PAIR_CDR( X9 );
        GOBACK( L2706 );
L2832:
        if  ( FALSE( scrt1_equal_3f( X10, c2100 ) ) )  goto L2836;
        X12 = sc_cons( c2144, PAIR_CAR( X1 ) );
        SETGEN( PAIR_CAR( X1 ), X12 );
        X9 = PAIR_CDR( X9 );
        GOBACK( L2706 );
L2836:
        if  ( FALSE( scrt1_equal_3f( X10, c2101 ) ) )  goto L2840;
        X12 = TRUEVALUE;
        SETGEN( PAIR_CAR( X4 ), X12 );
        X9 = PAIR_CDR( X9 );
        GOBACK( L2706 );
L2840:
        X12 = scrt1_equal_3f( X10, c2105 );
        if  ( FALSE( X12 ) )  goto L2860;
        if  ( FALSE( PAIR_CDR( X9 ) ) )  goto L2860;
        X14 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X14 ), PAIRTAG ) )  goto L2854;
        scrt1__24__car_2derror( X14 );
L2854:
        X13 = PAIR_CAR( X14 );
        SETGEN( PAIR_CAR( X7 ), X13 );
        X13 = PAIR_CDR( X9 );
        if  ( EQ( TSCPTAG( X13 ), PAIRTAG ) )  goto L2858;
        scrt1__24__cdr_2derror( X13 );
L2858:
        X9 = PAIR_CDR( X13 );
        GOBACK( L2706 );
L2860:
        X12 = main_do_2dc_2dflag( X10, 
                                  PAIR_CAR( X1 ), 
                                  PAIR_CAR( X6 ), 
                                  PAIR_CAR( X3 ), 
                                  PAIR_CAR( X2 ) );
        X11 = sc_cons( X12, PAIR_CAR( X5 ) );
        SETGEN( PAIR_CAR( X5 ), X11 );
        X9 = PAIR_CDR( X9 );
        GOBACK( L2706 );
L2735:
        if  ( FALSE( PAIR_CAR( X4 ) ) )  goto L2863;
        X8 = screp_exit_v;
        X8 = UNKNOWNCALL( X8, 0 );
        VIA( PROCEDURE_CODE( X8 ) )( PROCEDURE_CLOSURE( X8 ) );
L2863:
        DISPLAY( 2 ) = screp_reset_v;
        screp_reset_v = MAKEPROCEDURE( 0, 
                                       0, 
                                       main_l2324, 
                                       MAKECLOSURE( EMPTYLIST, 
                                                    3, 
                                                    DISPLAY( 0 ), 
                                                    DISPLAY( 1 ), 
                                                    DISPLAY( 2 ) ) );
        if  ( FALSE( PAIR_CAR( X2 ) ) )  goto L2870;
        X8 = scrt5_open_2doutput_2dfile( DISPLAY( 0 ) );
        X9 = CONS( main_c_2dinclude_2dfile_v, EMPTYLIST );
        X9 = CONS( main_c_2dinclude_2ddir_v, X9 );
        scrt6_format( X8, CONS( c2328, X9 ) );
        scrt6_format( X8, CONS( c2329, EMPTYLIST ) );
        scrt6_format( X8, CONS( c2330, EMPTYLIST ) );
        scrt6_format( X8, CONS( c2331, EMPTYLIST ) );
        scrt6_format( X8, CONS( c2332, EMPTYLIST ) );
        scrt6_format( X8, CONS( c2333, EMPTYLIST ) );
        X10 = scrt1_reverse( main_module_2dnames_v );
        X9 = sc_cons( c2381, X10 );
        X10 = X9;
        X11 = EMPTYLIST;
        X12 = EMPTYLIST;
L2875:
        if  ( EQ( _S2CUINT( X10 ), _S2CUINT( EMPTYLIST ) ) )  goto L2883;
        if  ( EQ( TSCPTAG( X10 ), PAIRTAG ) )  goto L2879;
        scrt1__24__car_2derror( X10 );
L2879:
        X15 = CONS( PAIR_CAR( X10 ), EMPTYLIST );
        X14 = scrt6_format( X8, CONS( c2380, X15 ) );
        X13 = sc_cons( X14, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X11 ), _S2CUINT( EMPTYLIST ) ) )  goto L2882;
        X14 = PAIR_CDR( X10 );
        X12 = X13;
        X11 = X13;
        X10 = X14;
        GOBACK( L2875 );
L2882:
        X14 = PAIR_CDR( X10 );
        if  ( EQ( TSCPTAG( X12 ), PAIRTAG ) )  goto L2887;
        scdebug_error( c2368, 
                       c2369, CONS( X12, EMPTYLIST ) );
L2887:
        X12 = SETGEN( PAIR_CDR( X12 ), X13 );
        X10 = X14;
        GOBACK( L2875 );
L2883:
        scrt6_format( X8, CONS( c2382, EMPTYLIST ) );
        scrt6_format( X8, CONS( c2383, EMPTYLIST ) );
        scrt6_format( X8, CONS( c2384, EMPTYLIST ) );
        scrt5_close_2doutput_2dport( X8 );
        X11 = sc_cons( DISPLAY( 0 ), EMPTYLIST );
        X10 = X11;
        X9 = scrt1_append_2dtwo( PAIR_CAR( X5 ), X10 );
        SETGEN( PAIR_CAR( X5 ), X9 );
L2870:
        X14 = scrt1_reverse( PAIR_CAR( X5 ) );
        if  ( FALSE( main_compile_2dstatic_v ) )  goto L2892;
        if  ( FALSE( scrt1_member( c2444, PAIR_CAR( X5 ) ) ) )  goto L2894;
        X17 = sc_cons( c2447, EMPTYLIST );
        X16 = sc_cons( main_sc_2dlibrary__p_v, X17 );
        X15 = X16;
        goto L2906;
L2894:
        if  ( FALSE( scrt1_member( c2435, PAIR_CAR( X5 ) ) ) )  goto L2897;
        X15 = EMPTYLIST;
        goto L2906;
L2897:
        X16 = SYMBOL_VALUE( with_2dmodules_v );
        if  ( FALSE( scrt1_member( c2436, X16 ) ) )  goto L2899;
        X19 = sc_cons( c2447, EMPTYLIST );
        X18 = sc_cons( c2450, X19 );
        X17 = sc_cons( main_scxl_2dlibrary_v, X18 );
        X16 = sc_cons( main_sc_2dlibrary_v, X17 );
        X15 = X16;
        goto L2906;
L2899:
        X17 = sc_cons( c2447, EMPTYLIST );
        X16 = sc_cons( main_sc_2dlibrary_v, X17 );
        X15 = X16;
        goto L2906;
L2892:
        if  ( FALSE( scrt1_member( c2435, PAIR_CAR( X5 ) ) ) )  goto L2903;
        X15 = EMPTYLIST;
        goto L2906;
L2903:
        X16 = SYMBOL_VALUE( with_2dmodules_v );
        if  ( FALSE( scrt1_member( c2436, X16 ) ) )  goto L2905;
        X16 = sc_cons( c2443, EMPTYLIST );
        X15 = X16;
        goto L2906;
L2905:
        X16 = sc_cons( c2440, EMPTYLIST );
        X15 = X16;
L2906:
        X13 = scrt1_append_2dtwo( X14, X15 );
        X14 = X13;
        X15 = EMPTYLIST;
        X16 = EMPTYLIST;
L2911:
        if  ( NEQ( _S2CUINT( X14 ), _S2CUINT( EMPTYLIST ) ) )  goto L2912;
        X12 = X15;
        goto L2919;
L2912:
        if  ( EQ( TSCPTAG( X14 ), PAIRTAG ) )  goto L2915;
        scrt1__24__car_2derror( X14 );
L2915:
        X19 = CONS( PAIR_CAR( X14 ), EMPTYLIST );
        X18 = scrt3_string_2dappend( CONS( c2311, X19 ) );
        X17 = sc_cons( X18, EMPTYLIST );
        if  ( NEQ( _S2CUINT( X15 ), _S2CUINT( EMPTYLIST ) ) )  goto L2918;
        X18 = PAIR_CDR( X14 );
        X16 = X17;
        X15 = X17;
        X14 = X18;
        GOBACK( L2911 );
L2918:
        X18 = PAIR_CDR( X14 );
        if  ( EQ( TSCPTAG( X16 ), PAIRTAG ) )  goto L2923;
        scdebug_error( c2368, 
                       c2369, CONS( X16, EMPTYLIST ) );
L2923:
        X16 = SETGEN( PAIR_CDR( X16 ), X17 );
        X14 = X18;
        GOBACK( L2911 );
L2919:
        X13 = scrt1_cons_2a( EMPTYLIST, EMPTYLIST );
        X11 = CONS( scrt1_append_2dtwo( X12, X13 ), 
                    EMPTYLIST );
        X11 = CONS( main_c_2dinclude_2ddir_v, X11 );
        X10 = scrt1_cons_2a( PAIR_CAR( X7 ), 
                             CONS( c2390, X11 ) );
        X9 = sc_apply_2dtwo( scrt3_string_2dappend_v, X10 );
        X8 = scrt4_system( X9 );
        if  ( EQ( _S2CUINT( _TSCP( 0 ) ), _S2CUINT( X8 ) ) )  goto L2890;
        X8 = screp_reset_v;
        X8 = UNKNOWNCALL( X8, 0 );
        VIA( PROCEDURE_CODE( X8 ) )( PROCEDURE_CLOSURE( X8 ) );
L2890:
        X8 = MAKEPROCEDURE( 0, 
                            0, 
                            main_l2453, 
                            MAKECLOSURE( EMPTYLIST, 
                                         2, 
                                         DISPLAY( 0 ), 
                                         DISPLAY( 1 ) ) );
        SDVAL = scrt4_catch_2derror( X8 );
        DISPLAY( 0 ) = SD0;
        DISPLAY( 1 ) = SD1;
        DISPLAY( 2 ) = SD2;
        POPSTACKTRACE( SDVAL );
}

DEFTSCP( main_do_2dc_2dflag_v );
DEFCSTRING( t2927, "DO-C-FLAG" );
EXTERNTSCPP( scrt3_substring, XAL3( TSCP, TSCP, TSCP ) );
EXTERNTSCP( scrt3_substring_v );
EXTERNTSCPP( scrt2__2d_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__2d_2dtwo_v );
EXTERNTSCPP( scrt2_max_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2_max_2dtwo_v );
EXTERNTSCPP( scrt2__3e_2dtwo, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt2__3e_2dtwo_v );
EXTERNTSCPP( scrt3_string_3d_3f, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt3_string_3d_3f_v );
EXTERNTSCPP( scrt6_read, XAL1( TSCP ) );
EXTERNTSCP( scrt6_read_v );
EXTERNTSCPP( scrt5_open_2dinput_2dstring, XAL1( TSCP ) );
EXTERNTSCP( scrt5_open_2dinput_2dstring_v );
EXTERNTSCPP( scrt5_open_2dinput_2dfile, XAL1( TSCP ) );
EXTERNTSCP( scrt5_open_2dinput_2dfile_v );
EXTERNTSCP( scrt5_stderr_2dport_v );
EXTERNTSCPP( scrt2_zero_3f, XAL1( TSCP ) );
EXTERNTSCP( scrt2_zero_3f_v );
EXTERNTSCPP( scrt6_rename_2dfile, XAL2( TSCP, TSCP ) );
EXTERNTSCP( scrt6_rename_2dfile_v );

TSCP  main_do_2dc_2dflag( a2458, 
                          f2459, l2460, s2461, i2462 )
        TSCP  a2458, f2459, l2460, s2461, i2462;
{
        TSCP  X7, X6, X5, X4, X3, X2, X1;

        PUSHSTACKTRACE( t2927 );
        if  ( AND( EQ( TSCPTAG( a2458 ), EXTENDEDTAG ), 
                   EQ( TSCP_EXTENDEDTAG( a2458 ), STRINGTAG ) )
            )  goto L2930;
        scdebug_error( c2557, 
                       c2558, CONS( a2458, EMPTYLIST ) );
L2930:
        X3 = C_FIXED( STRING_LENGTH( a2458 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 12 ) ) ), 
                      3 ) )  goto L2933;
        X6 = _TSCP( IDIFFERENCE( _S2CINT( X3 ), 
                                 _S2CINT( _TSCP( 12 ) ) ) );
        goto L2934;
L2933:
        X6 = scrt2__2d_2dtwo( X3, _TSCP( 12 ) );
L2934:
        if  ( BITAND( BITOR( _S2CINT( _TSCP( 0 ) ), 
                             _S2CINT( X6 ) ), 
                      3 ) )  goto L2936;
        if  ( LTE( _S2CINT( _TSCP( 0 ) ), _S2CINT( X6 ) ) )  goto L2938;
        X5 = _TSCP( 0 );
        goto L2937;
L2938:
        X5 = X6;
        goto L2937;
L2936:
        X5 = scrt2_max_2dtwo( _TSCP( 0 ), X6 );
L2937:
        X4 = scrt3_substring( a2458, _TSCP( 0 ), X5 );
        X5 = CONS( c2540, EMPTYLIST );
        X1 = scrt3_string_2dappend( CONS( X4, X5 ) );
        X5 = CONS( c2539, EMPTYLIST );
        X2 = scrt3_string_2dappend( CONS( X4, X5 ) );
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 12 ) ) ), 
                      3 ) )  goto L2944;
        if  ( GT( _S2CINT( X3 ), _S2CINT( _TSCP( 12 ) ) ) )  goto L2948;
        POPSTACKTRACE( a2458 );
L2944:
        if  ( TRUE( scrt2__3e_2dtwo( X3, _TSCP( 12 ) ) ) )  goto L2948;
        POPSTACKTRACE( a2458 );
L2948:
        if  ( BITAND( BITOR( _S2CINT( X3 ), 
                             _S2CINT( _TSCP( 12 ) ) ), 
                      3 ) )  goto L2953;
        X5 = _TSCP( IDIFFERENCE( _S2CINT( X3 ), 
                                 _S2CINT( _TSCP( 12 ) ) ) );
        goto L2954;
L2953:
        X5 = scrt2__2d_2dtwo( X3, _TSCP( 12 ) );
L2954:
        X4 = scrt3_substring( a2458, X5, X3 );
        if  ( FALSE( scrt3_string_3d_3f( X4, c2488 ) ) )  goto L2951;
        X4 = CONS( a2458, EMPTYLIST );
        scrt6_format( TRUEVALUE, CONS( c2490, X4 ) );
        X4 = SYMBOL_VALUE( initialize_2dcompile_v );
        X4 = UNKNOWNCALL( X4, 0 );
        VIA( PROCEDURE_CODE( X4 ) )( PROCEDURE_CLOSURE( X4 ) );
        X4 = f2459;
L2957:
        if  ( EQ( _S2CUINT( X4 ), _S2CUINT( EMPTYLIST ) ) )  goto L2958;
        if  ( EQ( TSCPTAG( X4 ), PAIRTAG ) )  goto L2962;
        scrt1__24__car_2derror( X4 );
L2962:
        X5 = PAIR_CAR( X4 );
        X7 = scrt6_read( CONS( scrt5_open_2dinput_2dstring( X5 ), 
                               EMPTYLIST ) );
        X6 = SYMBOL_VALUE( do_2ddefine_2dconstant_v );
        X6 = UNKNOWNCALL( X6, 1 );
        VIA( PROCEDURE_CODE( X6 ) )( X7, PROCEDURE_CLOSURE( X6 ) );
        X4 = PAIR_CDR( X4 );
        GOBACK( L2957 );
L2958:
        SETGENTL( SYMBOL_VALUE( sc_2dinclude_2ddirs_v ), 
                  main_include_2ddirs_v );
        X5 = scrt5_open_2dinput_2dfile( a2458 );
        X4 = sc_cons( X5, EMPTYLIST );
        SETGENTL( SYMBOL_VALUE( sc_2dinput_v ), X4 );
        SETGENTL( SYMBOL_VALUE( sc_2dsource_2dname_v ), a2458 );
        SETGENTL( SYMBOL_VALUE( sc_2dicode_v ), 
                  scrt5_open_2doutput_2dfile( X1 ) );
        SETGENTL( SYMBOL_VALUE( sc_2derror_v ), 
                  scrt5_stderr_2dport_v );
        SETGENTL( SYMBOL_VALUE( sc_2dlog_v ), l2460 );
        SETGENTL( SYMBOL_VALUE( sc_2dstack_2dtrace_v ), s2461 );
        SETGENTL( SYMBOL_VALUE( sc_2dinterpreter_v ), i2462 );
        X4 = SYMBOL_VALUE( docompile_v );
        X4 = UNKNOWNCALL( X4, 0 );
        VIA( PROCEDURE_CODE( X4 ) )( PROCEDURE_CLOSURE( X4 ) );
        X4 = SYMBOL_VALUE( sc_2derror_2dcnt_v );
        if  ( NEQ( TSCPTAG( X4 ), FIXNUMTAG ) )  goto L2969;
        if  ( NEQ( _S2CUINT( X4 ), _S2CUINT( _TSCP( 0 ) ) ) )  goto L2973;
        goto L2976;
L2969:
        if  ( TRUE( scrt2_zero_3f( X4 ) ) )  goto L2976;
L2973:
        X5 = screp_reset_v;
        X5 = UNKNOWNCALL( X5, 0 );
        VIA( PROCEDURE_CODE( X5 ) )( PROCEDURE_CLOSURE( X5 ) );
L2976:
        X4 = SYMBOL_VALUE( module_2dname_v );
        main_module_2dnames_v = sc_cons( X4, main_module_2dnames_v );
        X4 = SYMBOL_VALUE( close_2dsc_2dfiles_v );
        X4 = UNKNOWNCALL( X4, 0 );
        VIA( PROCEDURE_CODE( X4 ) )( PROCEDURE_CLOSURE( X4 ) );
        scrt6_rename_2dfile( X1, X2 );
        POPSTACKTRACE( X2 );
L2951:
        POPSTACKTRACE( a2458 );
}

void  main__init(){}

static void  init_modules( compiler_version )
        char *compiler_version;
{
        scrt2__init();
        scdebug__init();
        scrt5__init();
        scrt6__init();
        scrt4__init();
        scrt1__init();
        scrt3__init();
        screp__init();
        callcode__init();
        closeana__init();
        compile__init();
        expform__init();
        gencode__init();
        lambdacode__init();
        lambdaexp__init();
        lap__init();
        macros__init();
        misccode__init();
        miscexp__init();
        plist__init();
        readtext__init();
        transform__init();
        MAXDISPLAY( 3 );
}

main( argc, argv )
        int argc;  char *argv[];
{
        TSCP  X1;

        static int  init = 0;
        if  (init)  return;
        init = 1;
        INITHEAP( 0, argc, argv, main_scc );
        init_constants();
        init_modules( "(main SCHEME->C COMPILER 15mar93-FreeBSD)" );
        INITIALIZEVAR( t2686, 
                       ADR( main_scheme__dir_v ), c2001 );
        INITIALIZEVAR( t2687, 
                       ADR( main_scc_2dversion_v ), c2003 );
        INITIALIZEVAR( t2688, 
                       ADR( main_force_2dld_2dof_2drep_v ), 
                       screp_read_2deval_2dprint_v );
        X1 = CONS( c2006, EMPTYLIST );
        INITIALIZEVAR( t2689, 
                       ADR( main_predef_2ddefault_v ), 
                       scrt3_string_2dappend( CONS( main_scheme__dir_v, 
                                                    X1 ) ) );
        INITIALIZEVAR( t2690, 
                       ADR( main_c_2dinclude_2dfile_v ), c2008 );
        INITIALIZEVAR( t2691, 
                       ADR( main_c_2dinclude_2ddir_v ), 
                       main_scheme__dir_v );
        X1 = CONS( c2011, EMPTYLIST );
        INITIALIZEVAR( t2692, 
                       ADR( main_sc_2dlibrary_v ), 
                       scrt3_string_2dappend( CONS( main_scheme__dir_v, 
                                                    X1 ) ) );
        X1 = CONS( c2013, EMPTYLIST );
        INITIALIZEVAR( t2693, 
                       ADR( main_scxl_2dlibrary_v ), 
                       scrt3_string_2dappend( CONS( main_scheme__dir_v, 
                                                    X1 ) ) );
        X1 = CONS( c2015, EMPTYLIST );
        INITIALIZEVAR( t2694, 
                       ADR( main_sc_2dlibrary__p_v ), 
                       scrt3_string_2dappend( CONS( main_scheme__dir_v, 
                                                    X1 ) ) );
        INITIALIZEVAR( t2695, 
                       ADR( main_compile_2dstatic_v ), 
                       FALSEVALUE );
        INITIALIZEVAR( t2696, 
                       ADR( main_module_2dnames_v ), EMPTYLIST );
        INITIALIZEVAR( t2697, 
                       ADR( main_include_2ddirs_v ), c2019 );
        INITIALIZEVAR( t2698, 
                       ADR( main_scc_v ), 
                       MAKEPROCEDURE( 1, 
                                      0, main_scc, EMPTYLIST ) );
        INITIALIZEVAR( t2927, 
                       ADR( main_do_2dc_2dflag_v ), 
                       MAKEPROCEDURE( 5, 
                                      0, 
                                      main_do_2dc_2dflag, EMPTYLIST ) );
        main_scc( CLARGUMENTS( argc, argv ) );
        SCHEMEEXIT();
}
