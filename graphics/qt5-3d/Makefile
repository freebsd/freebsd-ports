# $FreeBSD$

PORTNAME=  	3d
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt3D module

# Base GCC fails to build the code, pull in a more recent compiler.
USES=		compiler:c++0x qmake
USE_QT5=	concurrent core gui qml quick buildtools_build
QT_DIST=	${PORTNAME}

USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
