# New ports collection makefile for:    PNG images library
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.2.5
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lib${PORTNAME}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}
PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCHFILES=	libpng-patch00-pngrtran-filler-RRGGBB-overflow.txt \
		libpng-patch01-pngrtran-filler-GG-overflow.txt \
		libpng-patch02-pngerror-memcpy-overflow.txt \
		libpng-patch03-trns-chunk-overflow.txt \
		libpng-patch04-get-uint-31.txt \
		libpng-patch05-pngpread-chunklength.txt \
		libpng-patch06-pngread-chunklength.txt \
		libpng-patch07-png-read-png-overflow.txt \
		libpng-patch08-splt-buffer-overflow.txt \
		libpng-patch09-null-iccp-profile.txt \
		libpng-patch10-find-duplicate-chunk.txt \
		libpng-patch11-limit-dimensions.txt
PATCH_DIST_STRIP= -p1

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
