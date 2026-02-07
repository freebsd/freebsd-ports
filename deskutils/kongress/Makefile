PORTNAME=	kongress
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Conference companion application
WWW=		https://apps.kde.org/kongress

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

USES=		cmake compiler:c++20-lang gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl
USE_QT=		base declarative svg
USE_KDE=	calendarcore config coreaddons crash dbusaddons i18n \
		kirigami-addons kirigami2 kosm notifications \
		ecm:build

.include <bsd.port.mk>
