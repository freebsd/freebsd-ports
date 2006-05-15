# New ports collection makefile for:	ncurses
# Date created:				23 September 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		ncurses
PORTVERSION=		5.5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		garga@FreeBSD.org
COMMENT=		Library for terminal-independent, full-screen output

LIB_DEPENDS=		utf-8:${PORTSDIR}/converters/libutf-8

NO_FILTER_SHLIBS=	no

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/misc --disable-overwrite \
		--disable-termcap --includedir=${PREFIX}/include/ncurses \
		--with-profile --with-shared --without-debug \
		--without-curses-h --with-termlib --program-prefix= \
		--enable-safe-sprintf --disable-root-environ \
		--with-manpage-format=gzip  #--enable-widec
# needed by devel/py-ncurses port
.if defined(WITH_TRACE)
CONFIGURE_ARGS+=	--with-trace
.endif

CONFIGURE_ENV=	gnat_exists="no" \
		ac_cv_path_LDCONFIG="${LDCONFIG} -m ${PREFIX}/lib"

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

INSTALLS_SHLIB=	yes
MANCOMPRESSED=	yes
MAN1=	captoinfo.1m clear.1 infocmp.1m infotocap.1m reset.1 tack.1 \
	tic.1m toe.1m tput.1 tset.1
MAN3=	COLOR_PAIR.3x PAIR_NUMBER.3x _nc_tracebits.3x _traceattr.3x \
	_traceattr2.3x _tracechar.3x _tracechtype.3x _tracechtype2.3x \
	_tracedump.3x _tracef.3x _tracemouse.3x add_wch.3x add_wchnstr.3x \
	add_wchstr.3x addch.3x addchnstr.3x addchstr.3x addnstr.3x addnwstr.3x \
	addstr.3x addwstr.3x assume_default_colors.3x attr_get.3x attr_off.3x \
	attr_on.3x attr_set.3x attroff.3x attron.3x attrset.3x baudrate.3x \
	beep.3x bkgd.3x bkgdset.3x bkgrnd.3x bkgrndset.3x border.3x \
	border_set.3x bottom_panel.3x box.3x box_set.3x can_change_color.3x \
	cbreak.3x chgat.3x clear.3x clearok.3x clrtobot.3x clrtoeol.3x \
	color_content.3x color_set.3x copywin.3x current_field.3x \
	current_item.3x curs_add_wch.3x curs_add_wchstr.3x curs_addch.3x \
	curs_addchstr.3x curs_addstr.3x curs_addwstr.3x curs_attr.3x \
	curs_beep.3x curs_bkgd.3x curs_bkgrnd.3x curs_border.3x \
	curs_border_set.3x curs_clear.3x curs_color.3x curs_delch.3x \
	curs_deleteln.3x curs_extend.3x curs_get_wch.3x curs_get_wstr.3x \
	curs_getcchar.3x curs_getch.3x curs_getstr.3x curs_getyx.3x \
	curs_in_wch.3x curs_in_wchstr.3x curs_inch.3x curs_inchstr.3x \
	curs_initscr.3x curs_inopts.3x curs_ins_wch.3x curs_ins_wstr.3x \
	curs_insch.3x curs_insstr.3x curs_instr.3x curs_inwstr.3x \
	curs_kernel.3x curs_mouse.3x curs_move.3x curs_outopts.3x \
	curs_overlay.3x curs_pad.3x curs_print.3x curs_printw.3x \
	curs_refresh.3x curs_scanw.3x curs_scr_dump.3x curs_scroll.3x \
	curs_set.3x curs_slk.3x curs_termattrs.3x curs_termcap.3x \
	curs_terminfo.3x curs_touch.3x curs_trace.3x curs_util.3x \
	curs_window.3x curses_version.3x data_ahead.3x data_behind.3x \
	def_prog_mode.3x def_shell_mode.3x default_colors.3x define_key.3x \
	del_curterm.3x del_panel.3x delay_output.3x delch.3x deleteln.3x \
	delscreen.3x delwin.3x derwin.3x doupdate.3x dup_field.3x dupwin.3x \
	dynamic_field_info.3x echo.3x echo_wchar.3x echochar.3x endwin.3x \
	erase.3x erasechar.3x erasewchar.3x field_arg.3x \
	field_back.3x field_buffer.3x field_count.3x field_fore.3x \
	field_index.3x field_info.3x field_just.3x field_opts.3x \
	field_opts_off.3x field_opts_on.3x field_pad.3x field_status.3x \
	field_type.3x field_userptr.3x filter.3x flash.3x flushinp.3x form.3x \
	form_cursor.3x form_data.3x form_driver.3x form_field.3x \
	form_field_attributes.3x form_field_buffer.3x form_field_info.3x \
	form_field_just.3x form_field_new.3x form_field_opts.3x \
	form_field_userptr.3x form_field_validation.3x form_fields.3x \
	form_fieldtype.3x form_hook.3x form_new.3x form_new_page.3x \
	form_opts.3x form_opts_off.3x form_opts_on.3x form_page.3x \
	form_post.3x form_request_by_name.3x form_request_name.3x \
	form_requestname.3x form_sub.3x form_userptr.3x form_win.3x \
	free_field.3x free_fieldtype.3x free_form.3x free_item.3x free_menu.3x \
	get_wch.3x get_wstr.3x getbegyx.3x getbkgd.3x getbkgrnd.3x getcchar.3x \
	getch.3x getmaxyx.3x getmouse.3x getn_wstr.3x getnstr.3x getparyx.3x \
	getstr.3x getsyx.3x getwin.3x getyx.3x halfdelay.3x has_colors.3x \
	has_ic.3x has_il.3x has_key.3x hide_panel.3x hline.3x hline_set.3x \
	idcok.3x idlok.3x immedok.3x in_wch.3x in_wchnstr.3x in_wchstr.3x \
	inch.3x inchnstr.3x inchstr.3x init_color.3x init_pair.3x initscr.3x \
	innstr.3x innwstr.3x ins_nwstr.3x ins_wch.3x ins_wstr.3x insch.3x \
	insdelln.3x insertln.3x insnstr.3x insstr.3x instr.3x intrflush.3x \
	inwstr.3x is_linetouched.3x is_term_resized.3x is_wintouched.3x \
	isendwin.3x item_count.3x item_description.3x item_index.3x \
	item_name.3x item_opts.3x item_opts_off.3x item_opts_on.3x \
	item_userptr.3x item_value.3x item_visible.3x key_name.3x keybound.3x \
	keyname.3x keyok.3x keypad.3x killchar.3x killwchar.3x leaveok.3x \
	link_field.3x link_fieldtype.3x longname.3x mcprint.3x menu.3x \
	menu_attributes.3x menu_back.3x menu_cursor.3x menu_driver.3x \
	menu_fore.3x menu_format.3x menu_grey.3x menu_hook.3x menu_items.3x \
	menu_mark.3x menu_new.3x menu_opts.3x menu_opts_off.3x menu_opts_on.3x \
	menu_pad.3x menu_pattern.3x menu_post.3x menu_request_by_name.3x \
	menu_request_name.3x menu_requestname.3x menu_spacing.3x menu_sub.3x \
	menu_userptr.3x menu_win.3x meta.3x mitem_current.3x mitem_name.3x \
	mitem_new.3x mitem_opts.3x mitem_userptr.3x mitem_value.3x \
	mitem_visible.3x mouse_trafo.3x mouseinterval.3x mousemask.3x move.3x \
	move_field.3x move_panel.3x mvadd_wch.3x mvadd_wchnstr.3x \
	mvadd_wchstr.3x mvaddch.3x mvaddchnstr.3x mvaddchstr.3x mvaddnstr.3x \
	mvaddnwstr.3x mvaddstr.3x mvaddwstr.3x mvchgat.3x mvcur.3x mvdelch.3x \
	mvderwin.3x mvget_wch.3x mvget_wstr.3x mvgetch.3x mvgetn_wstr.3x \
	mvgetnstr.3x mvgetstr.3x mvhline.3x mvhline_set.3x mvin_wch.3x \
	mvin_wchnstr.3x mvin_wchstr.3x mvinch.3x mvinchnstr.3x mvinchstr.3x \
	mvinnstr.3x mvinnwstr.3x mvins_nwstr.3x mvins_wch.3x mvins_wstr.3x \
	mvinsch.3x mvinsnstr.3x mvinsstr.3x mvinstr.3x mvinwstr.3x mvprintw.3x \
	mvscanw.3x mvvline.3x mvvline_set.3x mvwadd_wch.3x mvwadd_wchnstr.3x \
	mvwadd_wchstr.3x mvwaddch.3x mvwaddchnstr.3x mvwaddchstr.3x \
	mvwaddnstr.3x mvwaddnwstr.3x mvwaddstr.3x mvwaddwstr.3x mvwchgat.3x \
	mvwdelch.3x mvwget_wch.3x mvwget_wstr.3x mvwgetch.3x mvwgetn_wstr.3x \
	mvwgetnstr.3x mvwgetstr.3x mvwhline.3x mvwhline_set.3x mvwin.3x \
	mvwin_wch.3x mvwin_wchnstr.3x mvwin_wchstr.3x mvwinch.3x \
	mvwinchnstr.3x mvwinchstr.3x mvwinnstr.3x mvwinnwstr.3x \
	mvwins_nwstr.3x mvwins_wch.3x mvwins_wstr.3x mvwinsch.3x mvwinsnstr.3x \
	mvwinsstr.3x mvwinstr.3x mvwinwstr.3x mvwprintw.3x mvwscanw.3x \
	mvwvline.3x mvwvline_set.3x napms.3x ncurses.3x new_field.3x \
	new_fieldtype.3x new_form.3x new_item.3x new_menu.3x new_page.3x \
	new_panel.3x newpad.3x newterm.3x newwin.3x nl.3x nocbreak.3x \
	nodelay.3x noecho.3x nonl.3x noqiflush.3x noraw.3x notimeout.3x \
	overlay.3x overwrite.3x pair_content.3x panel.3x panel_above.3x \
	panel_below.3x panel_hidden.3x panel_userptr.3x panel_window.3x \
	pechochar.3x pnoutrefresh.3x pos_form_cursor.3x pos_menu_cursor.3x \
	post_form.3x post_menu.3x prefresh.3x printw.3x putp.3x putwin.3x \
	qiflush.3x raw.3x redrawwin.3x refresh.3x replace_panel.3x \
	reset_prog_mode.3x reset_shell_mode.3x resetty.3x resize_term.3x \
	resizeterm.3x restartterm.3x ripoffline.3x savetty.3x scale_form.3x \
	scale_menu.3x scanw.3x scr_dump.3x scr_init.3x scr_restore.3x \
	scr_set.3x scrl.3x scroll.3x scrollok.3x set_current_field.3x \
	set_current_item.3x set_curterm.3x set_field_back.3x \
	set_field_buffer.3x set_field_fore.3x set_field_init.3x \
	set_field_just.3x set_field_opts.3x set_field_pad.3x \
	set_field_status.3x set_field_term.3x set_field_type.3x \
	set_field_userptr.3x set_fieldtype_arg.3x set_fieldtype_choice.3x \
	set_form_fields.3x set_form_init.3x set_form_opts.3x set_form_page.3x \
	set_form_sub.3x set_form_term.3x set_form_userptr.3x set_form_win.3x \
	set_item_init.3x set_item_opts.3x set_item_term.3x set_item_userptr.3x \
	set_item_value.3x set_max_field.3x set_menu_back.3x set_menu_fore.3x \
	set_menu_format.3x set_menu_grey.3x set_menu_init.3x set_menu_items.3x \
	set_menu_mark.3x set_menu_opts.3x set_menu_pad.3x set_menu_pattern.3x \
	set_menu_spacing.3x set_menu_sub.3x set_menu_term.3x \
	set_menu_userptr.3x set_menu_win.3x set_new_page.3x \
	set_panel_userptr.3x set_term.3x set_top_row.3x setcchar.3x \
	setscrreg.3x setsyx.3x setterm.3x setupterm.3x show_panel.3x \
	slk_attr.3x slk_attr_off.3x slk_attr_on.3x slk_attr_set.3x \
	slk_attroff.3x slk_attron.3x slk_attrset.3x slk_clear.3x slk_color.3x \
	slk_init.3x slk_label.3x slk_noutrefresh.3x slk_refresh.3x \
	slk_restore.3x slk_set.3x slk_touch.3x standend.3x standout.3x \
	start_color.3x subpad.3x subwin.3x syncok.3x term_attrs.3x \
	termattrs.3x termname.3x tgetent.3x tgetflag.3x tgetnum.3x tgetstr.3x \
	tgoto.3x tigetflag.3x tigetnum.3x tigetstr.3x timeout.3x top_panel.3x \
	top_row.3x touchline.3x touchwin.3x tparm.3x tputs.3x trace.3x \
	typeahead.3x unctrl.3x unget_wch.3x ungetch.3x ungetmouse.3x \
	unpost_form.3x unpost_menu.3x untouchwin.3x update_panels.3x \
	use_default_colors.3x use_env.3x use_extended_names.3x vid_attr.3x \
	vid_puts.3x vidattr.3x vidputs.3x vline.3x vline_set.3x vw_printw.3x \
	vw_scanw.3x vwprintw.3x vwscanw.3x wadd_wch.3x wadd_wchnstr.3x \
	wadd_wchstr.3x waddch.3x waddchnstr.3x waddchstr.3x waddnstr.3x \
	waddnwstr.3x waddstr.3x waddwstr.3x wattr_get.3x wattr_off.3x \
	wattr_on.3x wattr_set.3x wattroff.3x wattron.3x wattrset.3x wbkgd.3x \
	wbkgdset.3x wbkgrnd.3x wbkgrndset.3x wborder.3x wborder_set.3x \
	wchgat.3x wclear.3x wclrtobot.3x wclrtoeol.3x wcolor_set.3x \
	wcursyncup.3x wdelch.3x wdeleteln.3x wecho_wchar.3x wechochar.3x \
	wenclose.3x werase.3x wget_wch.3x wget_wstr.3x wgetbkgrnd.3x wgetch.3x \
	wgetn_wstr.3x wgetnstr.3x wgetstr.3x whline.3x whline_set.3x \
	win_wch.3x win_wchnstr.3x win_wchstr.3x winch.3x winchnstr.3x \
	winchstr.3x winnstr.3x winnwstr.3x wins_nwstr.3x wins_wch.3x \
	wins_wstr.3x winsch.3x winsdelln.3x winsertln.3x winsnstr.3x \
	winsstr.3x winstr.3x winwstr.3x wmouse_trafo.3x wmove.3x \
	wnoutrefresh.3x wprintw.3x wredrawln.3x wrefresh.3x wresize.3x \
	wscanw.3x wscrl.3x wsetscrreg.3x wstandend.3x wstandout.3x \
	wsyncdown.3x wsyncup.3x wtimeout.3x wtouchln.3x wunctrl.3x wvline.3x \
	wvline_set.3x field_init.3x field_term.3x form_init.3x form_term.3x \
	item_init.3x item_term.3x key_defined.3x menu_init.3x \
	menu_term.3x pecho_wchar.3x
