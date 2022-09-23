PORTNAME=	kmouth
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	accessibility kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Speech synthesizer frontend for KDE
WWW=		https://www.kde.org/applications/utilities/kmouth/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		i18n jobwidgets kio service solid widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network printsupport speech widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
