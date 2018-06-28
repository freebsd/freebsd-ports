# $FreeBSD$

PORTNAME=	connectivity
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	comms
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt connectivity (Bluetooth/NFC) module

USE_QT=		concurrent core qml quick buildtools_build
USES=		qmake qt-dist:5,connectivity

USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
