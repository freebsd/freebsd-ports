# $FreeBSD$

PORTNAME=	gammaray
PORTVERSION=	2.11.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Debugging tool for Qt-application

USES=		cmake kde:5 pkgconfig qt:5

USE_QT=		3d concurrent core declarative designer gui help linguisttools \
		location network printsupport script scripttools svg uiplugin \
		webchannel webengine widgets xml buildtools_build qdoc_build \
		qmake_build
USE_KDE=	coreaddons syntaxhighlighting

USE_GITHUB=	yes
GH_ACCOUNT=	KDAB
GH_PROJECT=	GammaRay

PLIST_SUB+=	ARCH=${ARCH} \
		PORTMAJMIN=${PORTVERSION:C/(.*)\..*/\1/} \
		PORTVERSION=${PORTVERSION} \
		QTVER=${QT5_VERSION:C/\./_/:C/\..*//}

.include <bsd.port.mk>
