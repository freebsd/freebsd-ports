# New ports collection makefile for:	amarok
# Date created:			Tue Feb 24 02:21:14 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	amarok
PORTVERSION=	2.6.0
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE music player

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib \
		tag-extras.1:${PORTSDIR}/audio/taglib-extras \
		lastfm.0:${PORTSDIR}/audio/liblastfm \
		ofa:${PORTSDIR}/audio/libofa \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		qjson.0:${PORTSDIR}/devel/qjson \
		qca.2:${PORTSDIR}/devel/qca \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		kcddb.5:${PORTSDIR}/multimedia/kdemultimedia4
BUILD_DEPENDS=	${LOCALBASE}/lib/qt4/plugins/script/libqtscript_core.so.1.0.0:${PORTSDIR}/devel/qtscriptgenerator
RUN_DEPENDS=	${LOCALBASE}/lib/qt4/plugins/script/libqtscript_core.so.1.0.0:${PORTSDIR}/devel/qtscriptgenerator \
		${KDE4_PREFIX}/lib/kde4/kio_upnp_ms.so:${PORTSDIR}/net/kio-upnp-ms

LATEST_LINK=	${PORTNAME}-kde4

USE_KDE4=	kdehier kdelibs kdeprefix runtime automoc4 strigi
USE_MYSQL=	embedded
USE_QT4=	dbus designer gui network opengl \
		phonon script sql svg webkit xml \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	x11
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	IPOD MP3TUNES MTP
IPOD_DESC=	iPod support
MP3TUNES_DESC=	MP3tunes support

OPTIONS_DEFAULT=	IPOD MP3TUNES MTP

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not build on sparc64 (GCC-related error)
.endif

.if ${PORT_OPTIONS:MIPOD}
LIB_DEPENDS+=	gpod.7:${PORTSDIR}/audio/libgpod
USE_GNOME+=	gdkpixbuf2 glib20
PLIST_SUB+=	IPOD=""
.else
CMAKE_ARGS+=	-DWITH_IPOD:BOOL=Off
PLIST_SUB+=	IPOD="@comment "
.endif

.if ${PORT_OPTIONS:MMP3TUNES}
LIB_DEPENDS+=	loudmouth-1.0:${PORTSDIR}/net-im/loudmouth \
		curl.6:${PORTSDIR}/ftp/curl
USE_GNOME+=	glib20 libxml2
PLIST_SUB+=	MP3TUNES=""
.else
CMAKE_ARGS+=	-DWITH_MP3tunes:BOOL=Off
PLIST_SUB+=	MP3TUNES="@comment "
.endif

.if ${PORT_OPTIONS:MMTP}
LIB_DEPENDS+=	mtp.9:${PORTSDIR}/audio/libmtp
PLIST_SUB+=	MTP=""
.else
CMAKE_ARGS+=	-DWITH_Mtp:BOOL=Off
PLIST_SUB+=	MTP="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DBUILD_po:BOOL=Off
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/modules/FindMySQLAmarok.cmake
	${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${WRKSRC}/cmake/modules/FindLoudmouth.cmake

.include <bsd.port.mk>
