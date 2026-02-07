PORTNAME=	skladnik
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		https://apps.kde.org/skladnik/

USES=		cmake compiler:c++17-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	config configwidgets coreaddons crash dbusaddons \
		i18n kio libkdegames widgetsaddons xmlgui \
		ecm:build
USE_QT=		base

# POVRay is used for development
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_POVRay

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
