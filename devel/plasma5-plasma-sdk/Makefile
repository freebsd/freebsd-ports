PORTNAME=	plasma-sdk
DISTVERSION=	${KDE_PLASMA_VERSION}.1
CATEGORIES=	devel kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 applications useful for Plasma development
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		dbusaddons i18n iconthemes jobwidgets kdeclarative kio package \
		parts plasma-framework service solid sonnet syntaxhighlighting \
		texteditor textwidgets widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build \
		kirigami2:run
USE_QT=		concurrent core dbus declarative gui network svg widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
