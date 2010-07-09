# New ports collection makefile for:    PNG images library
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.4.3
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/01-lib${PORTNAME}-master/${PORTVERSION}
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

OPTIONS=	APNG "Animated PNG support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_APNG) || make(makesum) || defined(FETCH_ALL)
MASTER_SITES+=	SF/vdubapngmod/lib${PORTNAME}-apng-patch/${PORTVERSION}:apng \
		http://littlesvr.ca/apng/diff/:apng
DISTFILES+=	${DISTNAME}-apng.patch:apng
EXTRACT_ONLY=   ${DISTNAME}${EXTRACT_SUFX}
.endif
.if defined(WITH_APNG)
USE_DOS2UNIX=	${DISTNAME}-apng.patch
EXTRA_PATCHES=	${WRKSRC}/${DISTNAME}-apng.patch
.endif

post-extract:
# Please don't delete the following line - this link used by ghostscript* ports
	@${LN} -sf ${WRKSRC} ${WRKDIR}/libpng
.if defined(WITH_APNG)
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}-apng.patch ${WRKSRC}
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
