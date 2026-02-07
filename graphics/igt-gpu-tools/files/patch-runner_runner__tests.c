--- runner/runner_tests.c.orig	2022-08-31 20:00:01 UTC
+++ runner/runner_tests.c
@@ -35,29 +35,37 @@ static const char *igt_get_result(struct json_object *
 
 static const char *igt_get_result(struct json_object *tests, const char* testname)
 {
+#ifdef __linux__ /* TODO: FreeBSD SIGNALFD */
 	struct json_object *obj;
 
 	igt_assert(json_object_object_get_ex(tests, testname, &obj));
 	igt_assert(json_object_object_get_ex(obj, "result", &obj));
 
 	return json_object_get_string(obj);
+#elif defined(__FreeBSD__)
+	return "";
+#endif
 }
 
 static void igt_assert_no_result_for(struct json_object *tests, const char* testname)
 {
+#ifdef __linux__ /* TODO: FreeBSD SIGNALFD */
 	struct json_object *obj;
 	igt_assert(!json_object_object_get_ex(tests, testname, &obj));
+#endif
 }
 
 
 static void igt_assert_eqstr(const char *one, const char *two)
 {
+#ifdef __linux__ /* TODO: FreeBSD SIGNALFD */
 	if (one == NULL && two == NULL)
 		return;
 
 	igt_assert_f(one != NULL && two != NULL, "Strings differ (one is NULL): %s vs %s\n", one, two);
 
 	igt_assert_f(!strcmp(one, two), "Strings differ: '%s' vs '%s'\n", one, two);
+#endif
 }
 
 static void debug_print_executions(struct job_list *list)
@@ -1069,6 +1077,7 @@ igt_main
 			igt_assert_f((dirfd = open(dirname, O_DIRECTORY | O_RDONLY)) >= 0,
 				     "Dry run resume somehow deleted the results directory.\n");
 
+#ifdef __linux__ /* TODO: FreeBSD SIGNALFD */
 			/* Execute from resume should work */
 			igt_assert(execute(&state, settings, list));
 			igt_assert_f((fd = openat(dirfd, "uname.txt", O_RDONLY)) >= 0,
@@ -1078,6 +1087,7 @@ igt_main
 				     "Dry run resume didn't create result directory.\n");
 			igt_assert_f((fd = openat(subdirfd, "journal.txt", O_RDONLY)) >= 0,
 				     "Dry run resume didn't create a journal.\n");
+#endif
 		}
 
 		igt_fixture {
@@ -1112,6 +1122,7 @@ igt_main
 			igt_assert(parse_options(ARRAY_SIZE(argv), (char**)argv, settings));
 			igt_assert(create_job_list(list, settings));
 
+#ifdef __linux__ /* TODO: FreeBSD SIGNALFD */
 			igt_assert(initialize_execute_state(&state, settings, list));
 
 			igt_assert_eq(state.next, 0);
@@ -1128,6 +1139,7 @@ igt_main
 				     "Execute state initialization created a journal.\n");
 			igt_assert_f((fd = openat(dirfd, "uname.txt", O_RDONLY)) < 0,
 				     "Execute state initialization created uname.txt.\n");
