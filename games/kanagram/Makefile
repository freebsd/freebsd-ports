PORTNAME=	kanagram
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Letter order game for KDE
WWW=		https://www.kde.org/applications/education/kanagram

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	attica auth codecs config configwidgets coreaddons crash \
		doctools i18n kdeclarative kio libkeduvocdocument newstuff \
		package service sonnet widgetsaddons xmlgui \
		ecm:build
USE_QT=		core dbus declarative gui network opengl speech svg widgets xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
