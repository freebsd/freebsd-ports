# New ports collection makefile for:	kmquake2
# Date created:				19 May 2005
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	kmquake2
PORTVERSION=	0.19
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake2/engines/KMQuake2/:src \
		http://qexpo.quakedev.com/uploaded/54/:data \
		http://www.markshan.com/maps/:pax \
		ftp://ftp.splatterworld.de/games/q2/mods/:pax \
		http://www.markshan.com/engine/:paxpatch
DISTNAME=	KMQuake2_${PORTVERSION:S/.//}_src_unix
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${KMQ2_FLARES}:src \
		${KMQ2_DATA}:data
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Enhanced Quake2 OpenGL only engine with Lazarus support

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		openal.0:${PORTSDIR}/audio/openal \
		png.5:${PORTSDIR}/graphics/png \
		vorbis.3:${PORTSDIR}/audio/libvorbis
EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

WRKSRC=		${WRKDIR}/KMQuake2_${PORTVERSION:S/.//}_src_unix

USE_BZIP2=	yes
USE_GCC=	3.2+
USE_GMAKE=	yes
USE_GL=		yes

OPTIONS=	3ZB2 "Build 3zb2 modification (bots)" off \
		CTF "Build Capture The Flag modification" off \
		DEDICATED "Build dedicated server" on \
		HYBRID "Build Rogue-Xatrix hybrid modification" off \
		LIGHTS "Build Lights modification with bots" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		PAX "Build Pax Imperia modification" off \
		ROGUE "Build Ground Zero (Rogue( mission pack" off \
		SDL "Build SDL client" on \
		XATRIX "Build The Reckoning (Xatrix) mission pack" off \
		ZAERO "Build Zaero mission pack" off

ALL_TARGET=	release

MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR=${LIBDIR:S/${PREFIX}\///}

LIBDIR=		${PREFIX}/lib/${PORTNAME}

KMQ2_ADDONS=	KMQuake2_addons_src_unix${EXTRACT_SUFX}
KMQ2_DATA=	kmquake2_${PORTVERSION:S/.//}.zip
KMQ2_FLARES=	Flares.tar
PAX_DATA=	paximperia.zip
PAX_PATCH=	pax_101_patch.zip

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

MOD_LIST=	3ZB2 CTF HYBRID LIGHTS PAX ROGUE ROGUE_XATRIX XATRIX ZAERO

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
DISTFILES+=	${KMQ2_ADDONS}
EXTRACT_ONLY+=	${KMQ2_ADDONS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-addons__Makefile
MAKE_ENV+=	KMQ2_ADDONS="${KMQ2_ADDONS:S/${EXTRACT_SUFX}//}"
.endif

.if !defined(WITHOUT_DEDICATED)
MAKE_ENV+=	BUILD_DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
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
.else
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(MOD_REQUESTED)
post-patch:
	@${FIND} ${WRKDIR}/${KMQ2_ADDONS:S/${EXTRACT_SUFX}//} \
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
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/${PORTNAME} ${PREFIX}/bin
.if !defined(WITHOUT_SDL)
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/${PORTNAME}-sdl ${PREFIX}/bin
.endif
	${MKDIR} ${LIBDIR}/baseq2
	${CP} -Rp ${WRKSRC}/quake2/baseq2/* ${LIBDIR}/baseq2
.if defined(MOD_REQUESTED)
	${CP} -Rp ${WRKDIR}/${KMQ2_ADDONS:S/${EXTRACT_SUFX}//}/quake2/* \
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
