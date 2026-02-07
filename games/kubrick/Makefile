PORTNAME=	kubrick
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		https://www.kde.org/applications/games/kubrick/

USES=		cmake compiler:c++11-lang gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl glu
USE_KDE=	auth codecs config configwidgets coreaddons crash i18n kio \
		libkdegames service widgetsaddons xmlgui \
		ecm:build
USE_QT=		base

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
