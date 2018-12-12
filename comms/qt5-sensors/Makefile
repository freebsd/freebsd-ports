# $FreeBSD$

PORTNAME=	sensors
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	comms
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt sensors module

USE_QT=		core declarative buildtools_build
USES=		compiler:c++11-lang qmake:norecursive qt-dist:5,sensors

USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
