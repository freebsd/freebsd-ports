# Created by: Brad Allen <braddo@tranceaddict.net>
# $FreeBSD$

PORTNAME=	stepmania
PORTVERSION=	5.0.11
DISTVERSIONPREFIX=	v
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rhythm game simulator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/Docs/Licenses.txt

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libpng.so:graphics/png

USE_GITHUB=	yes

USES=		cmake:outsource iconv jpeg perl5 pkgconfig shebangfix
SHEBANG_FILES=	Utils/*.pl extern/zlib/zlib2ansi
USE_XORG=	x11 xrandr xtst
USE_GL=		glew
USE_PERL5=	build
CMAKE_ARGS=	-DHAVE__MKDIR:BOOL=OFF
INSTALLS_ICONS=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		ALSA DOCS FFMPEG GTK2 JACK MAD PULSEAUDIO VAAPI VORBIS
OPTIONS_DEFAULT=	GTK2 MAD VORBIS
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_OFF=		-DWITH_ALSA:BOOL=OFF
FFMEPG_BUILD_DEPENDS=	yasm:devel/yasm
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_ON=	-DWITH_SYSTEM_FFMPEG:BOOL=ON
FFMPEG_CMAKE_OFF=	-DWITH_FFMPEG:BOOL=OFF
GTK2_USE=		gnome=gtk20
GTK2_CMAKE_ON=		-DWITH_GTK2:BOOL=ON
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_OFF=	-DWITH_JACK:BOOL=OFF
MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_CMAKE_OFF=		-DWITH_MP3:BOOL=OFF
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_OFF=	-DWITH_PULSE:BOOL=OFF
VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_CMAKE_OFF=	-DVA_FOUND:BOOL=OFF
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CMAKE_OFF=	-DWITH_OGG:BOOL=OFF

pre-build:
	@${MKDIR} ${WRKDIR}/wrappers
	@${ECHO_CMD} -n \
		> ${WRKDIR}/wrappers/stepmania
	@${ECHO_CMD} '#!${SH}' \
		>> ${WRKDIR}/wrappers/stepmania
	@${ECHO_CMD} 'cd ${PREFIX}/lib/stepmania' \
		>> ${WRKDIR}/wrappers/stepmania
	@${ECHO_CMD} 'exec ./stepmania "$$@"' \
		>> ${WRKDIR}/wrappers/stepmania

do-install:
	(cd ${WRKDIR}/wrappers && ${INSTALL_SCRIPT} stepmania \
		${STAGEDIR}${PREFIX}/bin)
.for i in Announcers BGAnimations BackgroundEffects BackgroundTransitions \
	Characters Courses Data NoteSkins Scripts Songs Themes
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} \
		${STAGEDIR}${PREFIX}/lib/stepmania)
.endfor
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} stepmania \
		${STAGEDIR}${PREFIX}/lib/stepmania)
	(cd ${WRKSRC} && ${INSTALL_DATA} stepmania.desktop \
		${STAGEDIR}${PREFIX}/share/applications)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} icons \
		${STAGEDIR}${PREFIX}/share)

post-install-GTK2-on:
	(cd ${WRKSRC} && ${INSTALL_LIB} GtkModule.so \
		${STAGEDIR}${PREFIX}/lib/stepmania)

post-install-DOCS-on:
	@(cd ${WRKSRC}/Docs && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR} "! -name Licenses.txt")

.include <bsd.port.mk>
