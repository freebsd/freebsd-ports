--- example/example_run.sh.orig	2019-11-13 15:45:57 UTC
+++ example/example_run.sh
@@ -1,4 +1,4 @@
-#! /bin/bash
+#!/bin/sh
 
 # Example:
 # Identify allelic imbalance (AI) given a tumor 
@@ -6,13 +6,13 @@
 # of the GATK.  This involves the following 3 steps.
 
 printf "STEP 1: PHASING 1KG HET SITES ...\n"
-python ../scripts/simple_phaser.py \
+python2.7 ../scripts/simple_phaser.py \
   --ldmap ../ldmap/hg19.exome.ldmap \
   --vcf example_input/tumor_exome.vcf \
   -o example_output/tumor_exome
 
 printf "\nSTEP 2: IDENTIFYING REGIONS OF AI ...\n"
-../haplohseq \
+haplohseq \
   --vcf example_output/tumor_exome.hap.vcf \
   --phased example_output/tumor_exome.hap \
   --event_prevalence 0.1 \
