PORTNAME=	ksudoku
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		https://www.kde.org/applications/games/ksudoku/

USES=		cmake compiler:c++11-lang gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl glu
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		crash guiaddons i18n jobwidgets kio libkdegames service \
		widgetsaddons xmlgui \
		ecm:build
USE_QT=		base declarative

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
