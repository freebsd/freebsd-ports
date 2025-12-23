PORTNAME=	kphotoalbum
DISTVERSION=	6.1.0
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and organizer for KDE
WWW=		https://www.kphotoalbum.org/

LICENSE=	GPLv2+

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libvlc.so:multimedia/vlc

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-tools \
		gl jpeg kde:6 pkgconfig qt:6 shebangfix tar:xz xorg
USE_GL=		opengl
USE_KDE=	archive colorscheme completion config configwidgets coreaddons \
		guiaddons i18n iconthemes jobwidgets kio libkdcraw phonon \
		purpose service sonnet textwidgets widgetsaddons xmlgui \
		ecm:build
USE_QT=		5compat base
USE_XORG=	x11

SHEBANG_FILES=	scripts/kpa-backup.sh \
		scripts/open-raw.pl

OPTIONS_DEFINE=		MARBLE
OPTIONS_DEFAULT=	MARBLE

MARBLE_DESC=		Virtual globe and world atlas
MARBLE_USE=		KDE=marble
MARBLE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Marble

.include <bsd.port.options.mk>

# These dependencies are only needed if the WEBENGINE option is enabled
# in astro/marble.
.if ${PORT_OPTIONS:MMARBLE} && exists(${LOCALBASE}/lib/marble/plugins/Photo.so)
USE_QT+=	declarative positioning webchannel webengine
.endif

.include <bsd.port.mk>
