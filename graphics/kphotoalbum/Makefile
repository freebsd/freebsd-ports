PORTNAME=	kphotoalbum
DISTVERSION=	5.12.0
PORTREVISION=	2
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and organizer for KDE
WWW=		https://www.kphotoalbum.org/

LICENSE=	GPLv2+

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libvlc.so:multimedia/vlc

USES=		cmake compiler:c++11-lang desktop-file-utils jpeg kde:5 \
		pkgconfig qt:5 shebangfix tar:xz xorg
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		i18n iconthemes jobwidgets kio libkdcraw phonon purpose service solid \
		sonnet textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network sql widgets xml \
		buildtools:build qmake:build
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
USE_QT+=	declarative location printsupport webchannel webengine
.endif

.include <bsd.port.mk>
