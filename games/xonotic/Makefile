# New ports collection makefile for:	Nexuiz
# Date created:				03 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nexuiz
PORTVERSION=	2.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A fast-paced, chaotic, and intense multiplayer first person shooter

NO_PACKAGE=	Package will be 455MB, set FORCE_PACKAGE if you really want to build it

USE_ZIP=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/Nexuiz/sources/darkplaces
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}" OPTIM_RELEASE="${CFLAGS} -fno-strict-aliasing -funroll-loops"
ALL_TARGET=	#

OPTIONS=	CLIENT		"Build GLX client"		on \
		SDL_CLIENT	"Build SDL client"		on \
		SERVER		"Build dedicated server"	on \
		MAPPACK		"Install community map pack"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MAPPACK)
DISTFILES+=	nexmappack_r2${EXTRACT_SUFX}
PLIST_SUB+=	MAPPACK=""
.else
PLIST_SUB+=	MAPPACK="@comment "
.endif

.if !(defined(WITHOUT_CLIENT) && defined(WITHOUT_SDL_CLIENT))
# Loads libraries on run-time, thus RUN_DEPENDS
RUN_DEPENDS=	${LOCALBASE}/lib/libvorbis.so:${PORTSDIR}/audio/libvorbis \
		${LOCALBASE}/lib/libjpeg.so:${PORTSDIR}/graphics/jpeg \
		${LOCALBASE}/lib/libpng.so:${PORTSDIR}/graphics/png \
		${LOCALBASE}/lib/libcurl.so:${PORTSDIR}/ftp/curl
.endif

.if !defined(WITHOUT_CLIENT)
USE_GL=		yes
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
	@${EXTRACT_CMD} ${WRKDIR}/Nexuiz/sources/enginesource20080229.zip \
		-d ${WRKDIR}/Nexuiz/sources
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${X11BASE},' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -E 's,(fs_basedir\, )"",\1"${DATADIR}",' ${WRKSRC}/fs.c

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	${SH} -c '${FIND} ${WRKSRC} -name "darkplaces-*[^vp]" | \
		while read f ; do ${INSTALL_PROGRAM} $${f} \
			${PREFIX}/bin/${PORTNAME}-$${f##*-} ; done'
	@${MKDIR} ${DATADIR}/data
	${INSTALL_DATA} ${WRKDIR}/Nexuiz/data/*.pk3 ${DATADIR}/data
.if !defined(WITHOUT_MAPPACK)
	${INSTALL_DATA} ${WRKDIR}/data/*.pk3 ${DATADIR}/data
.endif

.include <bsd.port.post.mk>
