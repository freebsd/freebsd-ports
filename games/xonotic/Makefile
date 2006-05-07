# New ports collection makefile for:	Nexuiz
# Date created:				03 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nexuiz
PORTVERSION=	1.2.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A fast-paced, chaotic, and intense multiplayer first person shooter

NO_PACKAGE=	"Package will be 159MB, set FORCE_PACKAGE if you really want to build it"

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/Nexuiz/sources/darkplaces
MAKEFILE=	makefile.bsd
MAKE_ARGS=	CC="${CC}" OPTIM_RELEASE="${CFLAGS} -fno-strict-aliasing -ffast-math -funroll-loops"
ALL_TARGET=	#

PLIST_FILES=	%%CLIENT%%bin/${PORTNAME}-glx %%SDL_CLIENT%%bin/${PORTNAME}-sdl \
		%%SERVER%%bin/${PORTNAME}-dedicated %%DATADIR%%/data/data20050905-full.pk3
PLIST_DIRS=	%%DATADIR%%/data %%DATADIR%%

OPTIONS=	CLIENT		"Build GLX client"		on \
		SDL_CLIENT	"Build SDL client"		on \
		SERVER		"Build dedicated server"	on

.include <bsd.port.pre.mk>

.if !(defined(WITHOUT_CLIENT) && defined(WITHOUT_SDL_CLIENT))
# Loads libraries on run-time, thus RUN_DEPENDS
RUN_DEPENDS=	${LOCALBASE}/lib/libvorbis.so:${PORTSDIR}/audio/libvorbis \
		${LOCALBASE}/lib/libjpeg.so:${PORTSDIR}/graphics/jpeg
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

pre-patch:
	@${EXTRACT_CMD} ${WRKDIR}/Nexuiz/${PORTNAME}enginesource20050911.zip \
		-d ${WRKDIR}/Nexuiz/sources
	@${REINPLACE_CMD} -E 's,sdl-config,sdl11-config,g; 161,165d; \
		s,^#(LDFLAGS_UNIXCL),\1,' ${WRKSRC}/makefile.inc
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${X11BASE},; 74,$$d' \
		${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} 'LDFLAGS_SDL=$$(LDFLAGS_BSDSDL)' >> ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -E 's,"\.","${DATADIR}",' ${WRKSRC}/fs.c

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	${SH} -c '${FIND} ${WRKSRC} -name "darkplaces-*[^vp]" | while read f ; \
		do ${INSTALL_PROGRAM} $${f} ${PREFIX}/bin/${PORTNAME}-$${f##*-} ; done'
	@${MKDIR} ${DATADIR}/data
	${INSTALL_DATA} ${WRKDIR}/Nexuiz/data/data20050905-full.pk3 ${DATADIR}/data

.include <bsd.port.post.mk>
