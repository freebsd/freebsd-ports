Partial backport of:
	https://github.com/Enlightenment/efl/commit/c245b576aad09ac5faeb800de7f7c4fef87c6363

EFL failed to build from source in Fedora Rawhide as a result of the update to GCC 10. GCC 10 enables -fno-common by default, and this found three issues in EFL:

  # The eina benchmark code defined int key_size in a header that was included in multiple places.
  # The elementary test code defines the "dt1", "dt2", "dt3" vars in two code files which are compiled together (but these variables do not appear to be used globally)
  # The eio test code defines the "ee" var in two code files which are compiled together (but this variable does not appear to be used globally)

I've fixed these issues and confirmed locally that the code builds again in Fedora.

Reviewed-by: Marcel Hollerbach <mail@marcel-hollerbach.de>
Differential Revision: https://phab.enlightenment.org/D11259

--- src/bin/elementary/test_ui_clock.c.orig	2020-08-25 18:28:31 UTC
+++ src/bin/elementary/test_ui_clock.c
@@ -5,7 +5,7 @@
 
 /* A simple test, just displaying clock in its default format */
 
-Evas_Object *dt1, *dt2, *dt3, *dt4;
+Evas_Object *uicdt1, *uicdt2, *uicdt3, *uicdt4;
 
 static void
 _changed_cb(void *data EINA_UNUSED, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
@@ -27,19 +27,19 @@ _bt_clicked(void *data EINA_UNUSED, Evas_Object *obj, 
    new_time.tm_mday = 26;
    new_time.tm_hour = 9;
    new_time.tm_min = 0;
-   efl_ui_clock_field_visible_set(dt1, EFL_UI_CLOCK_TYPE_HOUR, EINA_TRUE);
-   efl_ui_clock_field_visible_set(dt1, EFL_UI_CLOCK_TYPE_MINUTE, EINA_TRUE);
-   efl_ui_clock_field_visible_set(dt1, EFL_UI_CLOCK_TYPE_AMPM, EINA_TRUE);
-   efl_ui_clock_field_visible_set(dt1, EFL_UI_CLOCK_TYPE_SECOND, EINA_TRUE);
-   efl_ui_clock_field_visible_set(dt1, EFL_UI_CLOCK_TYPE_DAY, EINA_TRUE);
+   efl_ui_clock_field_visible_set(uicdt1, EFL_UI_CLOCK_TYPE_HOUR, EINA_TRUE);
+   efl_ui_clock_field_visible_set(uicdt1, EFL_UI_CLOCK_TYPE_MINUTE, EINA_TRUE);
+   efl_ui_clock_field_visible_set(uicdt1, EFL_UI_CLOCK_TYPE_AMPM, EINA_TRUE);
+   efl_ui_clock_field_visible_set(uicdt1, EFL_UI_CLOCK_TYPE_SECOND, EINA_TRUE);
+   efl_ui_clock_field_visible_set(uicdt1, EFL_UI_CLOCK_TYPE_DAY, EINA_TRUE);
 
-   efl_ui_clock_value_set(dt1, &new_time);
-   elm_object_disabled_set(dt1, EINA_TRUE);
+   efl_ui_clock_value_set(uicdt1, &new_time);
+   elm_object_disabled_set(uicdt1, EINA_TRUE);
 
    elm_object_disabled_set(obj, EINA_TRUE);
-   evas_object_del(dt2);
-   evas_object_del(dt3);
-   dt2 = dt3 = NULL;
+   evas_object_del(uicdt2);
+   evas_object_del(uicdt3);
+   uicdt2 = uicdt3 = NULL;
 }
 
 void
@@ -57,36 +57,36 @@ test_ui_clock(void *data EINA_UNUSED, Evas_Object *obj
    evas_object_show(bx);
    evas_object_size_hint_min_set(bx, 360, 240);
 
-   dt1 = efl_add(EFL_UI_CLOCK_CLASS, bx);
-   evas_object_size_hint_weight_set(dt1, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
-   evas_object_size_hint_align_set(dt1, EVAS_HINT_FILL, 0.5);
-   efl_ui_clock_field_visible_set(dt1, EFL_UI_CLOCK_TYPE_HOUR, EINA_FALSE);
-   efl_ui_clock_field_visible_set(dt1, EFL_UI_CLOCK_TYPE_MINUTE, EINA_FALSE);
-   efl_ui_clock_field_visible_set(dt1, EFL_UI_CLOCK_TYPE_AMPM, EINA_FALSE);
-   efl_ui_clock_field_visible_set(dt1, EFL_UI_CLOCK_TYPE_SECOND, EINA_FALSE);
-   efl_ui_clock_field_visible_set(dt1, EFL_UI_CLOCK_TYPE_DAY, EINA_FALSE);
-   efl_ui_clock_pause_set(dt1, EINA_TRUE);
-   elm_box_pack_end(bx, dt1);
-   evas_object_smart_callback_add(dt1, "changed", _changed_cb, NULL);
-   evas_object_show(dt1);
+   uicdt1 = efl_add(EFL_UI_CLOCK_CLASS, bx);
+   evas_object_size_hint_weight_set(uicdt1, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
+   evas_object_size_hint_align_set(uicdt1, EVAS_HINT_FILL, 0.5);
+   efl_ui_clock_field_visible_set(uicdt1, EFL_UI_CLOCK_TYPE_HOUR, EINA_FALSE);
+   efl_ui_clock_field_visible_set(uicdt1, EFL_UI_CLOCK_TYPE_MINUTE, EINA_FALSE);
+   efl_ui_clock_field_visible_set(uicdt1, EFL_UI_CLOCK_TYPE_AMPM, EINA_FALSE);
+   efl_ui_clock_field_visible_set(uicdt1, EFL_UI_CLOCK_TYPE_SECOND, EINA_FALSE);
+   efl_ui_clock_field_visible_set(uicdt1, EFL_UI_CLOCK_TYPE_DAY, EINA_FALSE);
+   efl_ui_clock_pause_set(uicdt1, EINA_TRUE);
+   elm_box_pack_end(bx, uicdt1);
+   evas_object_smart_callback_add(uicdt1, "changed", _changed_cb, NULL);
+   evas_object_show(uicdt1);
 
-   dt2 = efl_add(EFL_UI_CLOCK_CLASS, bx);
-   evas_object_size_hint_weight_set(dt2, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
-   evas_object_size_hint_align_set(dt2, EVAS_HINT_FILL, 0.5);
-   efl_ui_clock_field_visible_set(dt2, EFL_UI_CLOCK_TYPE_YEAR, EINA_FALSE);
-   efl_ui_clock_field_visible_set(dt2, EFL_UI_CLOCK_TYPE_MONTH, EINA_FALSE);
-   efl_ui_clock_field_visible_set(dt2, EFL_UI_CLOCK_TYPE_DATE, EINA_FALSE);
-   efl_ui_clock_field_visible_set(dt1, EFL_UI_CLOCK_TYPE_SECOND, EINA_FALSE);
-   elm_box_pack_end(bx, dt2);
-   efl_ui_clock_pause_set(dt2, EINA_TRUE);
-   elm_object_disabled_set(dt2, EINA_TRUE);
-   evas_object_show(dt2);
+   uicdt2 = efl_add(EFL_UI_CLOCK_CLASS, bx);
+   evas_object_size_hint_weight_set(uicdt2, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
+   evas_object_size_hint_align_set(uicdt2, EVAS_HINT_FILL, 0.5);
+   efl_ui_clock_field_visible_set(uicdt2, EFL_UI_CLOCK_TYPE_YEAR, EINA_FALSE);
+   efl_ui_clock_field_visible_set(uicdt2, EFL_UI_CLOCK_TYPE_MONTH, EINA_FALSE);
+   efl_ui_clock_field_visible_set(uicdt2, EFL_UI_CLOCK_TYPE_DATE, EINA_FALSE);
+   efl_ui_clock_field_visible_set(uicdt1, EFL_UI_CLOCK_TYPE_SECOND, EINA_FALSE);
+   elm_box_pack_end(bx, uicdt2);
+   efl_ui_clock_pause_set(uicdt2, EINA_TRUE);
+   elm_object_disabled_set(uicdt2, EINA_TRUE);
+   evas_object_show(uicdt2);
 
-   dt3 = efl_add(EFL_UI_CLOCK_CLASS, bx);
-   evas_object_size_hint_weight_set(dt3, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
-   evas_object_size_hint_align_set(dt3, EVAS_HINT_FILL, 0.5);
-   elm_box_pack_end(bx, dt3);
-   evas_object_show(dt3);
+   uicdt3 = efl_add(EFL_UI_CLOCK_CLASS, bx);
+   evas_object_size_hint_weight_set(uicdt3, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
+   evas_object_size_hint_align_set(uicdt3, EVAS_HINT_FILL, 0.5);
+   elm_box_pack_end(bx, uicdt3);
+   evas_object_show(uicdt3);
 
    //editable
    lb = efl_add(ELM_LABEL_CLASS, bx);
@@ -99,13 +99,13 @@ test_ui_clock(void *data EINA_UNUSED, Evas_Object *obj
    elm_box_pack_end(bx, lb);
    evas_object_show(lb);
 
-   dt4 = efl_add(EFL_UI_CLOCK_CLASS, bx);
-   evas_object_size_hint_weight_set(dt4, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
-   evas_object_size_hint_align_set(dt4, EVAS_HINT_FILL, 0.5);
-   efl_ui_clock_edit_mode_set(dt4, EINA_TRUE);
-   efl_ui_clock_pause_set(dt4, EINA_TRUE);
-   elm_box_pack_end(bx, dt4);
-   evas_object_show(dt4);
+   uicdt4 = efl_add(EFL_UI_CLOCK_CLASS, bx);
+   evas_object_size_hint_weight_set(uicdt4, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
+   evas_object_size_hint_align_set(uicdt4, EVAS_HINT_FILL, 0.5);
+   efl_ui_clock_edit_mode_set(uicdt4, EINA_TRUE);
+   efl_ui_clock_pause_set(uicdt4, EINA_TRUE);
+   elm_box_pack_end(bx, uicdt4);
+   evas_object_show(uicdt4);
 
    bt = elm_button_add(win);
    elm_object_text_set(bt, "Back to the future...");
