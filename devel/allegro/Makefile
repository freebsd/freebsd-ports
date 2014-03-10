# $FreeBSD$

PORTNAME=	allegro
DISTVERSION=	4.4.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/alleg/allegro/${PORTVERSION}
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Cross-platform library for games and multimedia programming

LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

USES=		gmake cmake pkgconfig
USE_XORG=	x11 xpm xext xcursor xxf86vm xxf86dga
USE_GL=		glu
USE_LDCONFIG=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}"
CMAKE_ARGS+=	-DDOCDIR="${DOCSDIR}"

SHLIB_VER=	${PORTVERSION}

# Wrong versioning upstream
PORTSCOUT=	ignore:1

OPTIONS_DEFINE=	ALSA JACK OGG
OPTIONS_GROUP=	DEMOS_EXAMPLES
OPTIONS_GROUP_DEMOS_EXAMPLES=	DEMOS EXAMPLES
OPTIONS_DEFAULT=	ALSA DEMOS OGG
DEMOS_DESC=	Install Demos programs, requires EXAMPLES

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS CHANGES THANKS readme.txt

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs

OPTIONS_SUB=	yes

EXAMPLES_CMAKE_ON=	-DWANT_EXAMPLES=on
EXAMPLES_CMAKE_OFF=	-DWANT_EXAMPLES=off
ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CMAKE_ON=		-DWANT_ALSA=on
ALSA_CMAKE_OFF=		-DWANT_ALSA=off
JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CMAKE_ON=		-DWANT_JACK=on
JACK_CMAKE_OFF=		-DWANT_JACK=off
OGG_LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg
OGG_CMAKE_ON=		-DWANT_LOGG=on
OGG_CMAKE_OFF=		-DWANT_LOGG=of

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
CFLAGS+=	-L${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MDEMOS} && ${PORT_OPTIONS:MEXAMPLES}
SUB_FILES+=	shooter skater skater_agl \
		pkg-message
MASTER_SITES+=	SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DISTFILES+=	shooter.png:icons \
		skater.png:icons
DESKTOP_ENTRIES+="Shooter" "In a distant corner of the galaxy" "shooter" \
		"shooter" "Game;ArcadeGame;" false
DESKTOP_ENTRIES+="Skater" "Allegro's next demo game" "skater" \
		"skater" "Game;ArcadeGame;" false
DESKTOP_ENTRIES+="Skater AGL" "Allegro's next demo game" "skater" \
		"skater_agl" "Game;ArcadeGame;" false
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/allegro-$${ALLEGRO_VERSION}||' \
		${WRKSRC}/docs/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|<X11/extensions/xf86dga.h>|<X11/extensions/Xxf86dga.h>|' \
		${WRKSRC}/src/x/xdga2.c
.if ${PORT_OPTIONS:MJACK}
	@${REINPLACE_CMD} -e 's|jack_client = jack_client_new(jack_client_name);|jack_client = jack_client_open(jack_client_name, (jack_options_t)0, NULL);|' \
		${WRKSRC}/src/unix/jack.c
.endif
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|add_subdirectory(docs)|#add_subdirectory(docs)|' \
		${WRKSRC}/CMakeLists.txt
.endif

post-install:
	@${INSTALL_MAN} ${WRKSRC}/docs/man/*.3 ${STAGEDIR}${MAN3PREFIX}/man/man3/
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.for l in ex12bit ex3buf ex3d exaccel exalpha exbitmap exblend excamera excolmap \
	exconfig excustom exdata exdbuf exexedat exfixed exflame exflip exfont \
	exgui exhello exjoy exkeys exlights exmem exmidi exmouse expackf expal \
	expat exquat exrgbhsv exrotscl exsample exscale exscn3d exscroll exshade \
	exspline exsprite exstars exstream exswitch exsyscur extimer extrans \
	extrans2 extruec exunicod exupdate exxfade exzbuf
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/examples/allegro/${l}
.endfor

.if ${PORT_OPTIONS:MDEMOS} && ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_SCRIPT} ${WRKDIR}/shooter ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${_DISTDIR}/shooter.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	@(cd ${STAGEDIR}${EXAMPLESDIR}/demos/shooter && ${CHMOD} 755 shooter)
	${INSTALL_SCRIPT} ${WRKDIR}/skater* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${_DISTDIR}/skater.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	@(cd ${STAGEDIR}${EXAMPLESDIR}/demos/skater && ${CHMOD} 755 skater*)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/examples/allegro/demos/shooter/shooter
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/examples/allegro/demos/skater/skater*
.endif

.include <bsd.port.mk>
