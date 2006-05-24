# New ports collection makefile for:	aalib
# Date created:				9 Dec 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	aalib
PORTVERSION=	1.4.r5
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aa-project
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	shaun@inerd.com
COMMENT=	An ascii art library

WRKSRC=		${WRKDIR}/${PORTNAME}-1.4.0
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
INFO=		aalib

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
CONFIGURE_ARGS=	--x-includes="${X11BASE}/include" \
		--x-libraries="${X11BASE}/lib"
.else
CONFIGURE_ARGS=	--with-x=no
.endif

MAN1=		aafire.1
MAN3=		aa_attrs.3 aa_autoinit.3 aa_close.3 aa_createedit.3 \
		aa_currentfont.3 aa_defparams.3 aa_autoinitkbd.3 \
		aa_autoinitmouse.3 aa_defrenderparams.3 aa_dithernames.3 \
		aa_drivers.3 mem_d.3 aa_edit.3 aa_fonts.3 aa_getkey.3 \
		aa_gotoxy.3 aa_help.3 aa_hidecursor.3 aa_image.3 \
		aa_displayrecommended.3 aa_editkey.3 aa_fastrender.3 \
		aa_init.3 aa_printf.3 aa_formats.3 aa_getevent.3 \
		aa_getmouse.3 aa_hidemouse.3 aa_imgheight.3 aa_imgwidth.3 \
		aa_initkbd.3 aa_initmouse.3 aa_kbddrivers.3 \
		aa_kbdrecommended.3 aa_mmheight.3 aa_mmwidth.3 \
		aa_mousedrivers.3 aa_mouserecommended.3 aa_parseoptions.3 \
		aa_putpixel.3 aa_puts.3 aa_recommendhi.3 \
		aa_recommendhidisplay.3 aa_recommendhikbd.3 \
		aa_recommendhimouse.3 aa_recommendlow.3 \
		aa_recommendlowdisplay.3 aa_recommendlowkbd.3 \
		aa_recommendlowmouse.3 aa_registerfont.3 aa_render.3 \
		aa_resize.3 aa_resizehandler.3 aa_scrheight.3 aa_scrwidth.3 \
		aa_setfont.3 aa_setsupported.3 aa_showcursor.3 aa_showmouse.3 \
		aa_text.3 aa_uninitkbd.3 aa_uninitmouse.3 save_d.3

post-extract:
	@${RM} -f ${WRKSRC}/doc/aalib.info*

post-patch:
	@${RM} -f ${WRKSRC}/config.cache
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g; \
		s|MAKEINFO=makeinfo|MAKEINFO="makeinfo --no-split"|g ; \
		s|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC} \( -name '*.[ch]' \! -name acconfig.h \) \
		| ${XARGS} ${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g'

.include <bsd.port.mk>
