# New ports collection makefile for:	xpuyopuyo
# Date created:		19 Sep 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xpuyopuyo
PORTVERSION=	0.4.1
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xpuyopuyo/ \
		http://lenin.dabney.caltech.edu/~justins/xpuyopuyo/

MAINTAINER=	yinjieh@csie.nctu.edu.tw

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
.if defined(WITH_GNOME)
LIB_DEPENDS+=	gnome.4:${PORTSDIR}/x11/gnomelibs
.endif
.if defined(WITH_MUSIC)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
.endif

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_AUTOCONF=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"
.if defined(WITH_GNOME)
CONFIGURE_ARGS+=--with-gnome=${X11BASE}
.else
CONFIGURE_ARGS+=--without-gnome
.endif
.if defined(WITH_ROTATE_FIXED)
CONFIGURE_ARGS+=--enable-rotate-fixed
.endif
.if defined(WITH_AIBREED)
CONFIGURE_ARGS+=--enable-aibreed
.endif
.if defined(WITH_MUSIC)
CONFIGURE_ARGS+=--with-libmikmod-prefix=${LOCALBASE}
.endif

MAN6=		xpuyopuyo.6

.if defined(WITH_GNOME)
PLIST=		${WRKDIR}/PLIST

pre-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST}
	@${ECHO} share/gnome/apps/Games/xpuyopuyo.desktop >> ${PLIST}
	@${ECHO} share/gnome/pixmaps/xpuyopuyo.xpm >> ${PLIST}
.endif

.include <bsd.port.mk>
