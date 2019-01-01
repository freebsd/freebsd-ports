# $FreeBSD$

PORTNAME=	kimagemapeditor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE generator of HTML image maps

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes itemviews \
		jobwidgets js kdelibs4support khtml kio notifications \
		parts service solid sonnet textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui network printsupport widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
