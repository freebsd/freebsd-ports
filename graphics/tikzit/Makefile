# $FreeBSD$

PORTNAME=	tikzit
DISTVERSION=	2.1.6
CATEGORIES=	graphics

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	PGF/TikZ diagram editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

USES=		bison compiler:c++11-lang qmake qt:5

USE_GITHUB=	yes
GH_TAGNAME=	v${DISTVERSION}

USE_QT=	buildtools core gui widgets network

.include <bsd.port.mk>
