# New ports collection makefile for:	gd
# Date created:         27 Mar 1998
# Whom:                 jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	2.0.1
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
LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

LATEST_LINK=	gd2

USE_FREETYPE2=	yes
.ifndef WITHOUT_XPM
# Temporary hack, until X-less XPM building is added to USE_XPM:
.ifndef WITHOUT_X11
USE_XPM=	yes
.else
LIB_DEPENDS+=	xpm:${PORTSDIR}/graphics/xpm
.endif
.else
MAKE_ARGS+=	-DWITHOUT_XPM
.endif

INSTALLS_SHLIB=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	-j2
.for v in WRKSRC INSTALL_PROGRAM INSTALL_DATA INSTALL_SCRIPT
MAKE_ARGS+=	$v="${$v}"
.endfor

post-extract:
	bzip2 -d < ${_DISTDIR}/gd_gif_in.c.bz2 > ${WRKSRC}/gd_gif_in.c

.ifdef GD_FONTS
SCRIPTS_ENV+=	GD_FONTS="${GD_FONTS}"
.endif

.include <bsd.port.mk>
