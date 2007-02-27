# New ports collection makefile for:	actioncube
# Date created:				2007-02-25
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	actioncube
PORTVERSION=	0.92
CATEGORIES=	games
MASTER_SITES=	SF/actiongame
DISTNAME=	ActionCube_v${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Total conversion of the FPS game called Cube

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	libenet
WRKSRC=		${WRKDIR}/ActionCube
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
MAKE_ENV+=	CXXOPTFLAGS=""
.endif

do-install:
.for f in ${ACUBE_BIN}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}_${f} ${PREFIX}/bin
.endfor
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
.for f in ${ACUBE_BIN}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ac_${f} \
		${PREFIX}/libexec/${PORTNAME}_${f}
.endfor
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -r bot config packages ${DATADIR}
	@${FIND} ${DATADIR} -type d | ${XARGS} ${CHMOD} ${BINMODE}
	@${FIND} ${DATADIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
	@${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} ${BINMODE}
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.post.mk>
