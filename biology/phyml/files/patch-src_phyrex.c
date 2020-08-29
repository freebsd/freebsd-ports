--- src/phyrex.c.orig	2020-07-09 11:49:16 UTC
+++ src/phyrex.c
@@ -958,7 +958,7 @@ phydbl *PHYREX_MCMC(t_tree *tree)
           PHYREX_Label_Nodes_With_Locations(tree);
           PHYREX_Label_Edges(tree);
           char *s = Write_Tree(tree);
-          PhyML_Fprintf(fp_tree,"\ntree %d [&lnP=%f,precision={1.e-1,1e-02,1e-01}] = [&R] %s",tree->mcmc->sample_num,tree->c_lnL,s);
+          PhyML_Fprintf(fp_tree,"\ntree %d [&lnP=%f,precision={1.e-1,1e-02,1e-01}] = [&R] %s",tree->mcmc->run,tree->c_lnL,s);
           PhyML_Fprintf(fp_tree,"\nend;");
           fseek(fp_tree,-5,SEEK_END);
           tree->write_tax_names = YES;
