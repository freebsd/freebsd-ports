# New ports collection makefile for:	ncurses
# Version required:			4.2
# Date created:				23 September 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.8 1998/10/06 07:35:03 asami Exp $
#

DISTNAME=		ncurses-4.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU} \
			ftp://ftp.clark.net/pub/dickey/ncurses/

MAINTAINER=		andy@icc.surw.chel.su

MAN1=	captoinfo.1m clear.1 infocmp.1m tic.1m toe.1m tput.1 tset.1
MAN3=	curs_addch.3x curs_addchstr.3x curs_addstr.3x curs_attr.3x \
	curs_beep.3x curs_bkgd.3x curs_border.3x curs_clear.3x \
	curs_color.3x curs_delch.3x curs_deleteln.3x curs_getch.3x \
	curs_getstr.3x curs_getyx.3x curs_inch.3x curs_inchstr.3x \
	curs_initscr.3x curs_inopts.3x curs_insch.3x curs_insstr.3x \
	curs_instr.3x curs_kernel.3x curs_mouse.3x curs_move.3x \
	curs_outopts.3x curs_overlay.3x curs_pad.3x curs_print.3x \
	curs_printw.3x curs_refresh.3x curs_scanw.3x curs_scr_dmp.3x \
	curs_scroll.3x curs_slk.3x curs_termattrs.3x curs_termcap.3x \
	curs_terminfo.3x curs_touch.3x curs_util.3x curs_window.3x \
	define_key.3x dft_fgbg.3x form.3x form_cursor.3x form_data.3x \
	form_driver.3x form_field.3x form_field_attributes.3x \
	form_field_buffer.3x form_field_info.3x form_field_just.3x \
	form_field_new.3x form_field_opts.3x form_field_userptr.3x \
	form_field_validation.3x form_fieldtype.3x form_hook.3x \
	form_new.3x form_new_page.3x form_opts.3x form_page.3x \
	form_post.3x form_requestname.3x form_userptr.3x form_win.3x \
	keyok.3x menu.3x menu_attribs.3x menu_cursor.3x menu_driver.3x \
	menu_format.3x menu_hook.3x menu_items.3x menu_mark.3x \
	menu_new.3x menu_opts.3x menu_pattern.3x menu_post.3x \
	menu_requestname.3x menu_spacing.3x menu_userptr.3x \
	menu_win.3x mitem_current.3x mitem_name.3x mitem_new.3x \
	mitem_opts.3x mitem_userptr.3x mitem_value.3x mitem_visible.3x \
	ncurses.3x panel.3x resizeterm.3x wresize.3x
MAN5=	terminfo.5 term.5
MAN7=	term.7
MANCOMPRESSED=	yes

MANUAL_PACKAGE_BUILD=	conflicts with system ncurses
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/misc --disable-overwrite \
		--disable-termcap --includedir=${PREFIX}/include/ncurses \
		--prefix=${PREFIX} --with-profile --with-shared
CONFIGURE_ENV=		gnat_exists="no" ac_cv_path_LDCONFIG="/usr/bin/env OBJFORMAT=${PORTOBJFORMAT} /sbin/ldconfig -m ${PREFIX}/lib"

.include <bsd.port.pre.mk>

post-install:
.if ${PORTOBJFORMAT} == "aout"
	@ ${LN} -sf ${PREFIX}/lib/libform.so.4.2 ${PREFIX}/lib/libform.so
	@ ${LN} -sf ${PREFIX}/lib/libmenu.so.4.2 ${PREFIX}/lib/libmenu.so
	@ ${LN} -sf ${PREFIX}/lib/libncurses.so.4.2 ${PREFIX}/lib/libncurses.so
	@ ${LN} -sf ${PREFIX}/lib/libpanel.so.4.2 ${PREFIX}/lib/libpanel.so
.endif
	@ ${MKDIR} ${PREFIX}/share/doc/ncurses
.for file in ANNOUNCE INSTALL NEWS README TO-DO announce.html misc/hackguide.doc misc/hackguide.html misc/ncurses-intro.doc misc/ncurses-intro.html
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/ncurses
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/misc/terminfo.src ${PREFIX}/share/misc/terminfo
	@ ${MKDIR} ${PREFIX}/share/examples/ncurses
.for file in README blue.c bs.6 bs.c firework.c gdc.6 gdc.c hanoi.c hashtest.c knight.c lrtest.c ncurses.c newdemo.c rain.c tclock.c test.priv.h testcurs.c view.c worm.c xmas.c
	@ ${INSTALL_DATA} ${WRKSRC}/test/${file} ${PREFIX}/share/examples/ncurses
.endfor
	@ ${INSTALL_SCRIPT} ${WRKSRC}/test/tracemunch ${PREFIX}/share/examples/ncurses
	@ ${INSTALL_DATA} ${FILESDIR}/Makefile ${PREFIX}/share/examples/ncurses
	@ ${MKDIR} ${PREFIX}/share/examples/ncurses/c++
.for file in NEWS PROBLEMS README-first cursesp.cc cursesp.h cursesw.cc cursesw.h demo.cc
	@ ${INSTALL_DATA} ${WRKSRC}/c++/${file} ${PREFIX}/share/examples/ncurses/c++
.endfor
	@ ${INSTALL_DATA} ${FILESDIR}/Makefile.c++ ${PREFIX}/share/examples/ncurses/c++/Makefile

.include <bsd.port.post.mk>
