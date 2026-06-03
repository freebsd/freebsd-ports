PORTNAME=	gnash
PORTVERSION=	0.8.11.20190130
PORTREVISION=	5
CATEGORIES=	graphics multimedia

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNU Flash movie player
WWW=		https://www.gnu.org/software/gnash/

LICENSE=	GPLv3

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libnspr4.so:devel/nspr \
		libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libcurl.so:ftp/curl \
		libspeex.so:audio/speex \
		libspeexdsp.so:audio/speexdsp \
		libboost_thread.so:devel/boost-libs \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libtheora.so:multimedia/libtheora \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libdca.so:multimedia/libdca \
		libgsm.so:audio/gsm \
		libcairo.so:graphics/cairo \
		libdc1394.so:multimedia/libdc1394

USES=		cpe tar:bzip2 compiler:c++11-lang autoreconf gmake libtool \
		pkgconfig jpeg gnome gl sdl desktop-file-utils xorg localbase:ldflags
CPE_VENDOR=	gnu
USE_GITHUB=	yes
USE_CSTD=	gnu11
USE_CXXSTD=	c++11
USE_XORG=	x11 xau xdmcp xext xi xinerama ice sm xv
USE_GNOME=	atk gdkpixbuf gtk20 libxml2 pango
USE_GL=		egl
USE_SDL=	sound2
GH_ACCOUNT=	GitMirroring
GH_PROJECT=	gnash
GH_TAGNAME=	583ccbc1
GNU_CONFIGURE=	yes
PORTSCOUT=	limit:^0\.

SYSCONFIGDIR=	${PREFIX}/etc

# jemalloc leads to infinite recursion on FreeBSD
CONFIGURE_ENV=	SDL_CONFIG=${LOCALBASE}/bin/sdl2-config
CONFIGURE_ARGS=	--with-boost-incl="${LOCALBASE}/include" \
		--with-boost-lib="${LOCALBASE}/lib" \
		--with-plugins-install=prefix \
		--sysconfdir="${SYSCONFIGDIR}" \
		--enable-gui=gtk \
		--enable-renderer=cairo \
		--enable-sound=sdl \
		--disable-docbook \
		--disable-testsuite \
		--disable-kparts3 \
		--disable-jemalloc \
		--disable-npapi \
		--disable-kparts4 \
		--without-gconf
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

GNASHVER=	0.8.11dev
CONFIG_FILES=	gnashpluginrc gnashrc

PLIST_SUB+=	GNASHVER="${GNASHVER}"

USE_LDCONFIG=	${PREFIX}/lib/gnash

OPTIONS_DEFINE=	CYGNAL FFMPEG VAAPI DOCS NLS
OPTIONS_DEFAULT=VAAPI FFMPEG

NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
CYGNAL_DESC=	Cygnal media server
VAAPI_DESC=	VAAPI support

CYGNAL_CONFIGURE_ENABLE=	cygnal
VAAPI_LIB_DEPENDS+=	libva.so:multimedia/libva
VAAPI_CPPFLAGS=		-I../libdevice/vaapi
VAAPI_CONFIGURE_ON=	--enable-device=egl,x11,vaapi
VAAPI_CONFIGURE_OFF+=	--enable-hwaccel=none
VAAPI_CONFIGURE_OFF+=	--enable-device=egl,x11
FFMPEG_LIB_DEPENDS=	libavcodec.so.58:multimedia/ffmpeg4
FFMPEG_CPPFLAGS=	-I${LOCALBASE}/ffmpeg4/include
FFMPEG_CFLAGS=		-I${LOCALBASE}/ffmpeg4/include
FFMPEG_LDFLAGS=		-L${LOCALBASE}/ffmpeg4/lib
FFMPEG_CONFIGURE_ON+=	--enable-media=ffmpeg
FFMPEG_CONFIGURE_ON+=	--with-ffmpeg-incl="${LOCALBASE}/ffmpeg4/include/libavcodec"
FFMPEG_CONFIGURE_ON+=	--with-ffmpeg-lib=${LOCALBASE}/ffmpeg4/lib
FFMPEG_CONFIGURE_OFF=	--enable-media=no
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.options.mk>

# Cygnal option processing
.if ${PORT_OPTIONS:MCYGNAL}
CONFIG_FILES+=	cygnalrc
.endif

post-patch:
	${REINPLACE_CMD} -e 's|lib64|lib|g' -e 's|lib32|lib|g' \
		${WRKSRC}/macros/libslist
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
			-e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/macros/incllist
	${REINPLACE_CMD} -e 's|CODEC_ID_|AV_CODEC_ID_|' \
		${WRKSRC}/libmedia/ffmpeg/VideoDecoderFfmpegVaapi.cpp

post-install:
	# eglinfo conflicts with mesa-demos
	${MV} ${STAGEDIR}/${PREFIX}/bin/eglinfo ${STAGEDIR}/${PREFIX}/bin/eglinfo-gnash
.for conf in ${CONFIG_FILES}
	${MV} ${STAGEDIR}/${SYSCONFIGDIR}/${conf} ${STAGEDIR}${SYSCONFIGDIR}/${conf}.dist
.endfor

.include <bsd.port.mk>
