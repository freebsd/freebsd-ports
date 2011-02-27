# New ports collection makefile for:	kmquake2
# Date created:				19 May 2005
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	kmquake2
PORTVERSION=	0.19
PORTREVISION=	13
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

OPTIONS=	3ZB2 "Build 3zb2 modification (bots)" off \
		CLIENT "Build client" on \
		CTF "Build CTF (Capture The Flag) modification" off \
		DEDICATED "Build dedicated server" on \
		GAME "Build a main game .so file (required)" on \
		HYBRID "Build Rogue-Xatrix hybrid modification" off \
		LIGHTS "Build Lights modification with bots" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		PAX "Build Pax Imperia modification" off \
		ROGUE "Build Ground Zero (Rogue) mission pack" off \
		SDL "Build SDL client" on \
		XATRIX "Build The Reckoning (Xatrix) mission pack" off \
		ZAERO "Build Zaero mission pack" off

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

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED) && \
    defined(WITHOUT_SDL)
IGNORE=		needs at least one executable (CLIENT, DEDICATED and SDL)
.endif

.for mod in ${MOD_LIST}
.   if defined(WITH_${mod})
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

.if !defined(WITHOUT_CLIENT) || !defined(WITHOUT_SDL)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		vorbis.4:${PORTSDIR}/audio/libvorbis
USE_OPENAL=	al
USE_GL=		yes
.endif

.if !defined(WITHOUT_CLIENT)
MAKE_ENV+=	BUILD_KMQUAKE2=YES
PLIST_SUB+=	CLIENT=""
Q2BIN+=		${PORTNAME}
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
MAKE_ENV+=	BUILD_KMQUAKE2_DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
Q2BIN+=		${PORTNAME}-ded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if !defined(WITHOUT_GAME)
MAKE_ENV+=	BUILD_GAME=YES
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=YES
.endif

.if defined(WITH_PAX)
DISTFILES+=	${PAX_DATA}:pax \
		${PAX_PATCH}:paxpatch
PLIST_SUB+=	PAX=""
.else
PLIST_SUB+=	PAX="@comment "
.endif

.if !defined(WITHOUT_SDL)
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
.if defined(WITH_PAX)
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
.if !defined(WITHOUT_GAME)
	${CP} -Rp ${WRKSRC}/quake2/baseq2/* ${LIBDIR}/baseq2
.endif
.if defined(MOD_REQUESTED)
	${CP} -Rp ${WRKDIR}/${KMQ2_ADDONS:S/-1${EXTRACT_SUFX}//}/quake2/* \
		${LIBDIR}
.endif
.if defined(WITH_PAX)
	${CP} -R ${WRKSRC}/quake2/pax ${LIBDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} Readme.unix kmquake2.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
