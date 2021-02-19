# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	allegro
DISTVERSION=	5.2.6.0
CATEGORIES=	devel games
PKGNAMESUFFIX=	5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform C library for games and multimedia programming

LICENSE=	ZLIB BSD3CLAUSE
LICENSE_COMB=	dual

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		libogg.so:audio/libogg \
		libphysfs.so:devel/physfs \
		libpng.so:graphics/png \
		libtheoradec.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis \
		libwebp.so:graphics/webp

USES=		cmake:insource compiler:c++11-lang gl gnome jpeg \
		openal:soft pkgconfig xorg uniquefiles:dirs
USE_GITHUB=	yes
GH_ACCOUNT=    	liballeg
GH_PROJECT=    	allegro5
USE_XORG=	x11 xpm xext xcursor xxf86vm xxf86dga sm ice xi xinerama xrandr \
		xscrnsaver
USE_GL=		gl glu
USE_GNOME=	gtk20 cairo gdkpixbuf2
USE_LDCONFIG=	yes

CFLAGS+=	-isystem${LOCALBASE}/include -L${LOCALBASE}/lib

PLIST_SUB=	SHLIB_VER="${PORTVERSION}" SHLIB_VER1="${PORTVERSION:R}"

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=		ALSA DOCS EXAMPLES PULSEAUDIO
OPTIONS_SUB=		yes

DOCS_DESC=		Build and install docs and manpages (requires pandoc)
DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/pandoc:textproc/hs-pandoc
DOCS_CMAKE_BOOL=	WANT_DOCS

ALSA_LIB_DEPENDS=	libasound.so.2:audio/alsa-lib
ALSA_CMAKE_BOOL=	WANT_ALSA
ALSA_BROKEN=		ALSA support is broken  # confirmed by running demos, leads to assertion at startup

EXAMPLES_CMAKE_BOOL=	WANT_EXAMPLES WANT_DEMOS

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	WANT_PULSEAUDIO

post-patch:
	@${REINPLACE_CMD} -e 's|lib$${LIB_SUFFIX}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	${INSTALL_MAN} ${WRKSRC}/docs/man/* ${STAGEDIR}${MAN3PREFIX}/man/man3/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "README.txt docs/src docs/html" ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "examples demos" ${STAGEDIR}${EXAMPLESDIR})
	${FIND} -d ${STAGEDIR}${EXAMPLESDIR} \
		-name CMakeFiles -o -name cmake_install.cmake \
		-exec ${RM} -r {} \;
	${FIND} ${STAGEDIR}${EXAMPLESDIR}/examples -regex ".*/ex_[a-z0-9_]*" \
		-exec ${CHMOD} a+x {} \; \
		-exec ${STRIP_CMD} {} \;
.for l in cosmic_protector skater speed
	@${CHMOD} a+x ${STAGEDIR}${EXAMPLESDIR}/demos/${l}/${l}
	@${STRIP_CMD} ${STAGEDIR}${EXAMPLESDIR}/demos/${l}/${l}
.endfor

.include <bsd.port.mk>
