# Origin: https://github.com/naev/naev/commit/8b4ceb3c5db7171b65f918f278e2d3a0685bf0f2
# Subject: Correctly pass boarding ship to pilot board hook
# Origin: https://github.com/naev/naev/commit/0b545ee49f33632e892e242807543d6b386a02af
# Subject: Run pilot board hook for all pilot, not just player

--- src/board.c.orig	2015-02-16 17:49:03 UTC
+++ src/board.c
@@ -143,7 +143,8 @@ void player_board (void)
    hparam[0].u.lp.pilot = p->id;
    hparam[1].type       = HOOK_PARAM_SENTINEL;
    hooks_runParam( "board", hparam );
-   pilot_runHook(p, PILOT_HOOK_BOARD);
+   hparam[0].u.lp.pilot = PLAYER_ID;
+   pilot_runHookParam(p, PILOT_HOOK_BOARD, hparam, 1);
 
    if (board_stopboard) {
       board_boarded = 0;
@@ -526,6 +527,7 @@ static void board_update( unsigned int w
 int pilot_board( Pilot *p )
 {
    Pilot *target;
+   HookParam hparam[2];
 
    /* Make sure target is sane. */
    target = pilot_get(p->target);
@@ -554,6 +556,12 @@ int pilot_board( Pilot *p )
    /* Set time it takes to board. */
    p->ptimer = 3.;
 
+   /* Run pilot board hook. */
+   hparam[0].type       = HOOK_PARAM_PILOT;
+   hparam[0].u.lp.pilot = p->id;
+   hparam[1].type       = HOOK_PARAM_SENTINEL;
+   pilot_runHookParam(target, PILOT_HOOK_BOARD, hparam, 1);
+
    return 1;
 }
 
