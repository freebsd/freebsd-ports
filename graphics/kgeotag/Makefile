# $FreeBSD$

PORTNAME=	kgeotag
DISTVERSION=	1.0.0
CATEGORIES=	graphics
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Photo geotagging manually or from GPX files

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

USES=		cmake compiler:c++17-lang kde:5 pkgconfig qt:5 tar:xz
USE_QT=		core gui widgets \
		buildtools_build linguist_build qmake_build
USE_KDE=	coreaddons config configwidgets crash i18n libkexiv2 \
		marble xmlgui \
		ecm_build

.include <bsd.port.mk>
