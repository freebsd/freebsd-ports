--- monsterz.py.orig	2020-06-01 13:24:07 UTC
+++ monsterz.py
@@ -10,6 +10,9 @@
    modify it under the terms of the Do What The Fuck You Want To
    Public License, Version 2, as published by Sam Hocevar. See
    http://sam.zoy.org/projects/COPYING.WTFPL for more details.
+
+ Patch to support Python3 from Reiner Herrmann <reiner@reiner-h.de>
+   https://bugs.debian.org/912513
 """
 
 import pygame
@@ -18,6 +21,7 @@ from random import randint
 from sys import argv, exit, platform
 from os.path import join, isdir, isfile, dirname, expanduser
 from os import write, mkdir
+from functools import cmp_to_key
 
 # String constants
 VERSION = '0.7.1'
@@ -108,9 +112,12 @@ def semi_grayscale(surf):
                 M = int(max(r, g, b))
                 m = int(min(r, g, b))
                 val = (2 * M + r + g + b) / 5
-                p[:] = (val + r) / 2, (val + g) / 2, (val + b) / 2
+                val = (2 * M + r + g + b) // 5
+                p[0] = (val + r) // 2
+                p[1] = (val + g) // 2
+                p[2] = (val + b) // 2
                 if alpha[y][x] >= 250:
-                    alpha[y][x] = 255 - (M - m) * 3 / 4
+                    alpha[y][x] = 255 - (M - m) * 3 // 4
         del pixels
         del alpha
         surf.unlock()
@@ -129,9 +136,11 @@ def semi_transp(surf):
                 r, g, b = p
                 M = int(max(r, g, b))
                 m = int(min(r, g, b))
-                p[:] = (m + r) / 2, (m + g) / 2, (m + b) / 2
+                p[0] = (m + r) // 2
+                p[1] = (m + g) // 2
+                p[2] = (m + b) // 2
                 if alpha[y][x] >= 250:
-                    alpha[y][x] = 255 - M * 2 / 3
+                    alpha[y][x] = 255 - M * 2 // 3
         del pixels
         del alpha
         surf.unlock()
@@ -218,12 +227,12 @@ class Settings:
         file.close()
 
     def get(self, key):
-        if not self.config.has_key(key):
+        if key not in self.config:
             return None
         return self.config[key]
 
     def set(self, key, value):
-        if not self.config.has_key(key):
+        if key not in self.config:
             return
         self.config[key] = value
 
@@ -241,15 +250,15 @@ class Settings:
             pass
         # Add dummy scores to make sure our score list is full
         for game in ['CLASSIC']:
-            if not self.scores.has_key(game):
+            if game not in self.scores:
                 self.scores[game] = []
             for x in range(20): self._add_score(game, 'NOBODY', 0, 1)
 
     def _add_score(self, game, name, score, level):
-        if not self.scores.has_key(game):
+        if game not in self.scores:
             self.scores[game] = []
         self.scores[game].append((name, score, level))
-        self.scores[game].sort(compare_scores)
+        self.scores[game].sort(key=cmp_to_key(compare_scores))
         self.scores[game] = self.scores[game][0:19]
 
     def new_score(self, game, score, level):
@@ -264,7 +273,7 @@ class Settings:
                 msg += type + ':' + name + ':' + str(score) + ':' + str(level)
                 msg += '\n'
         if self.outfd is not None:
-            write(self.outfd, msg + '\n')
+            write(self.outfd, (msg + '\n').encode())
         else:
             try:
                 file = open(self.scorefile, 'w')
@@ -286,7 +295,7 @@ class Data:
         self.background = pygame.image.load(join(dir, 'graphics', 'background.png')).convert()
         self.board = pygame.image.load(join(dir, 'graphics', 'board.png')).convert()
         self.logo = pygame.image.load(join(dir, 'graphics', 'logo.png')).convert_alpha()
-        self.orig_size = w / 5
+        self.orig_size = w // 5
         self.normal = [None] * ITEMS
         self.blink = [None] * ITEMS
         self.tiny = [None] * ITEMS
@@ -316,8 +325,8 @@ class Data:
         # Create sprites
         for i in range(ITEMS):
             self.normal[i] = scale(tile_at(0, i + 5), (t, t))
-            self.tiny[i] = scale(tile_at(0, i + 5), (t * 3 / 4, t * 3 / 4))
-            self.shaded[i] = scale(tile_at(3, i + 5), (t * 3 / 4, t * 3 / 4))
+            self.tiny[i] = scale(tile_at(0, i + 5), (t * 3 // 4, t * 3 // 4))
+            self.shaded[i] = scale(tile_at(3, i + 5), (t * 3 // 4, t * 3 // 4))
             semi_grayscale(self.shaded[i])
             self.blink[i] = scale(tile_at(1, i + 5), (t, t))
             self.surprise[i] = scale(tile_at(2, i + 5), (t, t))
@@ -326,15 +335,15 @@ class Data:
             #tmp = tile_at(1, 0).copy() # marche pas !
             tmp = scale(tile_at(1, 0), (t, t)) # marche...
             mini = tile_at(0, i + 5)
-            mini = scale(mini, (t * 7 / 8 - 1, t * 7 / 8 - 1))
-            tmp.blit(mini, (s / 16, s / 16))
+            mini = scale(mini, (t * 7 // 8 - 1, t * 7 // 8 - 1))
+            tmp.blit(mini, (s // 16, s // 16))
             self.special[i] = scale(tmp, (t, t))
-        self.led_off = scale(self.tiles.subsurface((3 * s, 0, s / 2, s / 2)), (t / 2, t / 2))
-        self.led_on = scale(self.tiles.subsurface((3 * s + s / 2, 0, s / 2, s / 2)), (t / 2, t / 2))
-        self.led_more = scale(self.tiles.subsurface((3 * s, s / 2, s / 2, s / 2)), (t / 2, t / 2))
-        self.led_less = scale(self.tiles.subsurface((3 * s + s / 2, s / 2, s / 2, s / 2)), (t / 2, t / 2))
-        self.eye = scale(tile_at(2, 0), (t * 3 / 4, t * 3 / 4))
-        self.shadeye = scale(tile_at(2, 0), (t * 3 / 4, t * 3 / 4))
+        self.led_off = scale(self.tiles.subsurface((3 * s, 0, s // 2, s // 2)), (t // 2, t // 2))
+        self.led_on = scale(self.tiles.subsurface((3 * s + s // 2, 0, s // 2, s // 2)), (t // 2, t // 2))
+        self.led_more = scale(self.tiles.subsurface((3 * s, s // 2, s // 2, s // 2)), (t // 2, t // 2))
+        self.led_less = scale(self.tiles.subsurface((3 * s + s // 2, s // 2, s // 2, s // 2)), (t // 2, t // 2))
+        self.eye = scale(tile_at(2, 0), (t * 3 // 4, t * 3 // 4))
+        self.shadeye = scale(tile_at(2, 0), (t * 3 // 4, t * 3 // 4))
         semi_transp(self.shadeye)
         self.arrow = tile_at(4, 0)
         self.selector = scale(tile_at(0, 0), (t, t))
@@ -367,7 +376,7 @@ class Data:
 
     def screen2board(self, coord):
         x, y = coord
-        return ((x - 24) / ITEM_SIZE, (y - 24) / ITEM_SIZE)
+        return ((x - 24) // ITEM_SIZE, (y - 24) // ITEM_SIZE)
 
 class Sprite:
     def __init__(self, surf, coord):
@@ -398,7 +407,8 @@ class System:
     def blit(self, surf, coords):
         self.background.blit(surf, coords)
 
-    def blit_board(self, (x1, y1, x2, y2)):
+    def blit_board(self, coords):
+        (x1, y1, x2, y2) = coords
         x1, y1 = x1 * ITEM_SIZE, y1 * ITEM_SIZE
         x2, y2 = x2 * ITEM_SIZE - x1, y2 * ITEM_SIZE - y1
         surf = data.board.subsurface((x1, y1, x2, y2))
@@ -454,16 +464,16 @@ class Fonter:
                 self.cache.append((m, s, c, t))
                 return t
         font = pygame.font.Font(None, size * 2)
-        delta = 2 + size / 8
+        delta = 2 + size // 8
         black = font.render(msg, 2, (0, 0, 0))
         w, h = black.get_size()
         text = pygame.Surface((w + delta, h + delta)).convert_alpha()
         text.fill((0, 0, 0, 0))
         for x, y in [(5, 5), (6, 3), (5, 1), (3, 0),
                      (1, 1), (0, 3), (1, 5), (3, 6)]:
-            text.blit(black, (x * delta / 6, y * delta / 6))
+            text.blit(black, (x * delta // 6, y * delta // 6))
         white = font.render(msg, 2, color)
-        text.blit(white, (delta / 2, delta / 2))
+        text.blit(white, (delta // 2, delta // 2))
         text = pygame.transform.rotozoom(text, 0.0, 0.5)
         self.cache.append((msg, size, color, text))
         if len(self.cache) > self.size:
@@ -492,7 +502,7 @@ class Game:
         self.win_timer = 0
         self.warning_timer = 0
         self.switch_timer = 0
-        self.level_timer = SCROLL_DELAY / 2
+        self.level_timer = SCROLL_DELAY // 2
         self.board_timer = 0
         self.missed = False
         self.check_moves = False
@@ -527,11 +537,11 @@ class Game:
         #self.board[randint(3, 4)][0] = ITEM_METAL
 
     def fill_board(self):
-        for y in xrange(BOARD_HEIGHT - 1, -1, -1):
-            for x in xrange(BOARD_WIDTH - 1, -1, -1):
+        for y in range(BOARD_HEIGHT - 1, -1, -1):
+            for x in range(BOARD_WIDTH - 1, -1, -1):
                 if self.board[x][y] != ITEM_NONE:
                     continue
-                for y2 in xrange(y - 1, -1, -1):
+                for y2 in range(y - 1, -1, -1):
                     if self.board[x][y2] != ITEM_NONE:
                         self.board[x][y] = self.board[x][y2]
                         self.extra_offset[x][y] = (0, ITEM_SIZE * (y2 - y))
@@ -683,7 +693,7 @@ class Game:
         system.blit(data.board, (24, 24))
         # Have a random piece blink
         c = randint(0, BOARD_WIDTH - 1), randint(0, BOARD_HEIGHT - 1)
-        if randint(0, 5) is 0 and not self.blink_list.has_key(c):
+        if randint(0, 5) is 0 and c not in self.blink_list:
             self.blink_list[c] = 5
         # Handle special scrolling cases
         if self.level_timer:
@@ -692,14 +702,14 @@ class Game:
             timer = self.board_timer
         else:
             timer = 0
-        if timer > SCROLL_DELAY / 2:
+        if timer > SCROLL_DELAY // 2:
             global_xoff = 0
             yoff = (SCROLL_DELAY - timer) * (SCROLL_DELAY - timer)
-            global_yoff = yoff * 50 * 50 / SCROLL_DELAY / SCROLL_DELAY
+            global_yoff = yoff * 50 * 50 // SCROLL_DELAY // SCROLL_DELAY
         elif timer > 0:
             global_xoff = 0
             yoff = - timer * timer
-            global_yoff = yoff * 50 * 50 / SCROLL_DELAY / SCROLL_DELAY
+            global_yoff = yoff * 50 * 50 // SCROLL_DELAY // SCROLL_DELAY
         else:
             global_xoff = 0
             global_yoff = 0
@@ -725,15 +735,15 @@ class Game:
             xoff, yoff = self.extra_offset[i][j]
             if self.lost_timer:
                 d = LOST_DELAY - self.lost_timer
-                xoff += (i * 2 - 7) * 4 * d / LOST_DELAY
-                yoff += (j * 2 - 7) * 4 * d / LOST_DELAY
-                xoff += (j * 2 - 7) * 4 * d / LOST_DELAY
-                yoff += (-i * 2 + 7) * 4 * d / LOST_DELAY
+                xoff += (i * 2 - 7) * 4 * d // LOST_DELAY
+                yoff += (j * 2 - 7) * 4 * d // LOST_DELAY
+                xoff += (j * 2 - 7) * 4 * d // LOST_DELAY
+                yoff += (-i * 2 + 7) * 4 * d // LOST_DELAY
                 xoff += (randint(0, d) - randint(0, d))
                 yoff += (randint(0, d) - randint(0, d))
                 self.extra_offset[i][j] = xoff, yoff
             elif yoff and self.win_timer:
-                yoff = yoff * (self.win_timer - 1) / (WIN_DELAY * 2 / 3)
+                yoff = yoff * (self.win_timer - 1) // (WIN_DELAY * 2 // 3)
                 self.extra_offset[i][j] = xoff, yoff
             xoff += global_xoff
             yoff += global_yoff
@@ -744,17 +754,17 @@ class Game:
                 shape = data.metal
             elif n >= ITEM_PUZZLE:
                 shape = data.puzzle[puzzlevels[self.level - 1][2]][n - ITEM_PUZZLE]
-            elif self.level_timer and self.level_timer < SCROLL_DELAY / 2:
+            elif self.level_timer and self.level_timer < SCROLL_DELAY // 2:
                 shape = data.blink[n]
             elif (i, j) in self.surprised_list \
-              or self.board_timer > SCROLL_DELAY / 2 \
-              or self.level_timer > SCROLL_DELAY / 2:
+              or self.board_timer > SCROLL_DELAY // 2 \
+              or self.level_timer > SCROLL_DELAY // 2:
                 shape = data.surprise[n]
             elif (i, j) in self.disappear_list:
                 shape = data.exploded[n]
             elif n == self.angry_items:
                 shape = data.angry[n]
-            elif self.blink_list.has_key((i, j)):
+            elif (i, j) in self.blink_list:
                 shape = data.blink[n]
                 self.blink_list[i, j] -= 1
                 if self.blink_list[i, j] is 0: del self.blink_list[i, j]
@@ -771,7 +781,8 @@ class Game:
         if self.select:
             system.blit(data.selector, select_coord)
 
-    def piece_draw(self, sprite, (x, y)):
+    def piece_draw(self, sprite, pos):
+        (x, y) = pos
         width = ITEM_SIZE
         crop = sprite.subsurface
         # Constrain X
@@ -806,7 +817,7 @@ class Game:
         # Draw timebar
         timebar = pygame.Surface((406, 32)).convert_alpha()
         timebar.fill((0, 0, 0, 155))
-        w = 406 * self.time / 2000000
+        w = 406 * self.time // 2000000
         if w > 0:
             if self.warning_timer:
                 ratio = 1.0 * abs(2 * self.warning_timer - WARNING_DELAY) \
@@ -829,15 +840,15 @@ class Game:
             pass
         else:
             for x in range(4):
-                for y, p in enumerate(alpha[x]):
-                    alpha[x][y] = p * x / 4
-                for y, p in enumerate(alpha[406 - x - 1]):
-                    alpha[406 - x - 1][y] = p * x / 4
+                for y in range(len(alpha[x])):
+                    alpha[x][y] = alpha[x][y] * x // 4
+                for y in range(len(alpha[406 - x - 1])):
+                    alpha[406 - x - 1][y] = alpha[406 - x - 1][y] * x // 4
             for col in alpha:
                 l = len(col)
                 for y in range(4):
-                    col[y] = col[y] * y / 4
-                    col[l - y - 1] = col[l - y - 1] * y / 4
+                    col[y] = col[y] * y // 4
+                    col[l - y - 1] = col[l - y - 1] * y // 4
                 del col
             del alpha
             timebar.unlock()
@@ -846,7 +857,7 @@ class Game:
             # Print play again message
             text = fonter.render('GAME OVER', 80)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 192 - w / 2, 24 + 192 - h / 2))
+            system.blit(text, (24 + 192 - w // 2, 24 + 192 - h // 2))
             if self.score < 5000:
                 msg = 'YUO = TEH L0SER'
             elif self.score < 15000:
@@ -857,13 +868,13 @@ class Game:
                 msg = 'ZOMFG!!!111!!! YUO PWND!!!%$#@%@#'
             text = fonter.render(msg, 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 192 - w / 2, 24 + 240 - h / 2))
+            system.blit(text, (24 + 192 - w // 2, 24 + 240 - h // 2))
         elif self.paused:
             # Draw pause message
             system.blit(self.pause_bitmap, (72, 24))
             text = fonter.render('PAUSED', 120)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 192 - w / 2, 24 + 336 - h / 2))
+            system.blit(text, (24 + 192 - w // 2, 24 + 336 - h // 2))
         elif self.splash:
             if self.type == GAME_TRAINING:
                 msg = 'TRAINING'
@@ -871,7 +882,7 @@ class Game:
                 msg = 'LEVEL ' + str(self.level)
             text = fonter.render(msg, 60)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 192 - w / 2, 24 + 144 - h / 2))
+            system.blit(text, (24 + 192 - w // 2, 24 + 144 - h // 2))
             if self.needed[0]:
                 msg = 'MONSTERS NEEDED: ' + str(self.needed[0])
             elif self.type == GAME_PUZZLE:
@@ -884,24 +895,24 @@ class Game:
             if self.lucky != -1:
                 text = fonter.render('LUCKY MONSTER:', 40)
                 w, h = text.get_rect().size
-                system.blit(text, (192 - w / 2 - 8, 24 + 288 - h / 2))
-                system.blit(data.normal[self.lucky], (192 + w / 2, 288))
+                system.blit(text, (192 - w // 2 - 8, 24 + 288 - h // 2))
+                system.blit(data.normal[self.lucky], (192 + w // 2, 288))
         elif self.lost_timer != -1:
             # Draw pieces
             self.board_draw()
             # Print new level stuff
-            if self.level_timer > SCROLL_DELAY / 2:
+            if self.level_timer > SCROLL_DELAY // 2:
                 if self.type == GAME_PUZZLE:
                     text = fonter.render('COMPLETED!', 80)
                 else:
                     text = fonter.render('LEVEL UP!', 80)
                 w, h = text.get_rect().size
-                system.blit(text, (24 + 192 - w / 2, 24 + 192 - h / 2))
+                system.blit(text, (24 + 192 - w // 2, 24 + 192 - h // 2))
             # When no more moves are possible
-            if self.board_timer > SCROLL_DELAY / 2:
+            if self.board_timer > SCROLL_DELAY // 2:
                 text = fonter.render('NO MORE MOVES!', 60)
                 w, h = text.get_rect().size
-                system.blit(text, (24 + 192 - w / 2, 24 + 192 - h / 2))
+                system.blit(text, (24 + 192 - w // 2, 24 + 192 - h // 2))
             # Print bonus
             for b in self.bonus_list:
                 if b[2]:
@@ -910,7 +921,7 @@ class Game:
                     text = fonter.render(str(b[1]), 36)
                 w, h = text.get_rect().size
                 x, y = data.board2screen(b[0])
-                system.blit(text, (x + 24 - w / 2, y + 24 - h / 2))
+                system.blit(text, (x + 24 - w // 2, y + 24 - h // 2))
             # Print hint arrow
             if self.show_move:
                 lookup = [0, 1, 5, 16, 27, 31, 32, 31, 27, 16, 5, 1]
@@ -918,8 +929,8 @@ class Game:
                     x1, y1 = data.board2screen(src)
                     x2, y2 = data.board2screen(dst)
                     delta = lookup[monsterz.timer % 12]
-                    x = -32 + (x1 * delta + x2 * (32 - delta)) / 32
-                    y = 32 + (y1 * delta + y2 * (32 - delta)) / 32
+                    x = -32 + (x1 * delta + x2 * (32 - delta)) // 32
+                    y = 32 + (y1 * delta + y2 * (32 - delta)) // 32
                     system.blit(data.arrow, (x, y))
                     break # Only show one move
         # Print score
@@ -928,7 +939,7 @@ class Game:
         system.blit(text, (624 - w, 10))
         # Print done/needed
         for i in range(self.population):
-            x = 440 + i / 4 * 90
+            x = 440 + i // 4 * 90
             y = 64 + (i % 4) * 38
             if self.done[i] >= self.needed[i]:
                 surf = data.tiny[i]
@@ -954,15 +965,15 @@ class Game:
                 led, color = data.led_on, (255, 255, 255)
             else:
                 led, color = data.led_off, (180, 150, 127)
-            c = map(lambda a, b: b - (b - a) * self.psat[0] / 255, r, color)
+            c = list(map(lambda a, b: b - (b - a) * self.psat[0] // 255, r, color))
             system.blit(led, (440, 298))
             system.blit(fonter.render('PAUSE', 30, c), (470, 296))
             color = (180, 150, 127)
-            c = map(lambda a, b: b - (b - a) * self.psat[1] / 255, r, color)
+            c = list(map(lambda a, b: b - (b - a) * self.psat[1] // 255, r, color))
             system.blit(fonter.render('ABORT', 30, c), (470, 326))
             for x in range(2):
                 if self.psat[x]:
-                    self.psat[x] = self.psat[x] * 8 / 10
+                    self.psat[x] = self.psat[x] * 8 // 10
 
     def pause(self):
         # TODO: prevent cheating by not allowing less than 1 second
@@ -980,7 +991,7 @@ class Game:
 
     def update(self):
         ticks = pygame.time.get_ticks()
-        delta = (ticks - self.oldticks) * 450 / (12 - self.speed)
+        delta = (ticks - self.oldticks) * 450 // (12 - self.speed)
         self.oldticks = ticks
         # If paused, do nothing
         if self.paused:
@@ -990,7 +1001,7 @@ class Game:
         # Resolve winning moves and chain reactions
         if self.board_timer:
             self.board_timer -= 1
-            if self.board_timer is SCROLL_DELAY / 2:
+            if self.board_timer is SCROLL_DELAY // 2:
                 self.new_board()
             elif self.board_timer is 0:
                 system.play('boing')
@@ -1035,7 +1046,7 @@ class Game:
             return
         if self.level_timer:
             self.level_timer -= 1
-            if self.level_timer is SCROLL_DELAY / 2:
+            if self.level_timer is SCROLL_DELAY // 2:
                 self.level += 1
                 if self.type == GAME_PUZZLE:
                     if self.level > len(puzzlevels):
@@ -1055,7 +1066,7 @@ class Game:
                 for w in self.wins:
                     for x, y in w:
                         self.surprised_list.append((x, y))
-            elif self.win_timer is WIN_DELAY * 4 / 5:
+            elif self.win_timer is WIN_DELAY * 4 // 5:
                 system.play('pop')
                 self.scorebonus = 0
                 self.timebonus = 0
@@ -1076,10 +1087,10 @@ class Game:
                     for x, y in w:
                         x2 += x
                         y2 += y
-                    self.bonus_list.append([(x2 / len(w), y2 / len(w)), points, lucky])
+                    self.bonus_list.append([(x2 // len(w), y2 // len(w)), points, lucky])
                 self.disappear_list = self.surprised_list
                 self.surprised_list = []
-            elif self.win_timer is WIN_DELAY * 3 / 5:
+            elif self.win_timer is WIN_DELAY * 3 // 5:
                 for x, y in self.disappear_list:
                     if self.board[x][y] != ITEM_NONE:
                         self.done[self.board[x][y]] += 1
@@ -1095,7 +1106,7 @@ class Game:
                         self.angry_items = angry
                 self.disappear_list = []
                 self.bonus_list = []
-            elif self.win_timer is WIN_DELAY * 2 / 5:
+            elif self.win_timer is WIN_DELAY * 2 // 5:
                 self.time += self.timebonus
                 if self.time > 2000000:
                     self.time = 2000000
@@ -1192,7 +1203,7 @@ class Game:
                             self.will_play = move
                             min = self.done[color]
                 self.ai_timer = 15 - self.level
-            if self.ai_timer is (15 - self.level) / 2:
+            if self.ai_timer is (15 - self.level) // 2:
                 self.clicks.append(self.will_play[0])
             elif self.ai_timer is 0:
                 self.clicks.append(self.will_play[1])
@@ -1287,10 +1298,10 @@ class Monsterz:
             pass
         else:
             for x in range(10):
-                for y, p in enumerate(alpha[x]):
-                    alpha[x][y] = p * x / 12
-                for y, p in enumerate(alpha[406 - x - 1]):
-                    alpha[406 - x - 1][y] = p * x / 12
+                for y in range(len(alpha[x])):
+                    alpha[x][y] = alpha[x][y] * x // 12
+                for y in range(len(alpha[406 - x - 1])):
+                    alpha[406 - x - 1][y] = alpha[406 - x - 1][y] * x // 12
             del alpha
             scroll.unlock()
         system.blit(scroll, (13, 437))
@@ -1321,26 +1332,26 @@ class Monsterz:
                 led, color = data.led_on, (255, 255, 255)
             else:
                 led, color = data.led_off, (180, 150, 127)
-            c = map(lambda a, b: b - (b - a) * self.gsat[0] / 255, r, color)
+            c = list(map(lambda a, b: b - (b - a) * self.gsat[0] // 255, r, color))
             system.blit(led, (440, 378))
             system.blit(fonter.render('SOUND FX', 30, c), (470, 376))
             if settings.get('music'):
                 led, color = data.led_on, (255, 255, 255)
             else:
                 led, color = data.led_off, (180, 150, 127)
-            c = map(lambda a, b: b - (b - a) * self.gsat[1] / 255, r, color)
+            c = list(map(lambda a, b: b - (b - a) * self.gsat[1] // 255, r, color))
             system.blit(led, (440, 408))
             system.blit(fonter.render('MUSIC', 30, c), (470, 406))
         if settings.get('fullscreen'):
             led, color = data.led_on, (255, 255, 255)
         else:
             led, color = data.led_off, (180, 150, 127)
-        c = map(lambda a, b: b - (b - a) * self.gsat[2] / 255, r, color)
+        c = list(map(lambda a, b: b - (b - a) * self.gsat[2] // 255, r, color))
         system.blit(led, (440, 438))
         system.blit(fonter.render('FULLSCREEN', 30, c), (470, 436))
         for x in range(3):
             if self.gsat[x]:
-                self.gsat[x] = self.gsat[x] * 8 / 10
+                self.gsat[x] = self.gsat[x] * 8 // 10
 
     def generic_event(self, event):
         if event.type == QUIT:
@@ -1398,7 +1409,7 @@ class Monsterz:
         self.marea = marea
         # Print logo and menu
         w, h = data.logo.get_size()
-        system.blit(data.logo, (24 + 192 - w / 2, 24 + 96 - h / 2))
+        system.blit(data.logo, (24 + 192 - w // 2, 24 + 96 - h // 2))
         for x in range(4):
             if self.msat[x] > 180:
                 monster = data.surprise[shapes[x]]
@@ -1407,12 +1418,12 @@ class Monsterz:
             else:
                 monster = data.blink[shapes[x]]
             system.blit(monster, data.board2screen((1, 4 + x)))
-            c = map(lambda a: 255 - (255 - a) * self.msat[x] / 255, colors[x])
+            c = list(map(lambda a: 255 - (255 - a) * self.msat[x] // 255, colors[x]))
             text = fonter.render(messages[x], 48, c)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 102, 24 + 216 + ITEM_SIZE * x - h / 2))
+            system.blit(text, (24 + 102, 24 + 216 + ITEM_SIZE * x - h // 2))
             if self.msat[x]:
-                self.msat[x] = self.msat[x] * 8 / 10
+                self.msat[x] = self.msat[x] * 8 // 10
         # Handle events
         for event in pygame.event.get():
             if self.generic_event(event):
@@ -1479,32 +1490,32 @@ class Monsterz:
         # Print menu
         text = fonter.render('GAME TYPE', 60)
         w, h = text.get_rect().size
-        system.blit(text, (24 + 192 - w / 2, 24 + 24 - h / 2))
+        system.blit(text, (24 + 192 - w // 2, 24 + 24 - h // 2))
         for i in range(4):
-            c = map(lambda a: 255 - (255 - a) * self.nsat[i] / 255, [127, 0, 255])
+            c = list(map(lambda a: 255 - (255 - a) * self.nsat[i] // 255, [127, 0, 255]))
             text = fonter.render(messages[i], 48, c)
             w, h = text.get_rect().size
-            system.blit(text, (24 + ITEM_SIZE * 4 - w / 2, 24 + 120 + ITEM_SIZE * i - h / 2))
+            system.blit(text, (24 + ITEM_SIZE * 4 - w // 2, 24 + 120 + ITEM_SIZE * i - h // 2))
             if self.nsat[i]:
-                self.nsat[i] = self.nsat[i] * 8 / 10
+                self.nsat[i] = self.nsat[i] * 8 // 10
         for i in range(4, 8):
-            c = map(lambda a: 255 - (255 - a) * self.nsat[i] / 255, [127, 0, 255])
+            c = list(map(lambda a: 255 - (255 - a) * self.nsat[i] // 255, [127, 0, 255]))
             if i % 2:
                 img = data.led_more
                 x = 320
             else:
                 img = data.led_less
                 x = 88
-            y = 36 + ITEM_SIZE * (6 + (i - 4) / 2)
+            y = 36 + ITEM_SIZE * (6 + (i - 4) // 2)
             system.blit(img, (x, y))
             if self.nsat[i]:
-                self.nsat[i] = self.nsat[i] * 8 / 10
+                self.nsat[i] = self.nsat[i] * 8 // 10
         # Print wanted monsterz
         for i in range(items):
-            system.blit(data.normal[i], (24 + 96 + ITEM_SIZE * 3 * i / (items - 1), 24 + ITEM_SIZE * 6))
+            system.blit(data.normal[i], (24 + 96 + ITEM_SIZE * 3 * i // (items - 1), 24 + ITEM_SIZE * 6))
         text = fonter.render('DIFFICULTY ' + str(difficulty), 36)
         w, h = text.get_rect().size
-        system.blit(text, (24 + 192 - w / 2, 24 + ITEM_SIZE * 7 + 24 - h / 2))
+        system.blit(text, (24 + 192 - w // 2, 24 + ITEM_SIZE * 7 + 24 - h // 2))
         # Handle events
         for event in pygame.event.get():
             if self.generic_event(event):
@@ -1610,18 +1621,18 @@ class Monsterz:
         # Title
         text = fonter.render('INSTRUCTIONS (' + str(self.page) + ')', 60)
         w, h = text.get_rect().size
-        system.blit(text, (24 + 192 - w / 2, 24 + 24 - h / 2))
+        system.blit(text, (24 + 192 - w // 2, 24 + 24 - h // 2))
         if self.page == 1:
             # Explanation 1
             text = fonter.render('SWAP ADJACENT MONSTERS TO CREATE', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 84 - h / 2))
+            system.blit(text, (24 + 6, 24 + 84 - h // 2))
             text = fonter.render('ALIGNMENTS OF THREE OR MORE. NEW', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 108 - h / 2))
+            system.blit(text, (24 + 6, 24 + 108 - h // 2))
             text = fonter.render('MONSTERS WILL FILL THE HOLES.', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 132 - h / 2))
+            system.blit(text, (24 + 6, 24 + 132 - h // 2))
             # Iter 1
             system.blit_board((0, 3, 2, 7))
             system.blit(data.normal[2], data.board2screen((0, 3)))
@@ -1658,22 +1669,22 @@ class Monsterz:
             text = fonter.render('10', 36)
             w, h = text.get_rect().size
             x, y = data.board2screen((7, 4))
-            system.blit(text, (x + 24 - w / 2, y + 24 - h / 2))
+            system.blit(text, (x + 24 - w // 2, y + 24 - h // 2))
             # Explanation 2
             text = fonter.render('CREATE CHAIN REACTIONS TO GET TWICE', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 348 - h / 2))
+            system.blit(text, (24 + 6, 24 + 348 - h // 2))
             text = fonter.render('AS MANY POINTS, THEN 4x, 8x ETC.', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 372 - h / 2))
+            system.blit(text, (24 + 6, 24 + 372 - h // 2))
         elif self.page == 2:
             # Explanation 1
             text = fonter.render('THE LUCKY MONSTER EARNS YOU TWICE', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 108 - h / 2))
+            system.blit(text, (24 + 6, 24 + 108 - h // 2))
             text = fonter.render('AS MANY POINTS AS OTHER MONSTERS.', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 132 - h / 2))
+            system.blit(text, (24 + 6, 24 + 132 - h // 2))
             shape = data.special[self.timer % 7]
             # Print done/needed
             system.blit_board((0, 3, 4, 5))
@@ -1697,15 +1708,15 @@ class Monsterz:
             text = fonter.render('140', 48, rainbow[monsterz.timer % 6])
             w, h = text.get_rect().size
             x, y = data.board2screen((2, 6))
-            system.blit(text, (x + 24 - w / 2, y + 24 - h / 2))
+            system.blit(text, (x + 24 - w // 2, y + 24 - h // 2))
             text = fonter.render('70', 36)
             w, h = text.get_rect().size
             x, y = data.board2screen((1, 7))
-            system.blit(text, (x + 24 - w / 2, y + 24 - h / 2))
+            system.blit(text, (x + 24 - w // 2, y + 24 - h // 2))
             for i in range(4):
                 surf = data.tiny[i + 1]
                 count = 3 + i * 2
-                x = 24 + 240 + 4 + i / 2 * 70
+                x = 24 + 240 + 4 + i // 2 * 70
                 y = 172 + (i % 2) * 38
                 for dummy in range(2):
                     system.blit(surf, (x, y))
@@ -1722,13 +1733,13 @@ class Monsterz:
             # Explanation 1
             text = fonter.render('YOU CAN ALWAYS PERFORM A VALID MOVE.', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 84 - h / 2))
+            system.blit(text, (24 + 6, 24 + 84 - h // 2))
             text = fonter.render('WHEN NO MORE MOVES ARE POSSIBLE, YOU', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 108 - h / 2))
+            system.blit(text, (24 + 6, 24 + 108 - h // 2))
             text = fonter.render('GET A COMPLETE NEW BOARD.', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 132 - h / 2))
+            system.blit(text, (24 + 6, 24 + 132 - h // 2))
             # Surprised
             system.blit_board((0, 3, 8, 5))
             for x in range(8):
@@ -1736,29 +1747,29 @@ class Monsterz:
                 system.blit(data.surprise[(x * 7) % 8], data.board2screen((x, 4)))
             text = fonter.render('NO MORE MOVES!', 60)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 192 - w / 2, 24 + 192 - h / 2))
+            system.blit(text, (24 + 192 - w // 2, 24 + 192 - h // 2))
             # Explanation 2
             text = fonter.render('USE THE EYE TO FIND WHERE TO PLAY.', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6 + 48, 24 + 300 - h / 2))
+            system.blit(text, (24 + 6 + 48, 24 + 300 - h // 2))
             text = fonter.render('EACH 10,000 POINTS YOU GET A NEW', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6 + 48, 24 + 324 - h / 2))
+            system.blit(text, (24 + 6 + 48, 24 + 324 - h // 2))
             text = fonter.render('EYE. YOU CAN\'T HAVE MORE THAN 3.', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6 + 48, 24 + 348 - h / 2))
+            system.blit(text, (24 + 6 + 48, 24 + 348 - h // 2))
             system.blit(data.eye, (24 + 6, 24 + 306))
         elif self.page == 4:
             # Explanation 1
             text = fonter.render('WHEN ONLY ONE KIND OF MONSTER IS', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 84 - h / 2))
+            system.blit(text, (24 + 6, 24 + 84 - h // 2))
             text = fonter.render('NEEDED TO FINISH THE LEVEL, MONSTERS', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 108 - h / 2))
+            system.blit(text, (24 + 6, 24 + 108 - h // 2))
             text = fonter.render('OF THAT KIND GET AN ANGRY FACE.', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 132 - h / 2))
+            system.blit(text, (24 + 6, 24 + 132 - h // 2))
             # Print done/needed
             system.blit_board((0, 3, 4, 5))
             for i in range(4):
@@ -1770,7 +1781,7 @@ class Monsterz:
                     big = data.angry[i + 4]
                 system.blit(big, data.board2screen((i, 3 + (i % 2))))
                 system.blit(big, data.board2screen(((i + 2) % 4, 3 + ((i + 1) % 2))))
-                x = 24 + 240 + 4 + i / 2 * 70
+                x = 24 + 240 + 4 + i // 2 * 70
                 y = 172 + (i % 2) * 38
                 system.blit(surf, (x, y))
                 text = fonter.render(str(i * 3), 36)
@@ -1778,10 +1789,10 @@ class Monsterz:
             # Explanation 2
             text = fonter.render('CLICK ON THE BONUS TO REMOVE ALL', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 252 - h / 2))
+            system.blit(text, (24 + 6, 24 + 252 - h // 2))
             text = fonter.render('MONSTERS OF A RANDOM KIND.', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 276 - h / 2))
+            system.blit(text, (24 + 6, 24 + 276 - h // 2))
             shape = data.special[self.timer % 7]
             # Iter 1
             system.blit_board((0, 6, 3, 8))
@@ -1802,22 +1813,22 @@ class Monsterz:
             text = fonter.render('10', 36)
             w, h = text.get_rect().size
             x, y = data.board2screen((4, 7))
-            system.blit(text, (x + 24 - w / 2, y + 24 - h / 2))
+            system.blit(text, (x + 24 - w // 2, y + 24 - h // 2))
             x, y = data.board2screen((5, 6))
-            system.blit(text, (x + 24 - w / 2, y + 24 - h / 2))
+            system.blit(text, (x + 24 - w // 2, y + 24 - h // 2))
             x, y = data.board2screen((6, 6))
-            system.blit(text, (x + 24 - w / 2, y + 24 - h / 2))
+            system.blit(text, (x + 24 - w // 2, y + 24 - h // 2))
         elif self.page == 5:
             # Explanation 1
             text = fonter.render('IN PUZZLE MODE, PUT TOGETHER THE', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 84 - h / 2))
+            system.blit(text, (24 + 6, 24 + 84 - h // 2))
             text = fonter.render('PUZZLE BY MOVING PIECES AROUND. BE', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 108 - h / 2))
+            system.blit(text, (24 + 6, 24 + 108 - h // 2))
             text = fonter.render('CAREFUL NOT TO GET STUCK!', 24)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 6, 24 + 132 - h / 2))
+            system.blit(text, (24 + 6, 24 + 132 - h // 2))
             # Iter 1
             system.blit_board((0, 3, 2, 8))
             system.blit(data.normal[2], data.board2screen((0, 3)))
@@ -1876,19 +1887,19 @@ class Monsterz:
         self.copyright_draw()
         text = fonter.render('HIGH SCORES', 60)
         w, h = text.get_rect().size
-        system.blit(text, (24 + 192 - w / 2, 24 + 24 - h / 2))
+        system.blit(text, (24 + 192 - w // 2, 24 + 24 - h // 2))
         # Print our list
         for x in range(10):
             name, score, level = settings.scores['CLASSIC'][x]
             text = fonter.render(str(x + 1) + '. ' + name.upper(), 32)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 24, 24 + 72 + 32 * x - h / 2))
+            system.blit(text, (24 + 24, 24 + 72 + 32 * x - h // 2))
             text = fonter.render(str(score), 32)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 324 - w, 24 + 72 + 32 * x - h / 2))
+            system.blit(text, (24 + 324 - w, 24 + 72 + 32 * x - h // 2))
             text = fonter.render(str(level), 32)
             w, h = text.get_rect().size
-            system.blit(text, (24 + 360 - w, 24 + 72 + 32 * x - h / 2))
+            system.blit(text, (24 + 360 - w, 24 + 72 + 32 * x - h // 2))
         # Handle events
         for event in pygame.event.get():
             if self.generic_event(event):
@@ -1903,39 +1914,39 @@ class Monsterz:
                 return
 
 def version():
-    print 'monsterz ' + VERSION
-    print 'Written by Sam Hocevar, music by MenTaLguY, sound effects by Sun Microsystems,'
-    print 'Inc., Michael Speck, David White and the Battle for Wesnoth project, Mike'
-    print 'Kershaw and Sam Hocevar.'
-    print
-    print 'Copyright (C) 2005, 2006 Sam Hocevar <sam@zoy.org>'
-    print '          (C) 1998 MenTaLguY <mental@rydia.net>'
-    print '          (C) 2002, 2005 Sun Microsystems, Inc.'
-    print '          (C) Michael Speck <kulkanie@gmx.net>'
-    print '          (C) 2003 by David White <davidnwhite@optusnet.com.au> and the'
-    print '              Battle for Wesnoth project'
-    print '          (C) Mike Kershaw <dragorn@kismetwireless.net>'
+    print('monsterz ' + VERSION)
+    print('Written by Sam Hocevar, music by MenTaLguY, sound effects by Sun Microsystems,')
+    print('Inc., Michael Speck, David White and the Battle for Wesnoth project, Mike')
+    print('Kershaw and Sam Hocevar.')
+    print()
+    print('Copyright (C) 2005, 2006 Sam Hocevar <sam@zoy.org>')
+    print('          (C) 1998 MenTaLguY <mental@rydia.net>')
+    print('          (C) 2002, 2005 Sun Microsystems, Inc.')
+    print('          (C) Michael Speck <kulkanie@gmx.net>')
+    print('          (C) 2003 by David White <davidnwhite@optusnet.com.au> and the')
+    print('              Battle for Wesnoth project')
+    print('          (C) Mike Kershaw <dragorn@kismetwireless.net>')
 
-    print 'This program is free software; you can redistribute it and/or modify it under'
-    print 'the terms of the Do What The Fuck You Want To Public License, Version 2, as'
-    print 'published by Sam Hocevar. See http://sam.zoy.org/wtfpl/ for more details.'
-    print 'The sound effects are released under their own licences: applause.wav and'
-    print 'pop.wav are covered by the LGPL, the others are covered by the GPL.'
+    print('This program is free software; you can redistribute it and/or modify it under')
+    print('the terms of the Do What The Fuck You Want To Public License, Version 2, as')
+    print('published by Sam Hocevar. See http://sam.zoy.org/wtfpl/ for more details.')
+    print('The sound effects are released under their own licences: applause.wav and')
+    print('pop.wav are covered by the LGPL, the others are covered by the GPL.')
 
 def usage():
-    print 'Usage: monsterz [OPTION]...'
-    print
-    print 'Options'
-    print ' -h, --help         display this help and exit'
-    print ' -v, --version      display version information and exit'
-    print ' -f, --fullscreen   start in full screen mode'
-    print ' -m, --nomusic      disable music'
-    print ' -s, --nosfx        disable sound effects'
-    print '     --outfd <fd>   output scores to file descriptor <fd>'
-    print '     --data <dir>   set alternate data directory to <dir>'
-    print '     --score <file> set score file to <file>'
-    print
-    print 'Report bugs or suggestions to <sam@zoy.org>.'
+    print('Usage: monsterz [OPTION]...')
+    print()
+    print('Options')
+    print(' -h, --help         display this help and exit')
+    print(' -v, --version      display version information and exit')
+    print(' -f, --fullscreen   start in full screen mode')
+    print(' -m, --nomusic      disable music')
+    print(' -s, --nosfx        disable sound effects')
+    print('     --outfd <fd>   output scores to file descriptor <fd>')
+    print('     --data <dir>   set alternate data directory to <dir>')
+    print('     --score <file> set score file to <file>')
+    print()
+    print('Report bugs or suggestions to <sam@zoy.org>.')
 
 def main():
     from getopt import getopt, GetoptError
@@ -1967,7 +1978,7 @@ def main():
         elif opt in ('--outfd'):
             try:
                 outfd = int(arg)
-                write(outfd, '\n')
+                write(outfd, b'\n')
             except:
                 outfd = None
         elif opt in ('--data'):
@@ -1982,7 +1993,7 @@ def main():
     try:
         data = Data(sharedir)
     except:
-        print argv[0] + ': could not open data from `' + sharedir + "'."
+        print(argv[0] + ': could not open data from `' + sharedir + "'.")
         raise
     fonter = Fonter()
     monsterz = Monsterz()
