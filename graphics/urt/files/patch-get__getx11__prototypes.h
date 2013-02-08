--- get/getx11/prototypes.h.orig	1993-01-12 06:56:21.000000000 +0900
+++ get/getx11/prototypes.h	2012-10-13 07:04:08.000000000 +0900
@@ -1,5 +1,5 @@
 extern void init_img_info(image_information *i);
-extern void main(int argc, char **argv);
+extern int main(int argc, char **argv);
 extern void handle_exposure(register image_information *img, int x, int y, int width, int height, int img_h);
 extern image_information *action_flip_forward(image_information *img, image_information *img_info, int flip_book_udelay, int n, unsigned long mask, XEvent *event, Boolean *found_event);
 extern image_information *action_flip_backward(image_information *img, image_information *img_info, int flip_book_udelay, int n, unsigned long mask, XEvent *event, Boolean *found_event);
