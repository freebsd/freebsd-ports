# Created by: vanilla
# $FreeBSD$

PORTNAME=	ofc
PORTVERSION=	0.8.1
PORTREVISION=	7
CATEGORIES=	lang
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	The Objective-C Foundation Classes library

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2 \
		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		freetype:${PORTSDIR}/print/freetype2

PROJECTHOST=	${PORTNAME}
USE_SDL=	sdl
USE_AUTOTOOLS=	libtool
USES=		pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15 ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS_DEFINE=	GDBM GMP

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGDBM}
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm
.endif

.if ${PORT_OPTIONS:MGMP}
LIB_DEPENDS+=	gmp:${PORTSDIR}/math/gmp
.endif

.if ${OSVERSION} >= 900000
# needs libobjc
GCCSUFFIX=	46
CC=		gcc${GCCSUFFIX}
CXX=		g++${GCCSUFFIX}
OFC_GCC_PORT?=	lang/gcc${GCCSUFFIX}
TARGLIB!=	${MAKE} -C ${PORTSDIR}/${OFC_GCC_PORT} -V TARGLIB
LDFLAGS+=	-L${TARGLIB}
BUILD_DEPENDS+=	${TARGLIB}/libobjc.so:${PORTSDIR}/${OFC_GCC_PORT}
RUN_DEPENDS+=	${TARGLIB}/libobjc.so:${PORTSDIR}/${OFC_GCC_PORT}
.endif

.include <bsd.port.mk>
