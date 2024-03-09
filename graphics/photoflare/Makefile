PORTNAME=	photoflare
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.12
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quick, simple but powerful cross-platform image editor
WWW=		https://photoflare.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libGraphicsMagick++.so:graphics/GraphicsMagick

USES=		desktop-file-utils gl qmake qt:5 localbase pkgconfig
USE_GITHUB=	yes
USE_QT=		core gui network printsupport widgets buildtools:build linguisttools:build
USE_GL=		gl

CXXFLAGS+=	`pkg-config --cflags GraphicsMagick++`
LDFLAGS+=	`pkg-config --libs GraphicsMagick++` ${LDFLAGS_${CHOSEN_COMPILER_TYPE}}
LDFLAGS_clang=	-lomp
LDFLAGS_gcc=	-fopenmp

.if !exists(/usr/include/omp.h)
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++17-lang
.endif

post-install: # delete ecp.* files with random extensions
	@${FIND} ${STAGEDIR}${PREFIX} -name "ecp.*" -delete

.include <bsd.port.mk>
