PORTNAME=	palapeli
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		https://www.kde.org/applications/games/palapeli/

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		qt:6 shared-mime-info tar:xz xorg
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		crash i18n itemviews jobwidgets kio libkdegames notifications \
		service solid widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base declarative
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
