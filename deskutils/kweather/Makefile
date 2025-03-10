PORTNAME=	kweather
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Weather application for Plasma Mobile
WWW=		https://apps.kde.org/kweather

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

LIB_DEPENDS=	libKWeatherCore.so:deskutils/kweathercore

USES=		cmake gettext kde:6 qt:6 tar:xz
USE_KDE=	config coreaddons crash i18n kirigami-addons libplasma \
		notifications \
		ecm:build
USE_QT=		base charts declarative
USE_GL=		gl opengl

.include <bsd.port.mk>
