# $FreeBSD$

PORTNAME=	kio
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

PATCH_SITES=	https://invent.kde.org/frameworks/kio/-/commit/
PATCHFILES=	a8a2c08014484145a4bd2a541a1cbeb8be856bf1.diff:-p1 \
		3134b410b98e40b34d3b80d123ee1304f6c084d4.diff:-p1 \
		dd0cd63612edc7f65292c1aa74c70bc33dfba8af.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 resource and network access abstraction

USES=		cmake compiler:c++11-lib desktop-file-utils \
		gettext gnome kde:5 qt:5 ssl tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	archive auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons doctools ecm \
		i18n iconthemes itemviews jobwidgets kded \
		notifications service solid sonnet textwidgets wallet \
		widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus declarative gui network \
		script widgets x11extras xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
