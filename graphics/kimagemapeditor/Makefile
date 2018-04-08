# $FreeBSD$

PORTNAME=	kimagemapeditor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications
PKGNAMESUFFIX=	# hack: uses kde:4 but we don't want the pkgname suffix

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE generator of HTML image maps

USES=		cmake:outsource kde:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes itemviews \
		jobwidgets js kdelibs4support khtml kio notifications \
		parts service solid sonnet textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui
USE_QT5=	core dbus gui network printsupport widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
