# $FreeBSD$

PORTNAME=	juk
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Jukebox, tagger and music collection manager

LICENSE=	GPLv2

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		cmake kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash globalaccel i18n iconthemes itemviews \
		jobwidgets kio notifications service solid sonnet textwidgets \
		wallet widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui network phonon4 svg widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
