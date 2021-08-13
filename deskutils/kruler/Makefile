PORTNAME=	kruler
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE screen ruler

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs config configwidgets coreaddons doctools i18n \
		notifications widgetsaddons windowsystem xmlgui \
		ecm_build
USE_QT=		core dbus gui widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	x11 xcb

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
