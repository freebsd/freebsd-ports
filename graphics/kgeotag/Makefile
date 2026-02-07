PORTNAME=	kgeotag
DISTVERSION=	1.8.0
CATEGORIES=	graphics
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Photo geotagging manually or from GPX files
WWW=		https://invent.kde.org/graphics/kgeotag/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/LicenseRef-KDE-Accepted-GPL.txt

USES=		cmake compiler:c++17-lang gettext-tools gl kde:6 \
		pkgconfig qt:6 tar:xz
USE_GL=		gl opengl # GLX
USE_KDE=	colorscheme config configwidgets coreaddons crash i18n \
		libkexiv2 marble widgetsaddons xmlgui \
		ecm:build
USE_QT=		5compat base declarative positioning webchannel

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386
USE_QT+=	webengine
.endif

.include <bsd.port.mk>
