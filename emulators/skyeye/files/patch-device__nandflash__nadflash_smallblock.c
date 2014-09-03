--- device/nandflash/nandflash_smallblock.c.orig
+++ device/nandflash/nandflash_smallblock.c
@@ -516,7 +516,7 @@
 #endif
 	nf->writebuffer=(u8*)malloc(dev->pagedumpsize);
 	//nf->memsize=528*32*4096;
-       if ((nf->fdump= open(dev->dump, FILE_FLAG)) < 0)
+       if ((nf->fdump= open(dev->dump, FILE_FLAG, S_IRUSR | S_IWUSR)) < 0)
        {
        	free(nf);
        	printf("error open nandflash dump!\n");
