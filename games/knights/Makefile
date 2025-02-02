PORTNAME=	knights
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE chess interface
WWW=		https://github.com/KDE/knights

RUN_DEPENDS=	${LOCALBASE}/bin/gnuchess:games/gnuchess

LICENSE=	GPLv2

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons i18n libkdegames libplasma package plotting service \
		solid sonnet textwidgets wallet widgetsaddons xmlgui \
		ecm:build
USE_QT=		base declarative
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
