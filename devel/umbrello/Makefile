PORTNAME=	umbrello
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	UML modeller for KDE
WWW=		https://apps.kde.org/umbrello/

USES=		cmake compiler:c++17-lang desktop-file-utils \
		gettext-tools gnome kde:6 qt:6 tar:xz xorg
USE_GNOME=	libxml2 libxslt
USE_KDE=	archive completion config coreaddons crash i18n \
		iconthemes kio texteditor textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base svg
USE_XORG=	x11

CMAKE_OFF=	BUILD_APIDOC

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
