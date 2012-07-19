# New ports collection makefile for:	kmquake2
# Date created:				19 May 2005
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	kmquake2
PORTVERSION=	0.19
PORTREVISION=	16
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake2/engines/KMQuake2/:src \
		http://qexpo2005.quakedev.com/uploaded/54/:data \
		http://www.markshan.com/maps/:pax \
		ftp://ftp.splatterworld.de/games/q2/mods/:pax \
		http://www.markshan.com/engine/:paxpatch
DISTNAME=	KMQuake2_${PORTVERSION:S/.//}_src_unix
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${KMQ2_FLARES}:src \
		${KMQ2_DATA}:data
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced Quake2 OpenGL only engine with Lazarus support

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

USE_BZIP2=	yes
USE_XORG=	xxf86dga
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/KMQuake2_${PORTVERSION:S/.//}_src_unix

OPTIONS_MULTI=	EXE
OPTIONS_MULTI_EXE=	CLIENT DEDICATED SDL
OPTIONS_DEFINE=	3ZB2 CFT GAME HYBRID LIGHTS OPTIMIZED_CFLAGS PAX ROGUE XMATRIX ZAERO DOCS
OPTIONS_DEFAULT=	CLIENT DEDICATED OPTIMIZED_CFLAGS SDL GAME
CLIENT_DESC=	Build client
CFT_DESC=	Build CTF (Capture The Flag) modification
3ZB2_DESC=	Build 3zb2 modification (bots)
CTF_DESC=	Build CTF (Capture The Flag) modification
DEDICATED_DESC=	Build dedicated server
GAME_DESC=	Build a main game .so file (required)
HYBRID_DESC=	Build Rogue-Xatrix hybrid modification
LIGHTS_DESC=	Build Lights modification with bots
PAX_DESC=	Build Pax Imperia modification
ROGUE_DESC=	Build Ground Zero (Rogue) mission pack
XMATRIX_DESC=	Build The Reckoning (Xatrix) mission pack
ZAERO_DESC=	Build Zaero mission pack

ALL_TARGET=	release

MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

LIBDIR=		${PREFIX}/lib/${PORTNAME}

KMQ2_ADDONS=	KMQuake2_addons_src_unix-1${EXTRACT_SUFX}
KMQ2_DATA=	kmquake2_${PORTVERSION:S/.//}.zip
KMQ2_FLARES=	Flares.tar
PAX_DATA=	paximperia.zip
PAX_PATCH=	pax_101_patch.zip

MOD_LIST=	3ZB2 CTF HYBRID LIGHTS PAX ROGUE XATRIX ZAERO

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.options.mk>

.for mod in ${MOD_LIST}
.   if ${PORT_OPTIONS:M${mod}}
MOD_REQUESTED+=	${mod:L}
MAKE_ENV+=	BUILD_${mod}=YES
PLIST_SUB+=	${mod}=""
.   else
PLIST_SUB+=	${mod}="@comment "
.   endif
.endfor

.if defined(MOD_REQUESTED)
DISTFILES+=	${KMQ2_ADDONS}:src
EXTRACT_ONLY+=	${KMQ2_ADDONS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-addons__Makefile
MAKE_ENV+=	KMQ2_ADDONS="${KMQ2_ADDONS:S/-1${EXTRACT_SUFX}//}"
.endif

.if ${PORT_OPTIONS:MCLIENT} || !empty(PORT_OPTIONS:MSDL)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		vorbis.4:${PORTSDIR}/audio/libvorbis
USE_OPENAL=	al
USE_GL=		yes
.endif

.if ${PORT_OPTIONS:MCLIENT}
MAKE_ENV+=	BUILD_KMQUAKE2=YES
PLIST_SUB+=	CLIENT=""
Q2BIN+=		${PORTNAME}
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
MAKE_ENV+=	BUILD_KMQUAKE2_DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
Q2BIN+=		${PORTNAME}-ded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if ${PORT_OPTIONS:MGAME}
MAKE_ENV+=	BUILD_GAME=YES
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	OPTIMIZED_CFLAGS=YES
.endif

.if ${PORT_OPTIONS:MPAX}
DISTFILES+=	${PAX_DATA}:pax \
		${PAX_PATCH}:paxpatch
PLIST_SUB+=	PAX=""
.else
PLIST_SUB+=	PAX="@comment "
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
MAKE_ENV+=	BUILD_KMQUAKE2_SDL=YES
PLIST_SUB+=	SDL=""
Q2BIN+=		${PORTNAME}-sdl
.else
PLIST_SUB+=	SDL="@comment "
.endif

post-patch:
# Resolve name collision with jpeg-8 and API png
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		-e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/renderer/r_image.c
.if defined(MOD_REQUESTED)
	@${FIND} ${WRKDIR}/${KMQ2_ADDONS:S/-1${EXTRACT_SUFX}//} \
		-type f -print0 | ${XARGS} -0 ${REINPLACE_CMD} -e \
		's|__linux__|__unix__|; s|#include <bits/nan\.h>||'
.endif

post-extract:
	@${UNZIP_CMD} -qo \
		${DISTDIR}/${DIST_SUBDIR}/${KMQ2_DATA} \
		baseq2/kmquake2.pk3 -d ${WRKSRC}/quake2
	@${TAR} xf ${DISTDIR}/${DIST_SUBDIR}/${KMQ2_FLARES} -C ${WRKSRC}
	@${CHMOD} go-w ${WRKSRC}/quake2/baseq2/kmquake2.pk3
.if ${PORT_OPTIONS:MPAX}
	@${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${PAX_DATA} \
		-x "*.dll" "*.bat" -d ${WRKSRC}/quake2/pax
	@${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${PAX_PATCH} \
		-x "*.dll" -d ${WRKSRC}/quake2/pax
.endif

do-install:
.for bin in ${Q2BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/${bin} ${PREFIX}/bin
.endfor
	${MKDIR} ${LIBDIR}/baseq2
.if ${PORT_OPTIONS:MGAME}
	${CP} -Rp ${WRKSRC}/quake2/baseq2/* ${LIBDIR}/baseq2
.endif
.if defined(MOD_REQUESTED)
	${CP} -Rp ${WRKDIR}/${KMQ2_ADDONS:S/-1${EXTRACT_SUFX}//}/quake2/* \
		${LIBDIR}
.endif
.if ${PORT_OPTIONS:MPAX}
	${CP} -R ${WRKSRC}/quake2/pax ${LIBDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} Readme.unix kmquake2.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
