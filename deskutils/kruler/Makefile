PORTNAME=	kruler
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE screen ruler
WWW=		https://www.kde.org/applications/graphics/kruler

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	auth codecs config configwidgets coreaddons doctools i18n \
		notifications statusnotifieritem widgetsaddons windowsystem \
		xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11 xcb

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
