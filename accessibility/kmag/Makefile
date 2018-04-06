# $FreeBSD$

PORTNAME=	kmag
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	accessibility kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Screen magnifier

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons ecm \
		i18n kio service widgetsaddons xmlgui
USE_QT5=	core dbus gui printsupport widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
