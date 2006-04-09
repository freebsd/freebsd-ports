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

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Quake engine modification

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
USE_ZIP=	yes

MAKEFILE=	makefile
ALL_TARGET=	#

OPTIONS=	CLIENT "Build GLX client" on \
		DEDICATED "Build dedicated server" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL_CLIENT "Build SDL client" on

PLIST_FILES=	%%DATADIR%%/dummy
PLIST_DIRS=	%%DATADIR%%

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITH_CLIENT) && !defined(WITH_SDL_CLIENT) && \
    !defined(WITH_DEDICATED)
IGNORE=		please select at least one of CLIENT, SDL_CLIENT and DEDICATED
.endif

.if defined(WITH_CLIENT) || defined(WITH_SDL_CLIENT)
# Loads libraries at run-time, thus RUN_DEPENDS.
RUN_DEPENDS+=	${LOCALBASE}/lib/libjpeg.so:${PORTSDIR}/graphics/jpeg \
		${LOCALBASE}/lib/libvorbis.so:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITH_CLIENT)
USE_GL=		yes
ALL_TARGET+=	cl-release
EXE_TARGETS+=	${PORTNAME}-glx
PLIST_SUB+=	CLIENT=""
PLIST_FILES+=	bin/${PORTNAME}-glx
.endif

.if defined(WITH_DEDICATED)
ALL_TARGET+=	sv-release
EXE_TARGETS+=	${PORTNAME}-dedicated
PLIST_FILES+=	bin/${PORTNAME}-dedicated
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
MAKE_ENV+=	WITH_OPTIMIZED_CFLAGS=YES
.endif

.if defined(WITH_SDL_CLIENT)
USE_SDL=	sdl
ALL_TARGET+=	sdl-release
EXE_TARGETS+=	${PORTNAME}-sdl
PLIST_FILES+=	bin/${PORTNAME}-sdl
.endif

post-extract:
	@${UNZIP_CMD} -aq \
		-o ${WRKDIR}/${PORTNAME}enginesource${PORTVERSION}.zip \
		-d ${WRKDIR}

do-install:
.for f in ${EXE_TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}
	@${TOUCH} ${DATADIR}/dummy

.include <bsd.port.post.mk>
