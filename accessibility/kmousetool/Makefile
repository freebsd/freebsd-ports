# $FreeBSD$

PORTNAME=	kmousetool
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	accessibility kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Automatic mouse click tool for KDE

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons \
		ecm i18n iconthemes notifications widgetsaddons xmlgui
USE_QT5=	core dbus gui phonon4 widgets xml \
		buildtools_build qmake_build
USE_XORG=	ice sm x11 xext xtst

.include <bsd.port.mk>
