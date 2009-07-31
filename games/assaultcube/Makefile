# New ports collection makefile for:	actioncube
# Date created:				2007-02-25
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	assaultcube
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/actiongame
DISTNAME=	AssaultCube_v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Total conversion of the FPS game called Cube

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	libenet
CONFIGURE_WRKSRC=	${WRKSRC}/source/enet
BUILD_WRKSRC=	${WRKSRC}/source/src

CFLAGS+=	-DFREEBSD

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED)
IGNORE=		needs at least one executable (CLIENT and DEDICATED)
.endif

.if !defined(WITHOUT_CLIENT)
USE_GL=		yes
USE_SDL=	image mixer sdl
ALL_TARGET+=	client
PLIST_SUB+=	CLIENT=""
SUB_FILES+=	${PORTNAME}_client
ACUBE_BIN+=	client
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
ALL_TARGET+=	server
PLIST_SUB+=	DEDICATED=""
SUB_FILES+=	${PORTNAME}_server
ACUBE_BIN+=	server
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITHOUT_OPTIMIZED_CFLAGS)
post-patch:
	@${REINPLACE_CMD} -e 's|$$(CXXOPTFLAGS)||' ${WRKSRC}/source/src/Makefile
.endif

do-install:
.for f in ${ACUBE_BIN}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}_${f} ${PREFIX}/bin
.endfor
.for f in ${ACUBE_BIN}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ac_${f} \
		${PREFIX}/libexec/${PORTNAME}_${f}
.endfor
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -r bot config packages ${DATADIR}
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
	@${FIND} ${DOCSDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${DOCSDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.post.mk>
