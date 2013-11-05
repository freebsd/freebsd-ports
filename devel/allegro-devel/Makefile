# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	allegro
DISTVERSION=	5.0.9
CATEGORIES=	devel
MASTER_SITES=	SF/alleg/allegro/${PORTVERSION}
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Cross-platform library for games and multimedia programming

LICENSE=	ZLIB BSD
LICENSE_COMB=	dual

LIB_DEPENDS+=	libjack.so:${PORTSDIR}/audio/jack \
		libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libphysfs.so:${PORTSDIR}/devel/physfs

USES=		gmake cmake pkgconfig
USE_XORG=	x11 xpm xext xcursor xxf86vm xxf86dga
USE_OPENAL=	soft
USE_GL=		gl glu
USE_FREETYPE=	yes
USE_LDCONFIG=	yes

PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB+=	SHLIB_VER1="${SHLIB_VER1}"

SHLIB_VER=	${PORTVERSION}
SHLIB_VER1=	${PORTVERSION:R}

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

# Wrong versioning upstream
PORTSCOUT=	skipv:5.0.10

OPTIONS_DEFINE=	ALSA DOCS PULSEAUDIO
OPTIONS_GROUP=	DEMOS_EXAMPLES
OPTIONS_GROUP_DEMOS_EXAMPLES=	DEMOS EXAMPLES
OPTIONS_DEFAULT=	ALSA DEMOS
DEMOS_DESC=	Install Demos programs, requires EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs

OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/pandoc:${PORTSDIR}/textproc/hs-pandoc
ALSA_LIB_DEPENDS=	libasound.so.2:${PORTSDIR}/audio/alsa-lib
ALSA_CMAKE_ON=		-DWANT_ALSA=on
ALSA_CMAKE_OFF=		-DWANT_ALSA=off
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DWANT_PULSEAUDIO=on
PULSEAUDIO_CMAKE_OFF=	-DWANT_PULSEAUDIO=off

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEMOS} && ${PORT_OPTIONS:MEXAMPLES}
CMAKE_ARGS+=-DWANT_DEMO=on
SUB_FILES+=	cosmic_protector speed \
		pkg-message
MASTER_SITES+=	SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DISTFILES+=	cosmic_protector.png:icons \
		speed.png:icons
DESKTOP_ENTRIES+="Cosmic Protector" "Protect the earth from a deadly meteor shower" "cosmic_protector" \
		"cosmic_protector" "Game;ArcadeGame;" false
DESKTOP_ENTRIES+="SPEED" "Simultaneous Projections Employing an Ensemble of Displays" "speed" \
		"speed" "Game;ArcadeGame;" false
.else
CMAKE_ARGS+=-DWANT_DEMO=off
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|lib$${LIB_SUFFIX}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/addons/audio/pulseaudio.c

post-install:
	@${INSTALL_MAN} ${WRKSRC}/docs/man/* ${STAGEDIR}${MAN3PREFIX}/man/man3/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@(cd ${DOCSRCDIR2} && ${COPYTREE_SHARE} "src html" ${STAGEDIR}${DOCSDIR2})

	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.if ${PORT_OPTIONS:MDEMOS} && ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_SCRIPT} ${WRKDIR}/cosmic_protector ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${_DISTDIR}/cosmic_protector.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	@(cd ${STAGEDIR}${EXAMPLESDIR}/demos/cosmic_protector && ${CHMOD} 755 cosmic_protector)
	${INSTALL_SCRIPT} ${WRKDIR}/speed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${_DISTDIR}/speed.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	@(cd ${STAGEDIR}${EXAMPLESDIR}/demos/speed && ${CHMOD} 755 speed)
.endif

.include <bsd.port.mk>
