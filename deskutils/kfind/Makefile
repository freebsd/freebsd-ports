# $FreeBSD$

PORTNAME=	kfind
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Find files and folders

USES=		cmake:outsource gettext kde:5 qt:5 tar:xz
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons crash ecm filemetadata guiaddons i18n iconthemes itemviews \
		jobwidgets kdelibs4support kio notifications parts service \
		solid sonnet textwidgets unitconversion widgetsaddons \
		windowsystem xmlgui
USE_QT=		core dbus gui network printsupport widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
