# New ports collection makefile for:	gd1
# Date created:				27 Mar 1998
# Whom:					jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	1.8.4
PORTEPOCH=	2
CATEGORIES+=	graphics
MASTER_SITES=	http://www.boutell.com/gd/http/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	graphics/gd

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	A graphics library for fast creation of images

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2
.if defined(WITH_XPM)
.if defined(WITHOUT_X11)
LIB_DEPENDS+=   Xpm:${PORTSDIR}/graphics/xpm
CPPFLAGS+=	-I${X11BASE}/include/X11 -I${X11BASE}/include -DHAVE_LIBXPM
LDFLAGS+=	-L${X11BASE}/lib -lXpm
.else
USE_XPM=	yes
CPPFLAGS+=	-I${X11BASE}/include/X11 -I${X11BASE}/include -DHAVE_LIBXPM
LDFLAGS+=	-L${X11BASE}/lib -lXpm -lX11
.endif
.endif

MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

LATEST_LINK=	gd1

MAKEFILE=	${FILESDIR}/Makefile.lib
INSTALLS_SHLIB=	yes

pre-everything::
.if !defined(WITH_XPM)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Xpm support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_XPM=yes\""
	@${ECHO_MSG}
.endif

post-extract:
	@${CP} ${FILESDIR}/gd_gif_in.c ${WRKSRC}

.include <bsd.port.mk>
