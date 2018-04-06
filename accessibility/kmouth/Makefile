# $FreeBSD$

PORTNAME=	kmouth
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	accessibility kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Speech synthesizer frontend for KDE

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		ecm i18n jobwidgets kio service widgetsaddons xmlgui
USE_QT5=	core dbus gui network printsupport speech widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
