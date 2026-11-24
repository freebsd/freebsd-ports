PORTNAME=	ktexteditor
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Full text editor component

LIB_DEPENDS=	libeditorconfig.so:editors/editorconfig-core-c

USES=		cmake cpe gettext-tools gl kde:6 qt:6 tar:xz xorg
CPE_VENDOR=	kde
USE_GL=		opengl
USE_KDE=	archive auth codecs colorscheme completion config \
		guiaddons i18n itemviews kio parts sonnet \
		syntaxhighlighting \
		ecm:build
USE_QT=		base declarative multimedia speech
USE_XORG=	x11

.include <bsd.port.mk>
