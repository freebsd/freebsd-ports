# New ports collection makefile for:	darkplaces
# Date created:				25 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	darkplaces
PORTVERSION=	20071120
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org:9090/twilight/darkplaces/files/
DISTNAME=	${PORTNAME}engine${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake engine modification

USE_ZIP=	yes
USE_GMAKE=	yes
USE_XORG=	xxf86dga xpm
USE_DOS2UNIX=	darkplaces.txt
MAKE_ENV=	DP_FS_BASEDIR="${Q1DIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKEFILE=	makefile
ALL_TARGET=	#

OPTIONS=	CLIENT "Build GLX client" on \
		DEDICATED "Build dedicated server" on \
		SDL "Build SDL client" on

PLIST_FILES=	%%DATADIR%%/dummy
PLIST_DIRS=	%%DATADIR%%
PORTDOCS=	darkplaces.txt

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITH_CLIENT) && !defined(WITH_DEDICATED) && !defined(WITH_SDL)
IGNORE=		needs at least one of CLIENT, DEDICATED and SDL options
.endif

.if defined(WITH_CLIENT) || defined(WITH_SDL)
USE_GL=		yes
# Loads libraries at run-time, thus RUN_DEPENDS.
RUN_DEPENDS+=	${LOCALBASE}/lib/libjpeg.so:${PORTSDIR}/graphics/jpeg \
		${LOCALBASE}/lib/libvorbis.so:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITH_CLIENT)
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

.if defined(WITH_SDL)
USE_SDL=	sdl
ALL_TARGET+=	sdl-release
EXE_TARGETS+=	${PORTNAME}-sdl
PLIST_FILES+=	bin/${PORTNAME}-sdl
.endif

post-extract:
	@${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} \
		${WRKDIR}/${PORTNAME}enginesource${PORTVERSION}.zip \
		-d ${WRKDIR}

do-install:
.for f in ${EXE_TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}
	@${TOUCH} ${DATADIR}/dummy
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/darkplaces.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
