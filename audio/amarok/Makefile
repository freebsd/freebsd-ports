PORTNAME=	amarok
DISTVERSION=	3.3.2
CATEGORIES=	audio kde
MASTER_SITES=	KDE/stable/amarok/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE music player
WWW=		https://amarok.kde.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libmtp.so:multimedia/libmtp \
		libtag.so:audio/taglib \
		libunwind.so:devel/libunwind

USES=		cmake compiler:c++14-lang cpe desktop-file-utils gettext gl gnome \
		gstreamer kde:6 pkgconfig python qt:6 ssl xorg \
		tar:xz
USE_GL=		gl opengl
USE_GNOME=	glib20
USE_GSTREAMER=	plugins
USE_KDE=	archive colorscheme coreaddons crash dbusaddons \
		dnssd doctools globalaccel guiaddons i18n \
		iconthemes kcmutils kio notifications package \
		solid statusnotifieritem texteditor textwidgets \
		threadweaver windowsystem \
		ecm:build doctools:build
USE_QT=		base declarative svg tools webengine
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes

CPE_VENDOR=	kde

CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_Googlemock=True

OPTIONS_DEFINE=		EMBEDDED IPOD LASTFM
OPTIONS_DEFAULT=	IPOD
OPTIONS_SUB=		yes

EMBEDDED_DESC=		Use a dedicated MySQL instance (requires MariaDB)
EMBEDDED_BUILD_DEPENDS=	${LOCALBASE}/libexec/mysqld:${_MYSQL_SERVER}
EMBEDDED_USES=		mysql:${AMAROK_SQL_VER},client,server
EMBEDDED_USES_OFF=	mysql
EMBEDDED_CMAKE_BOOL=	WITH_EMBEDDED_DB

# Requires libmygpo-qt6 >= 1.2.0. https://github.com/gpodder/libmygpo-qt
# GPODDER_DESC=		Enable gpodder.net support
# GPODDER_USE=		KDE=kwallet
# GPODDER_CMAKE_BOOL=	WITH_GPODDER

IPOD_DESC=		Apple iPod support
IPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod \
			libimobiledevice-1.0.so:comms/libimobiledevice \
			libplist-2.0.so:devel/libplist
IPOD_USE=		GNOME=gdkpixbuf
IPOD_CMAKE_BOOL=	WITH_IPOD

# /usr/local/include/lastfm6/global.h:65:26: error: invalid operands to binary expression ('const char *' and 'QLatin1String')
LASTFM_DESC=		Enable last.fm support (broken)
LASTFM_BROKEN=		fails to build with liblastfm-qt6
LASTFM_LIB_DEPENDS=	liblastfm6.so:audio/liblastfm
LASTFM_USE=		KDE=kwallet
LASTFM_CMAKE_BOOL=	WITH_LASTFM

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MEMBEDDED} && (${MYSQL_FLAVOUR} == mysql)
IGNORE=		EMBEDDED option requires MariaDB
.endif

.include <bsd.port.post.mk>
