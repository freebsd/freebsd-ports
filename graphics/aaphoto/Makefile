# Created by: Andras Horvath <han@log69.com>
# $FreeBSD$

PORTNAME=	aaphoto
PORTVERSION=	0.43.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	mail@log69.com
COMMENT=	Auto Adjust Photo, automatic color correction of photos

LICENSE=	GPLv3

LIB_DEPENDS=	libjasper.so:${PORTSDIR}/graphics/jasper \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	log69
GH_COMMIT=	e566f9b
GH_TAGNAME=	v${PORTVERSION}

USE_GCC=	any
GNU_CONFIGURE=	yes
USES=		compiler

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/aaphoto

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64" || ${ARCH} == "i386") && ${OSVERSION} >= 700000 && \
	${COMPILER_TYPE} == gcc
CFLAGS+=	-fopenmp -D__OPENMP__
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aaphoto ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
