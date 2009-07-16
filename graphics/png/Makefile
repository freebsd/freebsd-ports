# New ports collection makefile for:    PNG images library
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.2.37
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lib${PORTNAME}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}
#PATCH_SITES=	${MASTER_SITES}
#PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
#PATCHFILES=
#PATCH_DIST_STRIP= -p1

MAINTAINER=	ache@FreeBSD.org
COMMENT=	Library for manipulating PNG images

MAKEFILE=	${WRKSRC}/scripts/makefile.freebsd
ALL_TARGET=	all libpng-config test
MAKE_FLAGS=	ccopts="${CFLAGS}" ldopts="${LDFLAGS}" -f
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes
SHLIB_VER=	5
USE_BZIP2=	yes

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
	@${MKDIR} ${PREFIX}/include/libpng
	@${MKDIR} ${PREFIX}/libdata/pkgconfig

post-install:
	${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/scripts/libpng.pc.in \
		> ${WRKSRC}/scripts/libpng.pc
	${INSTALL_DATA} ${WRKSRC}/scripts/libpng.pc \
		${PREFIX}/libdata/pkgconfig/libpng12.pc
	${LN} -sf libpng12.pc ${PREFIX}/libdata/pkgconfig/libpng.pc

.include <bsd.port.post.mk>
