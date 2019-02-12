# $FreeBSD$

PORTNAME=	scxml
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 SXCML module

USES=		compiler:c++11-lang qmake qt-dist:5,scxml
USE_QT=		core declarative network buildtools_build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
