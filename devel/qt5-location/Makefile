# $FreeBSD$

PORTNAME=	location
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt location module

USE_QT=		concurrent core dbus gui network qml quick buildtools_build
USES=		qmake:norecursive qt-dist:5,location

USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
