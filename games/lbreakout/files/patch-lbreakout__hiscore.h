--- lbreakout/hiscore.h.orig	2001-02-24 22:00:24.000000000 +0300
+++ lbreakout/hiscore.h	2015-01-25 05:37:12.000000000 +0300
@@ -60,7 +60,7 @@
  protected:
 	HiScoreEntry	*entries;
 	int				entry_num;
-	char			filename[32];
+	char			filename[1024];
  public:
   StandardHiScore(char* f);
   StandardHiScore(FILE* f);
@@ -88,7 +88,7 @@
 // maintains two tables: one per score, the other per level
 class CompositeHiScore : public HiScore {
  private:
-   char filename[32];
+   char filename[1024];
    LevelHiScore* pLevel;
    StandardHiScore* pStandard;
 
