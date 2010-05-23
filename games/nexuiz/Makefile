# New ports collection makefile for:	Nexuiz
# Date created:				03 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nexuiz
PORTVERSION=	2.5.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/NexuizRelease/Nexuiz%20${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A fast-paced, chaotic, and intense multiplayer first person shooter

# Package size below is for default set of OPTIONS
NO_PACKAGE=	Package will be 942MB, set FORCE_PACKAGE if you really want it

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/Nexuiz/sources/darkplaces
MAKEFILE=	BSDmakefile
MAKE_ARGS=	DP_FS_BASEDIR="${DATADIR}" CC="${CC}" \
		DP_PRELOAD_DEPENDENCIES=yes DP_LINK_TO_LIBJPEG=yes \
		CFLAGS_LIBJPEG="-I${LOCALBASE}/include" \
		OPTIM_RELEASE="${CFLAGS} -fno-strict-aliasing -funroll-loops"
ALL_TARGET=	#

OPTIONS=	CLIENT		"Build GLX client"		on \
		SDL_CLIENT	"Build SDL client"		on \
		SERVER		"Build dedicated server"	on \
		MAPPACK		"Install community map pack"	on

.include <bsd.port.pre.mk>

.if !(defined(WITH_CLIENT) || defined(WITH_SDL_CLIENT) || defined(WITH_SERVER))
IGNORE=		requires at least one of [SDL_]CLIENT or SERVER options
.endif

.if !defined(WITHOUT_MAPPACK)
DISTFILES+=	nexmappack_r2${EXTRACT_SUFX}
PLIST_SUB+=	MAPPACK=""
.else
PLIST_SUB+=	MAPPACK="@comment "
.endif

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl
.if defined(WITH_CLIENT) || defined(WITH_SDL_CLIENT)
LIB_DEPENDS+=	modplug.0:${PORTSDIR}/audio/libmodplug \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		theora.0:${PORTSDIR}/multimedia/libtheora
.endif

.if !defined(WITHOUT_CLIENT)
USE_GL=		glut
USE_XORG=	x11 xpm xxf86vm xxf86dga xext
ALL_TARGET+=	cl-release
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_SDL_CLIENT)
USE_SDL=	sdl
ALL_TARGET+=	sdl-release
PLIST_SUB+=	SDL_CLIENT=""
.else
PLIST_SUB+=	SDL_CLIENT="@comment "
.endif

.if !defined(WITHOUT_SERVER)
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
.if !defined(WITHOUT_MAPPACK)
	${INSTALL_DATA} ${WRKDIR}/data/*.pk3 ${DATADIR}/data
.endif
.if !defined(WITHOUT_SERVER)
	cd ${WRKDIR}/Nexuiz && ${COPYTREE_SHARE} server ${DATADIR}
# Fixup lost +x permissions on scripts after COPYTREE_SHARE
	${FIND} ${DATADIR}/server -type f -name *.sh -o -name rcon*.pl | \
		${XARGS} ${CHMOD} +x
.endif

.include <bsd.port.post.mk>
