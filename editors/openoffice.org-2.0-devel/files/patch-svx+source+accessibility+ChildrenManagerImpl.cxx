--- ../svx/source/accessibility/ChildrenManagerImpl.cxx	Mon Oct 21 01:34:17 2002
+++ ../svx/source/accessibility/ChildrenManagerImpl.cxx.new	Mon Oct 21 01:33:50 2002
@@ -296,8 +296,6 @@
                 awt::Rectangle aPixelBBox (xComponent->getBounds());
                 if ((aPixelBBox.Width > 0) && (aPixelBBox.Height > 0))
                     raDescriptorList.push_back (ChildDescriptor (*I));
-                else
-                    OSL_TRACE ("accessible shape %x not visible", *I);
             }
         }
     }
@@ -320,8 +318,6 @@
             // the visible area.
             if (aBoundingBox.IsOver (aVisibleArea))
                 raDescriptorList.push_back (ChildDescriptor (xShape));
-            else
-                OSL_TRACE ("shape %x not visible", xShape);
         }
     }
 }
