# Ports collection makefile for:	ofc
# Date created:				06/21/2006
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	ofc
PORTVERSION=	0.8.1
PORTREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	http://ofc.dvoudheusden.net/download/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	The Objective-C Foundation Classes library

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2

USE_SDL=	sdl
USE_AUTOTOOLS=	libtool
USES=	pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15 ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

OPTIONS=	GDBM "Add gdbm support" off \
		GMP "Add gmp support" off

.if defined (WITH_GDBM)
LIB_DEPENDS+=	gdbm.4:${PORTSDIR}/databases/gdbm
.endif

.if defined (WITH_GMP)
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
# needs libobjc
GCCSUFFIX=42
CC=		gcc${GCCSUFFIX}
CXX=		g++${GCCSUFFIX}
OFC_GCC_PORT?=	lang/gcc${GCCSUFFIX}
TARGLIB!=	(cd ${PORTSDIR}/${OFC_GCC_PORT} && make -V TARGLIB)
LDFLAGS+=	-L${TARGLIB}
BUILD_DEPENDS+=	${TARGLIB}/libobjc.so:${PORTSDIR}/${OFC_GCC_PORT}
RUN_DEPENDS+=	${TARGLIB}/libobjc.so:${PORTSDIR}/${OFC_GCC_PORT}
.endif

.include <bsd.port.post.mk>
