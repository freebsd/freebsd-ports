PORTNAME=	kgeotag
DISTVERSION=	1.2.0
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
# From stage-qa; these are not checked explicitly, but link
# transitively though other KDE components (mostly Marble).
USE_QT+=	dbus declarative location network printsupport webchannel xml
USE_KDE+=	auth codecs widgetsaddons

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386
USE_QT+=	webengine
.endif

.include <bsd.port.mk>
