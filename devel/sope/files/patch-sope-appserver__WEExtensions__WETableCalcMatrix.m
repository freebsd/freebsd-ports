--- sope-appserver/WEExtensions/WETableCalcMatrix.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/WEExtensions/WETableCalcMatrix.m
@@ -89,8 +89,8 @@ static NSNull *null = nil;
                      @"<0x%p[%@]: object=0x%p start=%d len=%d>",
                      self, NSStringFromClass([self class]),
                      [self object],
-                     self->range.location,
-                     self->range.length];
+                     (int)self->range.location,
+                     (int)self->range.length];
 }
 
 @end /* WETableCalcMatrixSpan */
@@ -356,7 +356,7 @@ static NSNull *null = nil;
   MatrixCoord *positions;
 }
 
-- (void)addPosition:(unsigned)_x:(unsigned)_y;
+- (void)addPosition:(unsigned)_x :(unsigned)_y;
 - (void)checkForDuplicates;
 
 /* narrow set to row or column */
@@ -387,7 +387,7 @@ static NSNull *null = nil;
   }
 }
 
-- (void)addPosition:(unsigned)_x:(unsigned)_y {
+- (void)addPosition:(unsigned)_x :(unsigned)_y {
   if (self->positions == NULL) {
     self->positions = calloc(1, sizeof(MatrixCoord));
     self->positions[0].x = _x;
@@ -468,7 +468,7 @@ static inline MatrixEntry *entryAt(WETab
          (y * sizeof(MatrixEntry));
 }
 
-- (id)initWithSize:(unsigned)_width:(unsigned)_height {
+- (id)initWithSize:(unsigned)_width :(unsigned)_height {
   if (_width == 0 || _height == 0) {
     [self logWithFormat:@"ERROR: specified invalid matrix dimensions: %ix%i",
             _width, _height];
@@ -572,7 +572,7 @@ static inline MatrixEntry *entryAt(WETab
   return YES;
 }
 
-- (BOOL)object:(id)_obj matchesCellAt:(unsigned)_x:(unsigned)_y {
+- (BOOL)object:(id)_obj matchesCellAt:(unsigned)_x :(unsigned)_y {
   return [self->delegate tableCalcMatrix:self
                          shouldPlaceObject:_obj
                          atPosition:_x:_y];
@@ -580,7 +580,7 @@ static inline MatrixEntry *entryAt(WETab
 
 /* adding object to structure */
 
-- (void)addObject:(id)_obj toCellAt:(unsigned)_x:(unsigned)_y {
+- (void)addObject:(id)_obj toCellAt:(unsigned)_x :(unsigned)_y {
   WETableCalcMatrixPositionArray *positions;
   MatrixEntry *e;
   
