# $FreeBSD$

PORTNAME=	sensors
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	comms
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt sensors module

USE_QT=		core qml quick buildtools_build
USES=		qmake:norecursive qt-dist:5,sensors

USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
