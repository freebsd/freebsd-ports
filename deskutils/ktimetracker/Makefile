PORTNAME=	ktimetracker
DISTVERSION=	6.0.0
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/unstable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Todo management and time tracker
WWW=		https://userbase.kde.org/KTimeTracker

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

USES=		cmake compiler:c++17-lang gettext-tools gl kde:6 qt:6 \
		tar:xz xorg
USE_GL=		opengl
USE_KDE=	calendarcore colorscheme config configwidgets coreaddons \
		crash dbusaddons guiaddons i18n iconthemes idletime jobwidgets \
		kcmutils kio notifications sonnet statusnotifieritem \
		textwidgets widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		5compat base declarative
USE_XORG=	x11

.include <bsd.port.mk>
