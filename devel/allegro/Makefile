# New ports collection makefile for:	allegro
# Date created:		23-Feb-2001
# Whom:			Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	allegro
PORTVERSION=	3.9.34
CATEGORIES=	devel
MASTER_SITES=	http://sunsite.dk/allegro/

MAINTAINER=	olgeni@FreeBSD.org

USE_AUTOCONF_VER=213
USE_GMAKE=	yes
MAKEFILE=	makefile
INSTALLS_SHLIB=	yes

.if !defined (WITHOUT_DEVEL)
INSTALL_TARGET=	full-install
PLIST_SUB+=	FULL=""
.else
INSTALL_TARGET=	mini-install
PLIST_SUB+=	FULL="@comment "
.endif

pre-configure:
	${PERL} -pi -e "s@AUTOHEADER = autoheader@AUTOHEADER =${AUTOHEADER}@g" \
		${WRKSRC}/makefile.in

pre-build:
	cd ${WRKSRC} && ${GMAKE} depend

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/allegro
	${CP} ${WRKSRC}/docs/*html ${PREFIX}/share/doc/allegro
.endif

.if !defined (WITHOUT_MAN)
INSTALL_TARGET+=	install-man
MAN3=	ASSERT.3 MASK_COLOR_15.3 MASK_COLOR_16.3 \
	MASK_COLOR_24.3 MASK_COLOR_32.3 MASK_COLOR_8.3 TRACE.3 \
	_getpixel.3 _getpixel15.3 _getpixel16.3 _getpixel24.3 \
	_getpixel32.3 _putpixel.3 _putpixel15.3 _putpixel16.3 \
	_putpixel24.3 _putpixel32.3 _set_color.3 acquire_bitmap.3 \
	acquire_screen.3 al_assert.3 active_dialog.3 active_menu.3 \
	adjust_sample.3 al_trace.3 alert.3 alert3.3 allegro_error.3 \
	allegro_exit.3 allegro_id.3 allegro_init.3 allegro_message.3 \
	allocate_voice.3 append_filename.3 apply_matrix.3 \
	apply_matrix_f.3 apply_quat.3 arc.3 bestfit_color.3 \
	bitmap_color_depth.3 bitmap_mask_color.3 black_palette.3 \
	blit.3 bmp_read_line.3 bmp_unwrite_line.3 bmp_write_line.3 \
	broadcast_dialog_message.3 calc_spline.3 \
	calibrate_joystick.3 calibrate_joystick_name.3 \
	centre_dialog.3 check_cpu.3 circle.3 circlefill.3 clear.3 \
	clear_keybuf.3 clear_to_color.3 clear_zbuffer.3 clip3d.3 \
	clip3d_f.3 close_fli.3 color_map.3 config_is_hooked.3 \
	cpu_3dnow.3 cpu_cpuid.3 cpu_family.3 cpu_fpu.3 cpu_mmx.3 \
	cpu_model.3 cpu_vendor.3 create_bitmap.3 create_bitmap_ex.3 \
	create_blender_table.3 create_color_table.3 \
	create_light_table.3 create_rgb_table.3 create_sample.3 \
	create_sub_bitmap.3 create_system_bitmap.3 \
	create_trans_table.3 create_video_bitmap.3 create_zbuffer.3 \
	cross_product.3 cross_product_f.3 d_bitmap_proc.3 \
	d_box_proc.3 d_button_proc.3 d_check_proc.3 d_clear_proc.3 \
	d_ctext_proc.3 d_edit_proc.3 d_icon_proc.3 d_keyboard_proc.3 \
	d_list_proc.3 d_menu_proc.3 d_radio_proc.3 d_rtext_proc.3 \
	d_shadow_box_proc.3 d_slider_proc.3 d_text_list_proc.3 \
	d_text_proc.3 d_textbox_proc.3 d_yield_proc.3 \
	deallocate_voice.3 default_palette.3 delete_file.3 \
	desktop_color_depth.3 desktop_palette.3 destroy_bitmap.3 \
	destroy_compiled_sprite.3 destroy_font.3 destroy_midi.3 \
	destroy_rle_sprite.3 destroy_sample.3 destroy_zbuffer.3 \
	detect_digi_driver.3 detect_midi_driver.3 dialog_message.3 \
	digi_recorder.3 do_arc.3 do_circle.3 do_dialog.3 \
	do_ellipse.3 do_line.3 do_menu.3 do_uconvert.3 dot_product.3 \
	dot_product_f.3 draw_character.3 draw_compiled_sprite.3 \
	draw_gouraud_sprite.3 draw_lit_rle_sprite.3 \
	draw_lit_sprite.3 draw_rle_sprite.3 draw_sprite.3 \
	draw_sprite_h_flip.3 draw_sprite_v_flip.3 \
	draw_sprite_vh_flip.3 draw_trans_rle_sprite.3 \
	draw_trans_sprite.3 drawing_mode.3 ellipse.3 ellipsefill.3 \
	empty_string.3 enable_triple_buffer.3 exists.3 facos.3 \
	fadd.3 fade_from.3 fade_from_range.3 fade_in.3 \
	fade_in_range.3 fade_interpolate.3 fade_out.3 \
	fade_out_range.3 fasin.3 fatan.3 fatan2.3 fcos.3 fdiv.3 \
	fhypot.3 file_exists.3 file_select.3 file_select_ex.3 \
	file_size.3 file_time.3 find_allegro_resource.3 \
	find_datafile_object.3 find_dialog_focus.3 findclose.3 \
	findfirst.3 findnext.3 fix_filename_case.3 \
	fix_filename_path.3 fix_filename_slashes.3 fixtof.3 fixtoi.3 \
	fixup_datafile.3 fli_bitmap.3 fli_bmp_dirty_from.3 \
	fli_bmp_dirty_to.3 fli_frame.3 fli_pal_dirty_from.3 \
	fli_pal_dirty_to.3 fli_palette.3 fli_timer.3 floodfill.3 \
	fmul.3 font.3 for_each_file.3 free_audio_stream_buffer.3 \
	freeze_mouse_flag.3 fsin.3 fsqrt.3 fsub.3 ftan.3 ftofix.3 \
	generate_332_palette.3 generate_optimized_palette.3 \
	get_align_matrix.3 get_align_matrix_f.3 \
	get_audio_stream_buffer.3 geta.3 get_camera_matrix.3 \
	get_camera_matrix_f.3 get_color.3 get_compiled_sprite.3 \
	get_config_argv.3 get_config_float.3 get_config_hex.3 \
	get_config_id.3 get_config_int.3 get_config_string.3 \
	get_config_text.3 get_datafile_property.3 \
	get_display_switch_mode.3 get_executable_name.3 \
	get_extension.3 get_filename.3 get_mouse_mickeys.3 \
	get_palette.3 get_palette_range.3 get_refresh_rate.3 \
	get_rle_sprite.3 get_rotation_matrix.3 \
	get_rotation_matrix_f.3 get_rotation_quat.3 \
	get_scaling_matrix.3 get_scaling_matrix_f.3 \
	get_sound_input_cap_bits.3 get_sound_input_cap_parm.3 \
	get_sound_input_cap_rate.3 get_sound_input_cap_stereo.3 \
	get_transformation_matrix.3 get_transformation_matrix_f.3 \
	get_translation_matrix.3 get_translation_matrix_f.3 \
	get_uformat.3 get_vector_rotation_matrix.3 \
	get_vector_rotation_matrix_f.3 get_vector_rotation_quat.3 \
	get_x_rotate_matrix.3 get_x_rotate_matrix_f.3 \
	get_x_rotate_quat.3 get_y_rotate_matrix.3 \
	get_y_rotate_matrix_f.3 get_y_rotate_quat.3 \
	get_z_rotate_matrix.3 get_z_rotate_matrix_f.3 \
	get_z_rotate_quat.3 geta32.3 geta_depth.3 getb.3 getb15.3 \
	getb16.3 getb24.3 getb32.3 getb8.3 getb_depth.3 getg.3 \
	getg15.3 getg16.3 getg24.3 getg32.3 getg8.3 getg_depth.3 \
	getpixel.3 getr.3 getr15.3 getr16.3 getr24.3 getr32.3 \
	getr8.3 getr_depth.3 gfx_capabilities.3 gfx_mode_select.3 \
	gfx_mode_select_ex.3 gui_bg_color.3 gui_fg_color.3 \
	gui_font_baseline.3 gui_mg_color.3 gui_mouse_b.3 \
	gui_mouse_focus.3 gui_mouse_x.3 gui_mouse_y.3 gui_mouse_z.3 \
	gui_strlen.3 gui_textout.3 hline.3 hook_config_section.3 \
	hsv_to_rgb.3 identity_matrix.3 identity_matrix_f.3 \
	identity_quat.3 init_dialog.3 install_allegro.3 \
	install_int.3 install_int_ex.3 install_joystick.3 \
	install_keyboard.3 install_keyboard_hooks.3 install_mouse.3 \
	install_param_int.3 install_param_int_ex.3 install_sound.3 \
	install_sound_input.3 install_timer.3 is_linear_bitmap.3 \
	is_memory_bitmap.3 is_planar_bitmap.3 is_same_bitmap.3 \
	is_screen_bitmap.3 is_sub_bitmap.3 is_system_bitmap.3 \
	is_video_bitmap.3 itofix.3 joy.3 key.3 key_led_flag.3 \
	key_shifts.3 keyboard_callback.3 \
	keyboard_lowlevel_callback.3 keyboard_needs_poll.3 \
	keyboard_ucallback.3 keypressed.3 line.3 load_bitmap.3 \
	load_bmp.3 load_datafile.3 load_datafile_callback.3 \
	load_datafile_object.3 load_ibk.3 load_joystick_data.3 \
	load_lbm.3 load_midi.3 load_midi_patches.3 load_pcx.3 \
	load_sample.3 load_tga.3 load_voc.3 load_wav.3 makeacol.3 \
	makeacol32.3 makeacol_depth.3 makecol.3 makecol15.3 \
	makecol15_dither.3 makecol16.3 makecol16_dither.3 \
	makecol24.3 makecol32.3 makecol8.3 makecol_depth.3 \
	masked_blit.3 masked_stretch_blit.3 matrix_mul.3 \
	matrix_mul_f.3 matrix_to_quat.3 midi_loop_end.3 \
	midi_loop_start.3 midi_meta_callback.3 midi_msg_callback.3 \
	midi_out.3 midi_pause.3 midi_pos.3 midi_recorder.3 \
	midi_resume.3 midi_seek.3 midi_sysex_callback.3 mouse_b.3 \
	mouse_callback.3 mouse_needs_poll.3 mouse_pos.3 mouse_x.3 \
	mouse_y.3 mouse_z.3 need_uconvert.3 next_fli_frame.3 \
	normalize_vector.3 normalize_vector_f.3 num_joysticks.3 \
	open_fli.3 open_memory_fli.3 os_type.3 \
	override_config_data.3 override_config_file.3 pack_fclose.3 \
	pack_fclose_chunk.3 pack_feof.3 pack_ferror.3 pack_fgets.3 \
	pack_fopen.3 pack_fopen_chunk.3 pack_fputs.3 pack_fread.3 \
	pack_fseek.3 pack_fwrite.3 pack_getc.3 pack_igetl.3 \
	pack_igetw.3 pack_iputl.3 pack_iputw.3 pack_mgetl.3 \
	pack_mgetw.3 pack_mputl.3 pack_mputw.3 pack_putc.3 \
	packfile_password.3 palette_color.3 persp_project.3 \
	persp_project_f.3 pivot_scaled_sprite.3 pivot_sprite.3 \
	pivot_sprite_v_flip.3 play_audio_stream.3 play_fli.3 \
	play_looped_midi.3 play_memory_fli.3 play_midi.3 \
	play_sample.3 poll_joystick.3 poll_keyboard.3 poll_mouse.3 \
	poll_scroll.3 polygon.3 polygon3d.3 polygon3d_f.3 \
	polygon_z_normal.3 polygon_z_normal_f.3 pop_config_state.3 \
	popup_dialog.3 position_dialog.3 position_mouse.3 \
	position_mouse_z.3 push_config_state.3 put_backslash.3 \
	putpixel.3 qscale_matrix.3 rect.3 qscale_matrix_f.3 \
	qtranslate_matrix.3 qtranslate_matrix_f.3 quad3d.3 \
	quad3d_f.3 quat_interpolate.3 quat_mul.3 quat_slerp.3 \
	quat_to_matrix.3 read_sound_input.3 readkey.3 \
	reallocate_voice.3 rectfill.3 register_assert_handler.3 \
	register_bitmap_file_type.3 register_datafile_object.3 \
	register_trace_handler.3 register_uformat.3 rest.3 \
	release_bitmap.3 release_screen.3 release_voice.3 \
	remove_display_switch_callback.3 remove_int.3 \
	remove_joystick.3 remove_keyboard.3 remove_mouse.3 \
	remove_param_int.3 remove_sound.3 remove_sound_input.3 \
	remove_timer.3 replace_extension.3 replace_filename.3 \
	request_refresh_rate.3 request_scroll.3 \
	request_video_bitmap.3 reserve_voices.3 \
	reset_fli_variables.3 rest_callback.3 retrace_count.3 \
	retrace_proc.3 rgb_map.3 rgb_to_hsv.3 rotate_scaled_sprite.3 \
	rotate_sprite.3 rotate_sprite_v_flip.3 save_bitmap.3 \
	save_bmp.3 save_joystick_data.3 save_pcx.3 save_tga.3 \
	scancode_to_ascii.3 scare_mouse.3 scare_mouse_area.3 \
	screen.3 scroll_screen.3 select_palette.3 set_add_blender.3 \
	set_alpha_blender.3 set_blender_mode.3 set_blender_mode_ex.3 \
	set_burn_blender.3 set_clip.3 set_color.3 \
	set_color_blender.3 set_color_conversion.3 set_color_depth.3 \
	set_config_data.3 set_config_file.3 set_config_float.3 \
	set_config_hex.3 set_config_id.3 set_config_int.3 \
	set_config_string.3 set_dialog_color.3 set_leds.3 \
	set_difference_blender.3 set_display_switch_callback.3 \
	set_display_switch_mode.3 set_dissolve_blender.3 \
	set_dodge_blender.3 set_gfx_mode.3 set_hue_blender.3 \
	set_invert_blender.3 set_keyboard_rate.3 \
	set_luminance_blender.3 set_mouse_range.3 set_mouse_speed.3 \
	set_mouse_sprite.3 set_mouse_sprite_focus.3 \
	set_multiply_blender.3 set_palette.3 spline.3 \
	set_palette_range.3 set_projection_viewport.3 \
	set_saturation_blender.3 set_screen_blender.3 \
	set_sound_input_source.3 set_trans_blender.3 set_ucodepage.3 \
	set_uformat.3 set_volume.3 set_volume_per_voice.3 \
	set_window_title.3 set_write_alpha_blender.3 show_mouse.3 \
	show_video_bitmap.3 shutdown_dialog.3 simulate_keypress.3 \
	simulate_ukeypress.3 solid_mode.3 start_sound_input.3 \
	stop_audio_stream.3 stop_midi.3 stop_sample.3 \
	stop_sound_input.3 stretch_blit.3 stretch_sprite.3 \
	text_height.3 text_length.3 text_mode.3 textout.3 \
	textout_centre.3 textout_justify.3 textout_right.3 \
	textprintf.3 textprintf_centre.3 textprintf_justify.3 \
	textprintf_right.3 three_finger_flag.3 \
	timer_can_simulate_retrace.3 timer_is_using_retrace.3 \
	timer_simulate_retrace.3 triangle.3 triangle3d.3 \
	triangle3d_f.3 uatof.3 uconvert.3 uconvert_ascii.3 \
	uconvert_size.3 uconvert_toascii.3 ucwidth.3 ugetat.3 \
	ugetc.3 ugetx.3 ugetxc.3 uinsert.3 uisdigit.3 uisok.3 \
	uisspace.3 unload_datafile.3 uoffset.3 \
	unload_datafile_object.3 unscare_mouse.3 unselect_palette.3 \
	update_dialog.3 ureadkey.3 uremove.3 usetat.3 usetc.3 \
	usprintf.3 ustrcat.3 ustrchr.3 ustrcmp.3 ustrcpy.3 ustrdup.3 \
	ustrerror.3 ustricmp.3 ustrlen.3 ustrlwr.3 ustrncat.3 \
	ustrncmp.3 ustrncpy.3 ustrpbrk.3 ustrrchr.3 ustrsize.3 \
	ustrsizez.3 ustrstr.3 ustrtod.3 ustrtok.3 ustrtol.3 \
	ustrupr.3 utolower.3 utoupper.3 uvsprintf.3 uwidth.3 \
	uwidth_max.3 vector_length.3 vector_length_f.3 vline.3 \
	voice_check.3 voice_get_frequency.3 voice_get_pan.3 \
	voice_get_position.3 voice_get_volume.3 voice_ramp_volume.3 \
	voice_set_echo.3 voice_set_pan.3 voice_set_frequency.3 \
	voice_set_playmode.3 voice_set_position.3 \
	voice_set_priority.3 voice_set_tremolo.3 voice_set_vibrato.3 \
	voice_set_volume.3 voice_start.3 voice_stop.3 \
	voice_stop_frequency_sweep.3 voice_stop_pan_sweep.3 \
	voice_stop_volumeramp.3 voice_sweep_frequency.3 \
	voice_sweep_pan.3 vsync.3 xor_mode.3 yield_timeslice.3
.endif

.include <bsd.port.mk>
