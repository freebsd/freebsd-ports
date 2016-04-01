# Created by: Andras Horvath <han@log69.com>
# $FreeBSD$

PORTNAME=	aaphoto
PORTVERSION=	0.43.1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	mail@log69.com
COMMENT=	Auto Adjust Photo, automatic color correction of photos

LICENSE=	GPLv3

LIB_DEPENDS=	libjasper.so:graphics/jasper \
		libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	log69

GNU_CONFIGURE=	yes
USES=		compiler:openmp jpeg

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/aaphoto

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64" || ${ARCH} == "i386") && ${COMPILER_TYPE} == gcc
CFLAGS+=	-fopenmp -D__OPENMP__
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aaphoto ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
