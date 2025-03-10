PORTNAME=	ktuberling
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		https://www.kde.org/applications/games/ktuberling/

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		qt:6 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		iconthemes itemmodels itemviews jobwidgets kio libkdegames \
		newstuff notifications notifyconfig parts phonon service solid \
		sonnet textwidgets unitconversion widgetsaddons windowsystem \
		xmlgui \
		ecm:build
USE_QT=		base declarative

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
