# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nexuiz
PORTVERSION=	2.5.2
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/NexuizRelease/Nexuiz%20${PORTVERSION} \
		SF/${PORTNAME}/mappack/nexmappack_r2:mappack
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast-paced, chaotic, and intense multiplayer first person shooter

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		jpeg:${PORTSDIR}/graphics/jpeg

LICENSE=	GPLv2

MANUAL_PACKAGE_BUILD=   huge

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/Nexuiz/sources/darkplaces
MAKEFILE=	BSDmakefile
MAKE_ARGS=	DP_FS_BASEDIR="${DATADIR}" CC="${CC}" \
		DP_PRELOAD_DEPENDENCIES=yes DP_LINK_TO_LIBJPEG=yes \
		CFLAGS_LIBJPEG="-I${LOCALBASE}/include" \
		OPTIM_RELEASE="${CFLAGS} -fno-strict-aliasing -funroll-loops" \
		STRIP="${STRIP_CMD}"
MAKE_JOBS_UNSAFE=yes
ALL_TARGET=	#

OPTIONS_DEFINE=	MAPPACK
OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT SDL_CLIENT SERVER
CLIENT_DESC=	Build GLX client
SDL_CLIENT_DESC=	Build SDL client
SERVER_DESC=	Build dedicated server
MAPPACK_DESC=	Install community map pack
FLAVOR_DESC=	Executable Selection

OPTIONS_DEFAULT=	CLIENT SDL_CLIENT SERVER MAPPAC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMAPPACK}
DISTFILES+=	nexmappack_r2${EXTRACT_SUFX}:mappack
PLIST_SUB+=	MAPPACK=""
.else
PLIST_SUB+=	MAPPACK="@comment "
.endif

.if ${PORT_OPTIONS:MCLIENT} || defined{WITH_SDL_CLIENT}
LIB_DEPENDS+=	modplug:${PORTSDIR}/audio/libmodplug \
		png15:${PORTSDIR}/graphics/png \
		theora:${PORTSDIR}/multimedia/libtheora
.endif

.if ${PORT_OPTIONS:MCLIENT}
USE_GL=		glut
USE_XORG=	x11 xpm xxf86vm xxf86dga xext
ALL_TARGET+=	cl-release
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MSDL_CLIENT}
USE_SDL=	sdl
ALL_TARGET+=	sdl-release
PLIST_SUB+=	SDL_CLIENT=""
.else
PLIST_SUB+=	SDL_CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MSERVER}
ALL_TARGET+=	sv-release
PLIST_SUB+=	SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif

post-extract:
	@${EXTRACT_CMD} ${WRKDIR}/Nexuiz/sources/enginesource20091001.zip \
		-d ${WRKDIR}/Nexuiz/sources

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' \
		${WRKSRC}/${MAKEFILE} ${WRKSRC}/makefile.inc
	@${REINPLACE_CMD} -e '/LDFLAGS_BSDSV/s,$$,-L${LOCALBASE}/lib,' \
		${WRKSRC}/makefile.inc
# Fix for libpng 1.4
	@${REINPLACE_CMD} -e 's,gray_1_2_4_to_8,expand_&,g' \
		${WRKSRC}/image_png.c

do-install:
	${SH} -c '${FIND} ${WRKSRC} -name "darkplaces-*[^vpj]" | \
		while read f ; do ${INSTALL_PROGRAM} $${f} \
			${PREFIX}/bin/${PORTNAME}-$${f##*-} ; done'
	@${MKDIR} ${DATADIR}/data ${DATADIR}/havoc
	${INSTALL_DATA} ${WRKDIR}/Nexuiz/data/*.pk3 ${DATADIR}/data
	${INSTALL_DATA} ${WRKDIR}/Nexuiz/havoc/*.pk3 ${DATADIR}/havoc
.if ${PORT_OPTIONS:MMAPPACK}
	${INSTALL_DATA} ${WRKDIR}/data/*.pk3 ${DATADIR}/data
.endif
.if ${PORT_OPTIONS:MSERVER}
	cd ${WRKDIR}/Nexuiz && ${COPYTREE_SHARE} server ${DATADIR}
# Fixup lost +x permissions on scripts after COPYTREE_SHARE
	${FIND} ${DATADIR}/server -type f -name *.sh -o -name rcon*.pl | \
		${XARGS} ${CHMOD} +x
.endif

.include <bsd.port.mk>