MAN5=	term.5 terminfo.5
MAN7=	term.7

PORTDOCS=	*

DOCS=	ANNOUNCE INSTALL NEWS README TO-DO doc/html/announce.html \
	doc/hackguide.doc doc/html/hackguide.html \
	doc/html/index.html doc/ncurses-intro.doc \
	doc/html/ncurses-intro.html
EXAMPLES=	Makefile README blue.c bs.6 bs.c cardfile.c cardfile.dat \
		ditto.c dots.c filter.c firework.c firstlast.c gdc.6 \
		gdc.c hanoi.c hashtest.c knight.c lrtest.c ncurses.c \
		newdemo.c railroad.c rain.c tclock.c test.priv.h \
		testaddch.c testcurs.c testscanw.c view.c worm.c \
		xmas.c
EXAMPLES_CPP=	Makefile NEWS PROBLEMS README-first cursesapp.cc \
		cursesapp.h cursesf.cc cursesf.h cursesm.cc cursesm.h \
		cursesmain.cc cursesp.cc cursesp.h cursesw.cc \
		cursesw.h cursslk.cc cursslk.h demo.cc etip.h \
		internal.h

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400000
MANUAL_PACKAGE_BUILD=	conflicts with system ncurses
.endif

post-install:
	${MKDIR} ${EXAMPLESDIR}/c++
	${INSTALL_DATA} ${WRKSRC}/misc/terminfo.src \
		${PREFIX}/share/misc/terminfo
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/test/${f} ${EXAMPLESDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/test/tracemunch ${EXAMPLESDIR}
.for f in ${EXAMPLES_CPP}
	${INSTALL_DATA} ${WRKSRC}/c++/${f} ${EXAMPLESDIR}/c++
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
