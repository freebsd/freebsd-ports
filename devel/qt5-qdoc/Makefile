# $FreeBSD$

PORTNAME=	qdoc
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel textproc
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt documentation generator

USE_QT5=	core qml buildtools_build qdoc-data_run
QT_DIST=	tools
USES=		qmake

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST_FILES=	${QT_BINDIR}/qdoc

.include <bsd.port.mk>
