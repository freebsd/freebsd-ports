PORTNAME=	ktexteditor
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

COMMENT=	Full text editor component
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libeditorconfig.so:editors/editorconfig-core-c

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	archive auth codecs colorscheme completion config \
		configwidgets coreaddons guiaddons i18n itemviews jobwidgets \
		kio parts service solid sonnet syntaxhighlighting textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base declarative speech multimedia
USE_XORG=	x11

.include <bsd.port.mk>
