PORTNAME=	kruler
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE screen ruler
WWW=		https://www.kde.org/applications/graphics/kruler

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs config configwidgets coreaddons doctools i18n \
		notifications widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		core dbus gui widgets x11extras xml \
		buildtools:build qmake:build
USE_XORG=	x11 xcb

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
