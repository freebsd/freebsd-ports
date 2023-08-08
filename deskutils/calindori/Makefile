PORTNAME=	calindori
DISTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Calendar application for desktop and phone
WWW=		https://apps.kde.org/en/calindori

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

USES=		cmake compiler:c++17-lang desktop-file-utils gl kde:5 pkgconfig qt:5 tar:xz
USE_GL=		gl
USE_QT=		core dbus declarative gui \
		network quickcontrols quickcontrols2 \
		svg widgets \
		buildtools:build linguist:build qmake:build
USE_KDE=	calendarcore config coreaddons dbusaddons i18n kirigami2 \
		notifications people service \
		ecm:build

CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
