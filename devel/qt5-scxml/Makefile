# $FreeBSD$

PORTNAME=	scxml
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 SXCML module

USE_QT=		core declarative network buildtools_build
USES=		compiler:c++11-lang qmake qt-dist:5,scxml
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
