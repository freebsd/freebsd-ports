# New ports collection makefile for:	gd
# Date created:         27 Mar 1998
# Whom:                 jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	1.8.4
PORTREVISION=	3
CATEGORIES+=	graphics
MASTER_SITES=	http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/ \
		http://virtual-estates.net/~mi/port-stuff/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	graphics/gd
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} gd_gif_in.c.bz2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	ports@FreeBSD.org

.if !exists(/usr/bin/bzip2)
BUILD_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype:${PORTSDIR}/print/freetype2

USE_FREETYPE2=	yes

.if defined(WITH_X11)
USE_XLIB=	yes
USE_XPM=	yes
.endif

INSTALLS_SHLIB=	yes

post-extract:
	bzip2 -d < ${_DISTDIR}/gd_gif_in.c.bz2 > ${WRKSRC}/gd_gif_in.c

pre-everything:
.if !defined(WITH_X11)
	@${ECHO_MSG} "If you want to compile in X support use "
	@${ECHO_MSG} "'make -DWITH_X11' instead"
.endif

.include <bsd.port.mk>
