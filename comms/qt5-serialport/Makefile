# $FreeBSD$

PORTNAME=	serialport
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	comms
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt functions to access serial ports

USE_QT=		core buildtools_build
USES=		compiler:c++11-lang libtool qmake qt-dist:5,serialport
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
