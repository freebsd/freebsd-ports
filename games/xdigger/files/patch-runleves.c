--- runlevels.c.orig
+++ runlevels.c
@@ -672,6 +672,20 @@
     }
 } /* DiggerHalfStep() */
 
+typedef struct
+{
+  unsigned char x, y, id, type;
+} TMerk;
+  
+void Merke(unsigned char type, int x, int y, int *merkidx, TMerk *merk)
+{
+  merk[*merkidx].x = x;
+  merk[*merkidx].y = y;
+  merk[*merkidx].id = field[x][y].id & 7;
+  merk[*merkidx].type = type;
+  *merkidx++;   
+}  
+
 void StoneDiamondStep()
 {
 
@@ -680,24 +694,10 @@
 #define SF_LEFTDOWN  2
 #define SF_CHANGER   3
   
-  typedef struct
-  {
-    unsigned char x, y, id, type;
-  } TMerk;
-  
   TMerk merk[140], ghosts_todie[17];
   int i, x, y, dx, dy, merkidx, ghosts_todie_idx;
   Bool digger_todie = False;  
-  
-  void Merke(unsigned char type)
-    {
-      merk[merkidx].x = x;
-      merk[merkidx].y = y;
-      merk[merkidx].id = field[x][y].id & 7;
-      merk[merkidx].type = type;
-      merkidx++;   
-    }  
-  
+
   /* Schritt 1  (nur markieren) : */
   merkidx = 0; ghosts_todie_idx = 0;
   
@@ -708,19 +708,19 @@
         (field[x][y].id == ID_IVDIAMOND))
     {
       if (field[x][y+1].id == ID_NOTHING)
-        Merke(SF_DOWN);
+        Merke(SF_DOWN, x, y, &merkidx, merk);
       else
         if ((field[x][y+1].id == ID_STONE) ||
             (field[x][y+1].id == ID_DIAMOND))
         {
           if ((field[x-1][y].id == ID_NOTHING) &&
               (field[x-1][y+1].id == ID_NOTHING))
-            Merke(SF_LEFTDOWN);
+            Merke(SF_LEFTDOWN, x, y, &merkidx, merk);
           else
             if ((field[x+1][y].id == ID_NOTHING) &&
                 (field[x+1][y+1].id == ID_NOTHING))
             {          
-              Merke(SF_RIGHTDOWN);
+              Merke(SF_RIGHTDOWN, x, y, &merkidx, &merk);
               field[x+1][y+1].id = ID_FSTODMD;
             }        
         }
@@ -729,7 +729,7 @@
                (field[x][y].id == ID_IVSTONE)) &&
               (field[x][y+1].id == ID_CHANGER) &&
               (field[x][y+2].id == ID_NOTHING))
-            Merke(SF_CHANGER);
+            Merke(SF_CHANGER, x, y, &merkidx, &merk);
     }
   merk[merkidx].x = 0;
   merk[merkidx].y = 0;
@@ -1573,6 +1573,50 @@
 
 /*---------------------------------------------------------------------------*/
 
+void Save_Ghost(int flags, int *id, int *d, unsigned char *file_daten)
+{
+  switch (flags & F_GHOST_TYPEMASK)
+  {
+  case F_GHOST_TYPE180:
+    *id = 3;
+    break;
+  case F_GHOST_TYPEL:
+    *id = 7;
+    break;
+  case F_GHOST_TYPER:
+    *id = 15;
+    break;
+  case F_GHOST_TYPELR:
+    *id = 11;
+    break;
+  }
+  switch (flags & F_GHOST_MOVEMASK)
+  {
+  case F_GHOST_DOWN:
+    *d = 0;
+    break;
+  case F_GHOST_UP:
+    *d = 1;
+    break;
+  case F_GHOST_RIGHT:
+    *d = 2;
+    break;
+  case F_GHOST_LEFT:
+    *d = 3;
+    break;
+  }
+  if (number_ghosts < MAX_GHOSTS)
+  {
+    if (number_ghosts & 1)
+      file_daten[0x94 + number_ghosts/2] =
+        (file_daten[0x94 + number_ghosts/2] & 0xf0) | (*d);
+    else
+      file_daten[0x94 + number_ghosts/2] =
+        (file_daten[0x94 + number_ghosts/2] & 0x0f) | (*d << 4);
+    number_ghosts++;
+  }
+}
+
 void Edit_SaveLevel(int level_number)
 {
 /*   char filename[256]; */
@@ -1580,50 +1624,6 @@
   int x, y, id, flags, i, d;
   FILE *filehandle;
   
-  void Save_Ghost()
-  {
-    switch (flags & F_GHOST_TYPEMASK)
-    {
-    case F_GHOST_TYPE180:
-      id = 3;
-      break;
-    case F_GHOST_TYPEL:
-      id = 7;
-      break;
-    case F_GHOST_TYPER:
-      id = 15;
-      break;
-    case F_GHOST_TYPELR:
-      id = 11;
-      break;
-    }
-    switch (flags & F_GHOST_MOVEMASK)
-    {
-    case F_GHOST_DOWN:
-      d = 0;
-      break;
-    case F_GHOST_UP:
-      d = 1;
-      break;
-    case F_GHOST_RIGHT:
-      d = 2;
-      break;
-    case F_GHOST_LEFT:
-      d = 3;
-      break;
-    }
-    if (number_ghosts < MAX_GHOSTS)
-    {
-      if (number_ghosts & 1)
-        file_daten[0x94 + number_ghosts/2] =
-          (file_daten[0x94 + number_ghosts/2] & 0xf0) | (d);
-      else
-        file_daten[0x94 + number_ghosts/2] =
-          (file_daten[0x94 + number_ghosts/2] & 0x0f) | (d << 4);
-      number_ghosts++;
-    }
-  }
-  
   bzero(file_daten, sizeof(file_daten));
   number_ghosts = 0;
   c = file_daten;
@@ -1637,7 +1637,7 @@
             diggerposy = y;
         }
         if (id == ID_GHOST)
-          Save_Ghost();
+          Save_Ghost(flags, &id, &d, file_daten);
         *c = (*c & 0x0f) | (id << 4);
 
   /* ------------------------------------------------------------------ */
@@ -1650,7 +1650,7 @@
             diggerposy = y;
         }
         if (id == ID_GHOST)
-          Save_Ghost();
+          Save_Ghost(flags, &id, &d, file_daten);
         *c = (*c & 0xf0) | id;
     }
   c += 3; 
