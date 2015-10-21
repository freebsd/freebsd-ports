# Created by: Christian Gusenbauer
# $FreeBSD$

PORTNAME=	inventor
PORTVERSION=	2.1.5.p10
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	ftp://oss.sgi.com/projects/inventor/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/-/}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	c47g@gmx.at
COMMENT=	SGI's Open Inventor (TM)

LICENSE=	LGPL21

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

CONFLICTS=	Coin-[0-9]* SoXt-[0-9]*

USE_XORG=	x11 xext xi xp xt
USE_GL=		glu glw
USES=		gmake iconv jpeg motif
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64
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

post-patch:
	@${REINPLACE_CMD} 's|/usr\(/include/freetype2\)|${LOCALBASE}\1|' \
		${WRKSRC}/libFL/ang/GNUmakefile
	@${REINPLACE_CMD} -e 's|%%ICONV_LIB%%|${ICONV_LIB}|' \
	    ${WRKSRC}/lib/GNUmakefile

.include <bsd.port.mk>
