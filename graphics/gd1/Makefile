# New ports collection makefile for:	gd
# Date created:         27 Mar 1998
# Whom:                 jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	1.8.4
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES+=	graphics
MASTER_SITES=	http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	graphics/gd

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	A graphics library for fast creation of images

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

MAKEFILE=	${FILESDIR}/Makefile.lib
INSTALLS_SHLIB=	yes

.if defined(WITH_X11)
USE_XPM=	yes
.endif

pre-everything::
.if !defined(WITH_X11)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Xpm support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_X11=yes\""
	@${ECHO_MSG}
.endif

post-extract:
	@${CP} ${FILESDIR}/gd_gif_in.c ${WRKSRC}

.include <bsd.port.mk>
