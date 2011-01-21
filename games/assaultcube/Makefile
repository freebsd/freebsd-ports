# New ports collection makefile for:	actioncube
# Date created:				2007-02-25
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	assaultcube
PORTVERSION=	1.1.0.4
CATEGORIES=	games
MASTER_SITES=	SF/actiongame/AssaultCube%20Version%20${PORTVERSION}
DISTFILES=	AssaultCube_v${PORTVERSION}_source${EXTRACT_SUFX} \
		AssaultCube_v${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	lightside@safebox.ru
COMMENT=	Total conversion of the FPS game called Cube

USE_BZIP2=	yes
USE_OPENAL=	al
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	libenet
WRKSRC=		${WRKDIR}/${PORTVERSION}
CONFIGURE_ARGS=	--enable-shared=no --enable-static=yes
CONFIGURE_WRKSRC=	${WRKSRC}/source/enet
BUILD_WRKSRC=	${WRKSRC}/source/src
MAKE_JOBS_SAFE=	yes

PORTDATA=	config demos packages
PORTDOCS=	*

CFLAGS+=	-DFREEBSD

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		MASTER "Build master server" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED) && defined(WITHOUT_MASTER)
IGNORE=		needs at least one executable (CLIENT, DEDICATED or MASTER)
.endif

.if !defined(WITHOUT_CLIENT)
USE_GL=		yes
USE_SDL=	image mixer sdl
ALL_TARGET+=	client
SUB_FILES+=	${PORTNAME}_client
ACUBE_BIN+=	client
.endif

.if !defined(WITHOUT_DEDICATED)
ALL_TARGET+=	server
SUB_FILES+=	${PORTNAME}_server
ACUBE_BIN+=	server
.endif

.if !defined(WITHOUT_MASTER)
ALL_TARGET+=	master
SUB_FILES+=	${PORTNAME}_master
ACUBE_BIN+=	master
.endif

.if defined(WITHOUT_OPTIMIZED_CFLAGS)
post-patch:
	@${REINPLACE_CMD} -e 's|$$(CXXOPTFLAGS)||' ${WRKSRC}/source/src/Makefile
.endif

do-install:
.for f in ${ACUBE_BIN}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}_${f} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ac_${f} ${PREFIX}/libexec/${PORTNAME}_${f}
.endfor
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

post-install:
.for f in ${ACUBE_BIN}
	@${ECHO_CMD} bin/${PORTNAME}_${f} >> ${TMPPLIST}
	@${ECHO_CMD} libexec/${PORTNAME}_${f} >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
