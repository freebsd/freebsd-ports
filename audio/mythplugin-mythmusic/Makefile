PORTNAME=	mythmusic
DISTVERSIONPREFIX=	v
DISTVERSION=	35.0
CATEGORIES=	audio
PKGNAMEPREFIX=	mythplugin-

MAINTAINER=	ahicks@p-o.co.uk
COMMENT=	Music playing plugin for MythTV
WWW=		https://www.mythtv.org/wiki/MythMusic

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libmp3lame.so:audio/lame \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libmyth-35.so:multimedia/mythtv

USES=		gmake qt:5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	MythTV
GH_PROJECT=	mythtv
USE_QT=		buildtools:build core gui qmake:build sql widgets xml
SHEBANG_FILES=	../mythtv/programs/scripts/metadata/Music/mbutils.py

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --cc="${CC}" --cxx="${CXX}" \
		--disable-all \
		--enable-mythmusic
CONFIGURE_ENV=	QMAKESPEC="${QMAKESPEC}" MOC="${MOC}" \
		QTDIR="${PREFIX}" PKG_CONFIG_PATH="${LOCALBASE}/libdata/pkgconfig"
MAKE_ENV=	QTDIR="${PREFIX}" \
		QMAKESPEC="${QMAKESPEC}"
DESTDIRNAME=	INSTALL_ROOT
WRKSRC_SUBDIR=	mythplugins
PLIST_SUB=	MYTHSHARE="share/mythtv"

OPTIONS_DEFINE=	CDIO
OPTIONS_DEFAULT=CDIO

CDIO_LIB_DEPENDS=	libcdio.so:sysutils/libcdio \
			libcdio_paranoia.so:sysutils/libcdio-paranoia
CDIO_CONFIGURE_ENABLE=	cdio

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/mythmusic/mythmusic/mythmusic.pro
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mythtv/plugins/libmythmusic.so

.include <bsd.port.mk>
