# $FreeBSD$

PORTNAME=	kmousetool
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	accessibility kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Automatic mouse click tool for KDE

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons \
		ecm i18n iconthemes notifications widgetsaddons xmlgui
USE_QT=		core dbus gui phonon4 widgets xml \
		buildtools_build qmake_build
USE_XORG=	ice sm x11 xext xtst

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
