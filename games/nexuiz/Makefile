# New ports collection makefile for:	Nexuiz
# Date created:				03 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nexuiz
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A fast-paced, chaotic, and intense multiplayer first person shooter

NO_PACKAGE=	Package will be 468MB, set FORCE_PACKAGE if you really want to build it

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/Nexuiz/sources/darkplaces
MAKEFILE=	BSDmakefile
MAKE_ARGS=	DP_FS_BASEDIR="${DATADIR}" CC="${CC}" \
		OPTIM_RELEASE="${CFLAGS} -fno-strict-aliasing -funroll-loops"
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
# Loads libraries at run-time, thus RUN_DEPENDS
RUN_DEPENDS=	${LOCALBASE}/lib/libvorbis.so:${PORTSDIR}/audio/libvorbis \
		${LOCALBASE}/lib/libjpeg.so:${PORTSDIR}/graphics/jpeg \
		${LOCALBASE}/lib/libpng.so:${PORTSDIR}/graphics/png \
		${LOCALBASE}/lib/libcurl.so:${PORTSDIR}/ftp/curl
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
	@${EXTRACT_CMD} ${WRKDIR}/Nexuiz/sources/enginesource20080511.zip \
		-d ${WRKDIR}/Nexuiz/sources

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' ${WRKSRC}/${MAKEFILE}
# Make Nexuiz' lhnetaddress structure really compatible with FreeBSD's
# sockaddr_in, and fix value for LHNETADDRESSTYPE_INET6_FAMILY
	@${REINPLACE_CMD} -e 's,10,28, ; \
		s,short family,char sin_len; unsigned char family,' \
			${WRKSRC}/lhnet.h

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
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
