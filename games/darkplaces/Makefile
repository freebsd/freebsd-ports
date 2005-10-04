# New ports collection makefile for:	darkplaces
# Date created:				25 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	darkplaces
PORTVERSION=	20050818
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/twilight/darkplaces/files/
DISTNAME=	${PORTNAME}engine${PORTVERSION}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Quake engine modification

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_ZIP=	yes

MAKEFILE=	makefile
ALL_TARGET=	#

OPTIONS=	CLIENT "Build GLX client" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SERVER "Build dedicated server" on \
		SDL_CLIENT "Build SDL client" on

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if !defined(WITH_CLIENT) && !defined(WITH_SDL_CLIENT) && \
    !defined(WITH_DEDICATED)
IGNORE=		You must choose at least one option of CLIENT, SDL_CLIENT and DEDICATED
.endif

.if defined(WITH_CLIENT) || defined(WITH_SDL_CLIENT)
# Loads libraries on run-time, thus RUN_DEPENDS
RUN_DEPENDS=	${LOCALBASE}/lib/libvorbis.so:${PORTSDIR}/audio/libvorbis \
		${LOCALBASE}/lib/libjpeg.so:${PORTSDIR}/graphics/jpeg
.endif

.if defined(WITH_CLIENT)
USE_GL=		yes
ALL_TARGET+=	cl-release
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_SDL_CLIENT)
USE_SDL=	sdl
ALL_TARGET+=	sdl-release
PLIST_SUB+=	SDL_CLIENT=""
.else
PLIST_SUB+=	SDL_CLIENT="@comment "
.endif

.if defined(WITH_SERVER)
ALL_TARGET+=	sv-release
PLIST_SUB+=	SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif

post-extract:
	@${UNZIP_CMD} -a -q \
		-o ${WRKDIR}/${PORTNAME}enginesource${PORTVERSION}.zip \
		-d ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g ; \
			s|/usr/X11R6|${X11BASE}| ; \
			s|gcc|${CC}| ; \
			s|\(-MD\)|${CFLAGS} \1|' \
				${WRKSRC}/${MAKEFILE} ${WRKSRC}/makefile.inc
	@${REINPLACE_CMD} -e 's,"\.","${DATADIR}",' ${WRKSRC}/fs.c
.if defined(WITHOUT_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|$$(OPTIM_RELEASE)||' ${WRKSRC}/makefile.inc
.endif
.if ${ARCH} == "alpha"
	@${REINPLACE_CMD} -e 's|-ffast-math||' ${WRKSRC}/makefile.inc
.endif

do-install:
	@${MKDIR} ${DATADIR}
.for f in ${PORTNAME}-glx ${PORTNAME}-sdl ${PORTNAME}-dedicated
	@${TEST} -f ${WRKSRC}/${f} && \
		${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
	@${TEST} -L ${PREFIX}/bin/${PORTNAME} || \
		${LN} -s ${PREFIX}/bin/${f} ${PREFIX}/bin/${PORTNAME}
.endfor

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
