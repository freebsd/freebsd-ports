# New ports collection makefile for:    PNG images library
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.2.5
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://www.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lib${PORTNAME}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

#PATCH_SITES=	ftp://ftp.libpng.org/pub/png/src/
#PATCHFILES=

MAINTAINER=	ache@FreeBSD.org
COMMENT=	Library for manipulating PNG images

MAKEFILE=       ${WRKSRC}/scripts/makefile.freebsd
ALL_TARGET=	all test
INSTALLS_SHLIB=	yes
SHLIB_VER=	5

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

MAN3=		libpng.3 libpngpf.3
MAN5=		png.5
MANCOMPRESSED=	maybe

.include <bsd.port.pre.mk>

post-extract:
# Please don't delete the following line - this link used by ghostscript* ports
	@${LN} -sf ${WRKSRC} ${WRKDIR}/libpng

pre-su-install:
	@[ -d ${PREFIX}/include/libpng ] || ${MKDIR} ${PREFIX}/include/libpng
	@[ -d ${PREFIX}/libdata/pkgconfig ] || \
		${MKDIR} ${PREFIX}/libdata/pkgconfig

post-install:
	${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/scripts/libpng.pc.in \
		> ${WRKSRC}/scripts/libpng.pc
	${INSTALL_DATA} ${WRKSRC}/scripts/libpng.pc \
		${PREFIX}/libdata/pkgconfig/libpng12.pc

.include <bsd.port.post.mk>
