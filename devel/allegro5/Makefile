PORTNAME=	allegro
DISTVERSION=	5.2.10.1
CATEGORIES=	devel games
MASTER_SITES=	https://github.com/liballeg/${PORTNAME}${PKGNAMESUFFIX}/releases/download/${DISTVERSION}/
PKGNAMESUFFIX=	5

MAINTAINER=	kpedersen@disroot.org
COMMENT=	Cross-platform C library for games and multimedia programming
WWW=		https://liballeg.org/

LICENSE=	BSD3CLAUSE ZLIB
LICENSE_COMB=	dual

BUILD_DEPENDS=	minimp3>=0:audio/minimp3 \
		dumb>=0:audio/dumb
LIB_DEPENDS=	libFLAC.so:audio/flac \
		libfreeimage.so:graphics/freeimage \
		libfreetype.so:print/freetype2 \
		libinotify.so:devel/libinotify \
		libogg.so:audio/libogg \
		libopus.so:audio/opus \
		libopusfile.so:audio/opusfile \
		libphysfs.so:devel/physfs \
		libpng.so:graphics/png \
		libsharpyuv.so:graphics/webp \
		libtheoradec.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis \
		libvorbisfile.so:audio/libvorbis \
		libwebp.so:graphics/webp

USES=		cmake compiler:c++11-lang gl gnome jpeg localbase openal:soft \
		pkgconfig xorg
USE_GL=		glu opengl
USE_GNOME=	cairo gdkpixbuf gtk30
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xcursor xext xi xinerama xpm xrandr xscrnsaver \
		xxf86dga xxf86vm

CMAKE_ARGS=	-DMANDIR=${PREFIX}/share/man
CMAKE_ON=	WANT_AUDIO WANT_COLOR WANT_DUMB WANT_FLAC WANT_FONT WANT_IMAGE \
		WANT_IMAGE_FREEIMAGE WANT_IMAGE_JPG WANT_IMAGE_PNG \
		WANT_IMAGE_WEBP WANT_MEMFILE WANT_MP3 WANT_NATIVE_DIALOG \
		WANT_NATIVE_IMAGE_LOADER WANT_OGG_VIDEO WANT_OPENAL WANT_OPENGL \
		WANT_OPUS WANT_OSS WANT_PHYSFS WANT_PRIMITIVES \
		WANT_RELEASE_LOGGING WANT_SHADERS_GL WANT_TESTS WANT_TTF \
		WANT_VIDEO WANT_VORBIS WANT_X11 WANT_X11_XF86VIDMODE \
		WANT_X11_XINERAMA WANT_X11_XRANDR WANT_X11_XSCREENSAVER
CMAKE_OFF=	WANT_ACODEC_DYNAMIC_LOAD WANT_ANDROID_LEGACY WANT_AQUEUE \
		WANT_CURL_EXAMPLE WANT_D3D WANT_D3D9EX WANT_DLL_TLS \
		WANT_DOCS_INFO WANT_DOCS_PDF WANT_DOCS_PDF_PAPER WANT_DSOUND \
		WANT_FRAMEWORKS WANT_GLES3 WANT_LUAJIT WANT_MONOLITH \
		WANT_MUDFLAP WANT_OPENSL WANT_PYTHON_WRAPPER WANT_SHADERS_D3D \
		WANT_STATIC_RUNTIME WANT_TREMOR WANT_WAIT_EVENT_SLEEP

CFLAGS+=	-L${LOCALBASE}/lib -Wno-unused-command-line-argument

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

PLIST_SUB=	SHLIB_VER="${DISTVERSION}" \
		SHLIB_VER1="${DISTVERSION:R}"

PORTDOCS=	*

OPTIONS_DEFINE=		ALSA DOCS EXAMPLES MANPAGES OPENMPT PULSEAUDIO
OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT=	MANPAGES OPENMPT
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_SUB=		yes
OPENMPT_DESC=		Support for OpenMPT playback

ALSA_BROKEN=		confirmed by running demos, leads to assertion at startup
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	WANT_ALSA

DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/pandoc:textproc/hs-pandoc
DOCS_CMAKE_BOOL=	WANT_DOCS_HTML

EXAMPLES_LIB_DEPENDS=	libenet.so:net/enet
EXAMPLES_CMAKE_BOOL=	WANT_DEMO WANT_EXAMPLES WANT_POPUP_EXAMPLES

MANPAGES_BUILD_DEPENDS=	${LOCALBASE}/bin/pandoc:textproc/hs-pandoc
MANPAGES_CMAKE_BOOL=	WANT_DOCS_MAN

OPENMPT_LIB_DEPENDS=	libopenmpt.so:audio/libopenmpt
OPENMPT_CMAKE_BOOL=	WANT_OPENMPT

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	WANT_PULSEAUDIO

SSE_CMAKE_BOOL=		WANT_ALLOW_SSE

_DEMOS=	cosmic_protector shooter skater speed

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"CHANGES*.txt CONTRIBUTORS.txt README.txt SECURITY.md" \
		${STAGEDIR}${DOCSDIR})
	(cd ${BUILD_WRKSRC} && ${COPYTREE_SHARE} docs/html/refman ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${BUILD_WRKSRC} && ${COPYTREE_SHARE} "demos examples" ${STAGEDIR}${EXAMPLESDIR})
	${FIND} -d ${STAGEDIR}${EXAMPLESDIR} \
		\( -name CMakeFiles -o -name cmake_install.cmake \) \
		-exec ${RM} -r {} +
	${FIND} ${STAGEDIR}${EXAMPLESDIR}/examples -regex ".*/ex_[a-z0-9_]*" \
		-exec ${STRIP_CMD} {} +
	${STRIP_CMD} ${_DEMOS:M*:C|(.+)|${STAGEDIR}${EXAMPLESDIR}/demos/\1/\1|}

.include <bsd.port.mk>
