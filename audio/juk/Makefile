# $FreeBSD$

PORTNAME=	juk
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Jukebox, tagger and music collection manager

LICENSE=	GPLv2

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons globalaccel i18n iconthemes itemviews \
		jobwidgets kio notifications service solid sonnet textwidgets \
		wallet widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network phonon4 svg widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
