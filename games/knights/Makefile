# Created by: Stefan Jahn <stefan.jahn@nemesis-sektor.de>
# $FreeBSD$

PORTNAME=	knights
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE chess interface

RUN_DEPENDS=	${LOCALBASE}/bin/gnuchess:games/gnuchess

LICENSE=	GPLv2

USES=		cmake kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		crash dbusaddons i18n libkdegames package plasma-framework \
		plotting service solid sonnet textwidgets wallet \
		widgetsaddons xmlgui
USE_QT=		concurrent core dbus declarative gui network speech \
		svg widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
