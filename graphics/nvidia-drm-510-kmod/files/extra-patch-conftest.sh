--- conftest.sh.orig	2024-03-14 18:29:50 UTC
+++ conftest.sh
@@ -2627,7 +2627,7 @@ compile_test() {
             #include <linux/mm.h>
             long get_user_pages(unsigned long start,
                                 unsigned long nr_pages,
-                                unsigned int gup_flags,
+                                int gup_flags,
                                 struct page **pages,
                                 struct vm_area_struct **vmas) {
                 return 0;
@@ -2655,7 +2655,7 @@ compile_test() {
                                 struct mm_struct *mm,
                                 unsigned long start,
                                 unsigned long nr_pages,
-                                unsigned int gup_flags,
+                                int gup_flags,
                                 struct page **pages,
                                 struct vm_area_struct **vmas) {
                 return 0;
@@ -2679,7 +2679,7 @@ compile_test() {
             #include <linux/mm.h>
             long get_user_pages(unsigned long start,
                                 unsigned long nr_pages,
-                                unsigned int gup_flags,
+                                int gup_flags,
                                 struct page **pages) {
                 return 0;
             }" > conftest$$.c
@@ -2852,7 +2852,7 @@ compile_test() {
                                        struct mm_struct *mm,
                                        unsigned long start,
                                        unsigned long nr_pages,
-                                       unsigned int gup_flags,
+                                       int gup_flags,
                                        struct page **pages,
                                        struct vm_area_struct **vmas,
                                        int *locked) {
@@ -2877,7 +2877,7 @@ compile_test() {
             long get_user_pages_remote(struct mm_struct *mm,
                                        unsigned long start,
                                        unsigned long nr_pages,
-                                       unsigned int gup_flags,
+                                       int gup_flags,
                                        struct page **pages,
                                        struct vm_area_struct **vmas,
                                        int *locked) {
@@ -2901,7 +2901,7 @@ compile_test() {
             long get_user_pages_remote(struct mm_struct *mm,
                                        unsigned long start,
                                        unsigned long nr_pages,
-                                       unsigned int gup_flags,
+                                       int gup_flags,
                                        struct page **pages,
                                        int *locked) {
                 return 0;
@@ -2969,7 +2969,7 @@ compile_test() {
             #include <linux/mm.h>
             long pin_user_pages(unsigned long start,
                                 unsigned long nr_pages,
-                    		    unsigned int gup_flags,
+                    		    int gup_flags,
                                 struct page **pages,
                     		    struct vm_area_struct **vmas) {
                 return 0;
@@ -3055,7 +3055,7 @@ compile_test() {
                                        struct mm_struct *mm,
                                        unsigned long start,
                                        unsigned long nr_pages,
-                                       unsigned int gup_flags,
+                                       int gup_flags,
                                        struct page **pages,
                                        struct vm_area_struct **vmas,
                                        int *locked) {
@@ -3077,7 +3077,7 @@ compile_test() {
             long pin_user_pages_remote(struct mm_struct *mm,
                                        unsigned long start,
                                        unsigned long nr_pages,
-                                       unsigned int gup_flags,
+                                       int gup_flags,
                                        struct page **pages,
                                        struct vm_area_struct **vmas,
                                        int *locked) {
