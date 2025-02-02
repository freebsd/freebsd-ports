PORTNAME=	knavalbattle
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		http://www.kde.org/applications/games/navalbattle/

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		qt:6 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons dnssd doctools i18n libkdegames sonnet textwidgets \
		widgetsaddons xmlgui \
		ecm:build
USE_QT=		base

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
