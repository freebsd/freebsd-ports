# $FreeBSD$

PORTNAME=	photoflare
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quick, simple but powerful cross-platform image editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libGraphicsMagick++.so:graphics/GraphicsMagick \
		libomp.so:devel/openmp

USES=		compiler:c++17-lang desktop-file-utils gl qmake qt:5 localbase pkgconfig
USE_GITHUB=	yes
USE_QT=		core gui network printsupport widgets buildtools_build linguisttools_build
USE_GL=		gl

CXXFLAGS+=	`pkg-config --cflags GraphicsMagick++`
LDFLAGS+=	`pkg-config --libs GraphicsMagick++` ${LOCALBASE}/lib/libomp.so

.include <bsd.port.mk>
