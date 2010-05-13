# New ports collection makefile for:	apngasm
# Date created:		02 May 2010
# Whom:			Anonymous <swell.k@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	apngasm
PORTVERSION=	2.0
DISTVERSIONSUFFIX=-src
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	swell.k@gmail.com
COMMENT=	Create Animated PNG from a sequence of files

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_ZIP=	yes
USE_DOS2UNIX=	yes
NO_WRKSUBDIR=	yes

ALL_TARGET=	${PORTNAME}
MAKEFILE=	/dev/null
CFLAGS+=	-I${LOCALBASE}/include -lpng -lz -L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
