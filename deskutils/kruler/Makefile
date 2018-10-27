# $FreeBSD$

PORTNAME=	kruler
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE screen ruler

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons ecm doctools i18n \
		notifications widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	x11 xcb

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
