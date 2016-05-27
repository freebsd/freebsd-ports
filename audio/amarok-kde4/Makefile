# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	amarok
PORTVERSION=	2.8.0
PORTREVISION=	6
CATEGORIES=	audio kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE music player

LIB_DEPENDS=	libtag.so:audio/taglib \
		libtag-extras.so:audio/taglib-extras \
		liblastfm.so:audio/liblastfm \
		libofa.so:audio/libofa \
		libavcodec.so:multimedia/ffmpeg \
		libqjson.so:devel/qjson \
		libqca.so:devel/qca \
		libdbus-1.so:devel/dbus
BUILD_DEPENDS=	${LOCALBASE}/lib/qt4/plugins/script/libqtscript_core.so.1.0.0:devel/qtscriptgenerator
RUN_DEPENDS=	${LOCALBASE}/lib/qt4/plugins/script/libqtscript_core.so.1.0.0:devel/qtscriptgenerator \
		${KDE4_PREFIX}/lib/kde4/kio_upnp_ms.so:net/kio-upnp-ms

USE_KDE4=	kdelibs libkcddb libkcompactdisc \
		nepomuk-core runtime automoc4 strigi
USE_MYSQL=	embedded
USE_QT4=	corelib dbus designer gui network opengl \
		phonon script sql svg webkit xml \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	x11
USES=		cmake pkgconfig shared-mime-info shebangfix tar:bzip2
SHEBANG_FILES=	src/kconf_update/amarok-2.4.1-tokens_syntax_update.pl
USE_LDCONFIG=	yes

BROKEN_sparc64=	does not build (GCC-related error)

OPTIONS_DEFINE=	AMAZON IPOD MP3TUNES MTP NLS
OPTIONS_DEFAULT=IPOD MP3TUNES MTP
OPTIONS_SUB=	yes

AMAZON_DESC=		Amazon MP3 store support via clamz
AMAZON_RUN_DEPENDS=	clamz:net/clamz

IPOD_DESC=		Apple iPod support
IPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod
IPOD_USE=		GNOME=gdkpixbuf2,glib20
IPOD_CMAKE_OFF=		-DWITH_IPOD:BOOL=Off

MP3TUNES_DESC=		MP3tunes support
MP3TUNES_LIB_DEPENDS=	libloudmouth-1.so:net-im/loudmouth \
			libcurl.so:ftp/curl
MP3TUNES_USE=		GNOME=glib20,libxml2
MP3TUNES_CMAKE_OFF=	-DWITH_MP3tunes:BOOL=Off

MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp
MTP_CMAKE_OFF=		-DWITH_Mtp:BOOL=Off

NLS_USES=		gettext
NLS_CMAKE_OFF=		-DBUILD_po:BOOL=Off

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/modules/FindMySQLAmarok.cmake
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${WRKSRC}/cmake/modules/FindLoudmouth.cmake
# Avoid installing MIME types prior to install stage.
	@${REINPLACE_CMD} -e '/XDG.*EXECUTABLE/ d' \
		${WRKSRC}/utilities/amzdownloader/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/utilities/amzdownloader/amzdownloader.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_SCRIPT} ${WRKSRC}/utilities/amzdownloader/amzdownloader.desktop \
		${STAGEDIR}${PREFIX}/share/applications/kde4

.include <bsd.port.mk>
