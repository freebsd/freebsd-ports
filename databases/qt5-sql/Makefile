# $FreeBSD$

PORTNAME=	sql
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	databases
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt SQL database integration module

USE_QT5=	core qmake_build buildtools_build
QT_DIST=	base
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-no-gui -no-xcb
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include <bsd.port.mk>
