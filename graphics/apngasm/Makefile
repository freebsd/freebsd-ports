# New ports collection makefile for:	apngasm
# Date created:		02 May 2010
# Whom:			Anonymous <swell.k@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	apngasm
PORTVERSION=	2.3
DISTVERSIONSUFFIX=-src
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	swell.k@gmail.com
COMMENT=	Create Animated PNG from a sequence of files

USE_ZIP=	yes
USE_DOS2UNIX=	yes
NO_WRKSUBDIR=	yes

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

ALL_TARGET=	${PORTNAME}
MAKEFILE=	/dev/null
MAKE_ENV+=	LDFLAGS="${LDFLAGS}" LDLIBS="${LDLIBS}"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LDLIBS+=	-lpng -lm -lz

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if !defined(NO_SHARED)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpng.a:${PORTSDIR}/graphics/png
LDFLAGS+=	-static
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
