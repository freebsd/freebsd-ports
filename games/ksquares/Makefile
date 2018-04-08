# $FreeBSD$

PORTNAME=	ksquares
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons ecm guiaddons i18n iconthemes itemviews kio \
		libkdegames notifyconfig widgetsaddons xmlgui
USE_QT5=	core dbus gui network qml quick widgets xml \
		buildtools_build qmake_build

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
