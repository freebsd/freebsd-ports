# $FreeBSD$

PORTNAME=	lskat
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons crash ecm \
		guiaddons i18n libkdegames notifyconfig widgetsaddons xmlgui
USE_QT=		core dbus declarative gui network svg widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