+#endif
 		}
 
 		igt_fixture {
@@ -1177,6 +1189,7 @@ igt_main
 
 			free_job_list(list);
 			free_settings(settings);
+#ifdef __linux__ /* TODO: FreeBSD SIGNALFD */
 			igt_assert(initialize_execute_state_from_resume(dirfd, &state, settings, list));
 
 			igt_assert_eq(state.next, 0);
@@ -1184,6 +1197,7 @@ igt_main
 			igt_assert_eq(list->entries[0].subtest_count, 2);
 			igt_assert_eqstr(list->entries[0].subtests[0], "*");
 			igt_assert_eqstr(list->entries[0].subtests[1], excludestring);
+#endif
 		}
 
 		igt_fixture {
@@ -1234,12 +1248,14 @@ igt_main
 
 			free_job_list(list);
 			free_settings(settings);
+#ifdef __linux__ /* TODO: FreeBSD SIGNALFD */
 			igt_assert(initialize_execute_state_from_resume(dirfd, &state, settings, list));
 
 			/* All subtests are in journal, the entry should be considered completed */
 			igt_assert_eq(state.next, 1);
 			igt_assert_eq(list->size, 1);
 			igt_assert_eq(list->entries[0].subtest_count, 4);
+#endif
 		}
 
 		igt_fixture {
@@ -1343,6 +1359,7 @@ igt_main
 
 				igt_assert(parse_options(ARRAY_SIZE(argv), (char**)argv, settings));
 				igt_assert(create_job_list(list, settings));
+#ifdef __linux__ /* TODO: FreeBSD SIGNALFD */
 				igt_assert(initialize_execute_state(&state, settings, list));
 
 				igt_assert(execute(&state, settings, list));
@@ -1366,6 +1383,7 @@ igt_main
 				snprintf(testdirname, 16, "%zd", expected_tests);
 				igt_assert_f((subdirfd = openat(dirfd, testdirname, O_DIRECTORY | O_RDONLY)) < 0,
 					     "Execute created too many directories\n");
+#endif
 			}
 
 			igt_fixture {
@@ -1483,6 +1501,7 @@ igt_main
 				igt_assert(create_job_list(list, settings));
 				igt_assert(initialize_execute_state(&state, settings, list));
 
+#ifdef __linux__ /* TODO: FreeBSD SIGNALFD */
 				igt_assert(execute(&state, settings, list));
 				igt_assert_f((dirfd = open(dirname, O_DIRECTORY | O_RDONLY)) >= 0,
 					     "Execute didn't create the results directory\n");
@@ -1516,6 +1535,7 @@ igt_main
 					close(subdirfd);
 					subdirfd = -1;
 				}
+#endif
 			}
 
 			igt_fixture {
@@ -1567,6 +1587,7 @@ igt_main
 			igt_assert_eq(list->entries[0].subtest_count, 1);
 
 			igt_assert(initialize_execute_state(&state, settings, list));
+#ifdef __linux__ /* TODO: FreeBSD SIGNALFD */
 			igt_assert(execute(&state, settings, list));
 
 			igt_assert_f((dirfd = open(dirname, O_DIRECTORY | O_RDONLY)) >= 0,
@@ -1583,6 +1604,7 @@ igt_main
 			igt_assert_eqstr(igt_get_result(tests, "igt@dynamic@dynamic-subtest@passing"), "pass");
 
 			igt_assert_eq(json_object_put(results), 1);
+#endif
 		}
 
 		igt_fixture {
@@ -1619,6 +1641,7 @@ igt_main
 			igt_assert(parse_options(ARRAY_SIZE(argv), (char**)argv, settings));
 			igt_assert(create_job_list(list, settings));
 			igt_assert(initialize_execute_state(&state, settings, list));
+#ifdef __linux__ /* TODO: FreeBSD SIGNALFD */
 			igt_assert(execute(&state, settings, list));
 
 			igt_assert_f((dirfd = open(dirname, O_DIRECTORY | O_RDONLY)) >= 0,
@@ -1631,6 +1654,7 @@ igt_main
 			igt_assert_eqstr(igt_get_result(tests, "igt@dynamic@dynamic-subtest@passing"), "pass");
 
 			igt_assert_eq(json_object_put(results), 1);
+#endif
 		}
 
 		igt_fixture {
@@ -1924,6 +1948,7 @@ igt_main
 	}
 
 	igt_subtest("file-descriptor-leakage") {
+#ifdef __linux__ /* TODO: FreeBSD SIGNALFD */
 		int i;
 
 		/*
@@ -1939,6 +1964,7 @@ igt_main
 			igt_assert_neq(close(i), 0);
 			igt_assert_eq(errno, EBADF);
 		}
+#endif
 	}
 
 	igt_fixture {
