# New ports collection makefile for:    PNG images library
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.4.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/lib${PORTNAME}14/${PORTVERSION}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Library for manipulating PNG images

MAKE_JOBS_SAFE=	yes

USE_XZ=		yes
USE_LDCONFIG=	yes

MAKEFILE=	${WRKSRC}/scripts/makefile.freebsd
ALL_TARGET=	all libpng-config test
MAKE_FLAGS=	ccopts="${CFLAGS}" ldopts="${LDFLAGS}" -f
SHLIB_VER=	6
MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

MAN3=		libpng.3 libpngpf.3
MAN5=		png.5
MANCOMPRESSED=	maybe

OPTIONS=	APNG "Animated PNG support" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_APNG) || make(makesum) || defined(FETCH_ALL)
MASTER_SITES+=	SF/lib${PORTNAME}-apng/libpng-master/${PORTVERSION}:apng
DISTFILES+=	${DISTNAME}-apng.patch.gz:apng
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif
.if !defined(WITHOUT_APNG)
EXTRA_PATCHES=	${WRKSRC}/${DISTNAME}-apng.patch
.endif

post-extract:
.if !defined(WITHOUT_APNG)
	@${LN} -sf ${WRKSRC} ${WRKSRC}/
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}-apng.patch.gz ${WRKSRC}/
	${GZIP_CMD} -d ${WRKSRC}/${DISTNAME}-apng.patch.gz
.endif

pre-su-install:
	@${MKDIR} ${PREFIX}/include/libpng
	@${MKDIR} ${PREFIX}/libdata/pkgconfig

post-install:
	${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/scripts/libpng.pc.in \
		> ${WRKSRC}/scripts/libpng.pc
	${INSTALL_DATA} ${WRKSRC}/scripts/libpng.pc \
		${PREFIX}/libdata/pkgconfig/libpng14.pc
	${LN} -sf libpng14.pc ${PREFIX}/libdata/pkgconfig/libpng.pc

.include <bsd.port.post.mk>
