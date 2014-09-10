# $FreeBSD$

PORTNAME=	uitools
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Designer UI forms support module

USE_QT5=	core widgets buildtools_build
QT_DIST=	tools
USES=		qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

WRKSRC_SUBDIR=	src/designer/src/${PORTNAME}

.include <bsd.port.mk>
