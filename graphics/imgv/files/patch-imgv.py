--- imgv.py.orig	Wed Oct 18 06:01:50 2006
+++ imgv.py	Sat Feb  3 11:39:31 2007
@@ -18,17 +18,17 @@
 import pygame.event, pygame.time
 from pygame.display import set_caption, set_mode, update
 from pygame.locals import  MOUSEMOTION, MOUSEBUTTONDOWN, Rect, KEYDOWN, KEYUP, RESIZABLE, VIDEORESIZE, MOUSEBUTTONUP, K_UP, K_DOWN, K_RIGHT, K_LEFT
-import gl
-from load_timers import start_timer, check_timer
-from img_screen import init_screen, get_center, my_update_screen, img_border, paint_screen
-from show_message import show_message
-from cursor import wait_cursor, normal_cursor, drag_hand_cursor, grab_hand_cursor
-from usr_event import check_quit, right_click, left_click
-from load_img import load_img
-from handle_keyboard import handle_keyboard
-from main_menu import command_main_menu
-from pan import command_down, command_up, command_right, command_left
-from res import command_fullscreen
+from imgv import gl
+from imgv.load_timers import start_timer, check_timer
+from imgv.img_screen import init_screen, get_center, my_update_screen, img_border, paint_screen
+from imgv.show_message import show_message
+from imgv.cursor import wait_cursor, normal_cursor, drag_hand_cursor, grab_hand_cursor
+from imgv.usr_event import check_quit, right_click, left_click
+from imgv.load_img import load_img
+from imgv.handle_keyboard import handle_keyboard
+from imgv.main_menu import command_main_menu
+from imgv.pan import command_down, command_up, command_right, command_left
+from imgv.res import command_fullscreen
 
 def main():
     pygame.time.delay(5) # to make start_timer() work initially
