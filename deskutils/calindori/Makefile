PORTNAME=	calindori
DISTVERSION=	25.12.0
CATEGORIES=	deskutils
MASTER_SITES=	KDE/stable/release-service/${DISTVERSION}/src/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Calendar application for desktop and phone
WWW=		https://apps.kde.org/en/calindori

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

USES=		cmake compiler:c++17-lang desktop-file-utils gettext kde:6 pkgconfig qt:6 tar:xz
USE_QT=		base declarative svg tools:build
USE_KDE=	calendarcore config coreaddons dbusaddons i18n kirigami2 \
		notifications people \
		ecm:build

CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
