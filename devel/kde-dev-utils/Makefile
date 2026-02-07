PORTNAME=	kde-dev-utils
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE development utilities

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gl kde:6 \
		qt:6 tar:xz xorg
USE_GL=		gl
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons i18n itemviews jobwidgets kio parts service solid \
		sonnet textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
