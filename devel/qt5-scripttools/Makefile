# $FreeBSD$

PORTNAME=	scripttools
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Script additional components

USE_QT5=	core gui script widgets buildtools_build
QT_DIST=	script
USES=		qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

WRKSRC_SUBDIR=	src/${PORTNAME}

.include <bsd.port.mk>
