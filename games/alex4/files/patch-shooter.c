--- shooter.c.orig	2019-02-04 06:12:31 UTC
+++ shooter.c
@@ -500,12 +500,12 @@ void s_update_object(Tspace_object *o) {
 			break;
 		case SM_SIN_WAVE:
 			o->x += o->vx;
-			o->y = o->d2 + fixtoi(fmul(ftofix(o->vy), fsin(itofix(o->t))));
+			o->y = o->d2 + fixtoi(fixmul(ftofix(o->vy), fixsin(itofix(o->t))));
 			o->t += o->d1;
 			break;
 		case SM_COS_WAVE:
 			o->x += o->vx;
-			o->y = o->d2 + fixtoi(fmul(ftofix(o->vy), fcos(itofix(o->t))));
+			o->y = o->d2 + fixtoi(fixmul(ftofix(o->vy), fixcos(itofix(o->t))));
 			o->t += o->d1;
 			break;
 		case SM_BOSS_1:
@@ -516,8 +516,8 @@ void s_update_object(Tspace_object *o) {
 				o->tx = o->x;
 			}
 			else {
-				o->y = o->ty + fixtoi(fmul(ftofix(o->vy), fsin(itofix(o->t))));
-				o->x = o->tx - fixtoi(10 * fsin(itofix(o->t >> 1)));
+				o->y = o->ty + fixtoi(fixmul(ftofix(o->vy), fixsin(itofix(o->t))));
+				o->x = o->tx - fixtoi(10 * fixsin(itofix(o->t >> 1)));
 				o->t ++;
 			}
 			break;
@@ -573,7 +573,7 @@ void s_update_object(Tspace_object *o) {
 		else if (o->image == ENEMY15) {
 			int i;
 			for(i = 0; i < 256; i += 32)
-				s_make_enemy_bullet((int)o->x + o->bw / 2, (int)o->y + o->bh, fixtof(1 * fcos(itofix(i - 6))), fixtof(1 * fsin(itofix(i - 6))));
+				s_make_enemy_bullet((int)o->x + o->bw / 2, (int)o->y + o->bh, fixtof(1 * fixcos(itofix(i - 6))), fixtof(1 * fixsin(itofix(i - 6))));
 			o->fire_counter = 200 + rand()%50;
 		}
 	
@@ -1372,7 +1372,7 @@ int s_init_shooter() {
 	// load data
 	log2file(" loading shooter data");
 	packfile_password(get_init_string());
-	s_data = load_datafile("data/a45.dat");
+	s_data = load_datafile(DATADIR "a45.dat");
 	if (!s_data) {
 		log2file(" *** failed");
 		return -1;
