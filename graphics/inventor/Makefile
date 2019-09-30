# Created by: Christian Gusenbauer
# $FreeBSD$

PORTNAME=	inventor
PORTVERSION=	2.1.5.p10
PORTREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	ftp://oss.sgi.com/projects/inventor/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/-/}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SGI's Open Inventor (TM)

LICENSE=	LGPL21

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained, Depends on expiring graphics/libGLw
EXPIRATION_DATE=	2019-10-16

ONLY_FOR_ARCHS=	amd64 i386
CONFLICTS=	Coin-[0-9]* SoXt-[0-9]*

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		gl gmake iconv jpeg motif
USE_XORG=	x11 xext xi xp xt
USE_GL=		gl glu glw
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS=	CC="${CC}" CXX="${CXX}" LD="${CXX}" \
		VCOPTS="${CFLAGS}" VCXXOPTS="${CXXFLAGS}" \
		VLDOPTS="${LDFLAGS}" VLDDSOOPTS="${LDFLAGS}" \
		IVPREFIX="${PREFIX}" X11DIR="${LOCALBASE}"
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/lib:${WRKSRC}/libSoXt \
		FREETYPE=1 \
		INSTALL_STRIP=${STRIP} \
		IVROOT=${STAGEDIR}
MAKEFILE=	GNUmakefile

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DEBUG

DEBUG_MAKE_ENV=	LIBTYPE=debug

LDFLAGS+=	-Wl,--add-needed
LLD_UNSAFE=	yes
CFLAGS+=	-Wno-c++11-narrowing # cause of "lib/interaction/src/draggers/geom/SoCenterballDraggerGeom.h"

post-patch:
# Fix for print/freetype2 v2.7, where FT_Done_GlyphSlot function is not exported
	@${REINPLACE_CMD} -e '/FT_Done_GlyphSlot/s|^|//|' \
		${WRKSRC}/libFL/ang/flfreetype.c
	@${REINPLACE_CMD} 's|/usr\(/include/freetype2\)|${LOCALBASE}\1|' \
		${WRKSRC}/libFL/ang/GNUmakefile
	@${REINPLACE_CMD} -e 's|%%ICONV_LIB%%|${ICONV_LIB}|' \
	    ${WRKSRC}/lib/GNUmakefile
.include <bsd.port.mk>
