PORTNAME=	kanagram
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Letter order game for KDE
WWW=		https://www.kde.org/applications/education/kanagram

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	attica auth codecs config configwidgets coreaddons crash \
		doctools i18n kdeclarative kio libkeduvocdocument newstuff \
		package service sonnet widgetsaddons xmlgui \
		ecm:build
USE_QT=		base declarative

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
