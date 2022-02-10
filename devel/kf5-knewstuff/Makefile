PORTNAME=	knewstuff
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

PATCH_SITES=	https://invent.kde.org/frameworks/knewstuff/-/commit/
PATCHFILES=	c8165b7a0d622e318b3353ccf257a8f229dd12c9.diff:-p1 \
		9a98fc12d8b049ef2df73ad46bf628ea99e7c8a5.diff:-p1 \
		e1c6f2bf383876a31cd3e3f9e6edcaa19dc0a7dd.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for downloading application assets from the network

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	archive attica5 auth codecs completion config \
		configwidgets coreaddons i18n iconthemes itemviews \
		jobwidgets kio kirigami2 package service sonnet textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm_build
USE_QT=		concurrent core dbus declarative gui network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
