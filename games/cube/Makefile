# New ports collection makefile for:	cube
# Date created:        17 October 2002
# Whom:                Arjan van Leeuwen
#
# $FreeBSD$
#

PORTNAME=	cube
PORTVERSION=	2005.08.29
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2005_08_29
DISTFILES=	${CUBE_DATA} ${CUBE_SRC}
EXTRACT_ONLY=	${CUBE_SRC}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL 3D First Person Shooter game

BUILD_DEPENDS=	${LOCALBASE}/lib/libenet.a:${PORTSDIR}/net/enet

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}_source/src
CFLAGS+=	-fsigned-char
ALL_TARGET=	#empty
MALE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS
OPTIONS_MULTI=	TYPE
OPTIONS_MULTI_TYPE=	CLIENT DEDICATED
OPTIONS_DEFAULT=	CLIENT DEDICATED
CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server

SUB_FILES=	cube_client cube_server

CUBE_DATA=	${PORTNAME}_${PORTVERSION:S/./_/g}_unix.tar.gz
CUBE_SRC=	${PORTNAME}_${PORTVERSION:S/./_/g}_src.zip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
USE_GL=		yes
USE_SDL=	image mixer sdl
ALL_TARGET+=	client
PLIST_SUB+=	CLIENT=""
CUBE_BIN+=	client
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
ALL_TARGET+=	server
PLIST_SUB+=	DEDICATED=""
CUBE_BIN+=	server
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -fomit-frame-pointer
.endif

post-extract:
	@${TAR} zxf ${DISTDIR}/${CUBE_DATA} -C ${WRKDIR}

do-install:
.for f in ${CUBE_BIN}
	${INSTALL_SCRIPT} ${WRKDIR}/cube_${f} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cube_${f} ${PREFIX}/libexec
.endfor
	${MKDIR} ${DATADIR}
	@(cd ${WRKDIR}/cube && ${COPYTREE_SHARE} "data packages" ${DATADIR}/)
	${INSTALL_DATA} ${WRKDIR}/cube/autoexec.cfg ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/cube/readme.html ${DOCSDIR}
	@(cd ${WRKDIR}/cube/docs && ${COPYTREE_SHARE} \* ${DOCSDIR}/)
.endif

.include <bsd.port.mk>
