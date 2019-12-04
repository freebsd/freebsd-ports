# $FreeBSD$

PORTNAME=	amarok
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.70
PKGVERSIONSUFFIX=	-g${GH_TAGNAME}
PORTREVISION=	1
CATEGORIES=	audio kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE music player

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libfftw3.so:math/fftw3 \
		liblastfm5.so:audio/liblastfm-qt5 \
		libqjson-qt5.so:devel/qjson \
		libqca-qt5.so:devel/qca \
		libtag.so:audio/taglib \
		libtag-extras.so:audio/taglib-extras \
		liblz4.so:archivers/liblz4

USES=		cmake compiler:c++11-lang desktop-file-utils \
		kde:5 mysql:client,embedded pkgconfig qt:5 shebangfix ssl xorg

USE_QT=		core concurrent declarative dbus gui location network phonon4 \
		quickcontrols2 script scripttools sql svg webchannel \
		webkit widgets xml \
		buildtools_build qmake_build

USE_KDE=	archive auth attica bookmarks codecs config configwidgets \
		completion coreaddons crash dbusaddons dnssd globalaccel \
		guiaddons i18n iconthemes itemviews jobwidgets kdeclarative \
		kcmutils kio kirigami2 newstuff notifications notifyconfig \
		package parts service solid sonnet texteditor textwidgets \
		threadweaver widgetsaddons windowsystem xmlgui \
		ecm_build
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	kde
GH_TAGNAME=	0aa6ae0c77

SHEBANG_FILES=	src/kconf_update/amarok-2.4.1-tokens_syntax_update.pl
CMAKE_ARGS=	-DOPENSSL_ROOT_DIR=${OPENSSLBASE}
CMAKE_ON=	WITH_DESKTOP_UI
CMAKE_OFF=	WITH_FFmpeg

BROKEN_sparc64=	does not build (GCC-related error)

OPTIONS_DEFINE=		IPOD MP3TUNES MTP QTWEBENGINE
OPTIONS_DEFAULT=	IPOD MP3TUNES MTP
OPTIONS_DEFAULT_amd64=	QTWEBENGINE
OPTIONS_DEFAULT_i386=	QTWEBENGINE
OPTIONS_DEFAULT_powerpc64=	${OPTIONS_DEFAULT_powerpc64_${OSREL:R}}
OPTIONS_DEFAULT_powerpc64_13=	QTWEBENGINE
OPTIONS_SUB=		yes

IPOD_DESC=		Apple iPod support
IPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod \
			libimobiledevice.so:comms/libimobiledevice \
			libplist.so:devel/libplist
IPOD_USE=		GNOME=gdkpixbuf2,glib20
IPOD_USES=		gnome
IPOD_CMAKE_BOOL=	WITH_IPOD

MP3TUNES_DESC=		MP3tunes support
MP3TUNES_LIB_DEPENDS=	libloudmouth-1.so:net-im/loudmouth \
			libcurl.so:ftp/curl
MP3TUNES_LIB_DEPENDS_OFF=	libgcrypt.so:security/libgcrypt
MP3TUNES_USE=		GNOME=glib20,libxml2
MP3TUNES_USES=		gnome ssl

MP3TUNES_CMAKE_BOOL=	WITH_MP3Tunes
MP3TUNES_CMAKE_BOOL_OFF=	WITH_Libgcrypt

MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp
MTP_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Mtp

QTWEBENGINE_DESC=	Add dependency on qt5-webengine
QTWEBENGINE_USE=	qt=webengine
QTWEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngine

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/modules/FindMySQL.cmake
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${WRKSRC}/cmake/modules/FindLoudmouth.cmake

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages

.include <bsd.port.mk>
