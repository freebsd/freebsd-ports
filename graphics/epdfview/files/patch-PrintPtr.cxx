diff -Naur ./src/PrintPter.cxx ../epdfview-0.1.6/src/PrintPter.cxx
--- ./src/PrintPter.cxx	2008-08-28 15:27:16.000000000 +0200
+++ ../epdfview-0.1.6/src/PrintPter.cxx	2008-08-28 15:27:32.000000000 +0200
@@ -230,20 +230,27 @@
                     ppdFindOption (printerPPD, "PageSize");
                 view.clearPageSizeList ();
                 int pageSizeToSelect = 0;
-                ppd_choice_t *pageSizeChoice = pageSizeOption->choices;
-                for ( int currentSize = 0 ;
-                      currentSize < pageSizeOption->num_choices ;
-                      ++currentSize, ++pageSizeChoice )
+                if ( 0 != pageSizeOption )
                 {
-                    const gchar *sizeName = pageSizeChoice->text;
-                    const gchar *sizeValue = pageSizeChoice->choice;
-
-                    view.addPageSize (_(sizeName), sizeValue);
-                    if ( pageSizeChoice->marked )
+                    ppd_choice_t *pageSizeChoice = pageSizeOption->choices;
+                    for ( int currentSize = 0 ;
+                         currentSize < pageSizeOption->num_choices ;
+                         ++currentSize, ++pageSizeChoice )
                     {
-                        pageSizeToSelect = currentSize;
+                        const gchar *sizeName = pageSizeChoice->text;
+                        const gchar *sizeValue = pageSizeChoice->choice;
+
+                        view.addPageSize (_(sizeName), sizeValue);
+                        if ( pageSizeChoice->marked )
+                        {
+                            pageSizeToSelect = currentSize;
+                        }
                     }
                 }
+                else
+                {
+                    view.addPageSize (_("A4"), "A4");
+                }
                 view.selectPageSize (pageSizeToSelect);
 
                 // Get the resolutions.
@@ -251,29 +258,36 @@
                     ppdFindOption (printerPPD, "Resolution");
                 view.clearResolutionList ();
                 int resolutionToSelect = 0;
-                ppd_choice_t *resolutionChoice = resolutionOption->choices;
-                for ( int currentRes = 0 ;
-                      currentRes < resolutionOption->num_choices ;
-                      ++currentRes, ++resolutionChoice )
+                if ( 0 != resolutionOption )
                 {
-                    const gchar *resName = resolutionChoice->text;
-                    const gchar *resValue = resolutionChoice->choice;
-
-                    view.addResolution (_(resName), resValue);
-                    if ( resolutionChoice->marked )
+                    ppd_choice_t *resolutionChoice = resolutionOption->choices;
+                    for ( int currentRes = 0 ;
+                            currentRes < resolutionOption->num_choices ;
+                            ++currentRes, ++resolutionChoice )
                     {
-                        resolutionToSelect = currentRes;
+                        const gchar *resName = resolutionChoice->text;
+                        const gchar *resValue = resolutionChoice->choice;
+
+                        view.addResolution (_(resName), resValue);
+                        if ( resolutionChoice->marked )
+                        {
+                            resolutionToSelect = currentRes;
+                        }
                     }
                 }
+                else
+                {
+                    view.addResolution (_("300 DPI"), "300x300dpi");
+                }
                 view.selectResolution (resolutionToSelect);
 
                 // Get the color models.
                 ppd_option_t *colorModelOption =
                     ppdFindOption (printerPPD, "ColorModel");
                 view.clearColorModelList ();
+                int colorModelToSelect = 0;
                 if ( NULL != colorModelOption )
                 {
-                    int colorModelToSelect = 0;
                     ppd_choice_t *colorModelChoice = colorModelOption->choices;
                     for ( int currentColor = 0 ;
                           currentColor < colorModelOption->num_choices ;
@@ -288,12 +302,12 @@
                             colorModelToSelect = currentColor;
                         }
                     }
-                    view.selectColorModel (colorModelToSelect);
                 }
                 else
                 {
                     view.addColorModel (_("Grayscale"), "Gray");
                 }
+                view.selectColorModel (colorModelToSelect);
                 ppdClose (printerPPD);
             }
         }
