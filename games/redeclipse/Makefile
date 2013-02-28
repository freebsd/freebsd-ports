# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	redeclipse
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}_${PORTVERSION:C/^([0-9]+\.[0-9]+)\..*/\1/}
DISTNAME=	${PORTNAME}_${PORTVERSION}_nix_bsd

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Single-player and multi-player first-person ego-shooter

LICENSE_COMB=	multi
LICENSE=	MIT ZLIB

MANUAL_PACKAGE_BUILD=	huge

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/src/enet
CONFIGURE_ARGS=	--enable-shared=no --enable-static=yes
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	libenet ${BINARIES}
MAKE_JOBS_SAFE=	yes

SUB_FILES=	reclient reserver

PORTDATA=	*

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_MULTI=	COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT DEDICATED
OPTIONS_DEFAULT=CLIENT DEDICATED OPTIMIZED_CFLAGS
CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not build on sparc64
.endif

.if ${PORT_OPTIONS:MCLIENT}
USE_GL=		yes
USE_SDL=	image mixer sdl
PLIST_FILES+=	bin/reclient libexec/reclient share/pixmaps/redeclipse.ico
BINARIES+=	client

DESKTOP_ENTRIES="Red Eclipse" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/redeclipse.ico" \
		"reclient" \
		"Game;" \
		false
.endif

.if ${PORT_OPTIONS:MDEDICATED}
PLIST_FILES+=	bin/reserver libexec/reserver
BINARIES+=	server
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -fomit-frame-pointer
CXXFLAGS+=	-O3 -fomit-frame-pointer
.endif

do-install:
.for f in ${BINARIES}
	${INSTALL_SCRIPT} ${WRKDIR}/re${f} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/re${f} ${PREFIX}/libexec
.endfor
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} "." ${DATADIR}/
.endif
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_DATA} ${WRKSRC}/src/redeclipse.ico ${PREFIX}/share/pixmaps/
.endif

#post-install:
#	@${FIND} ${DATADIR} -type f | \
#		${SED} -e 's|^${PREFIX}/||' >> ${TMPPLIST}
#	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
#		${SED} -e 's|^${PREFIX}/|@dirrm |' >> ${TMPPLIST}

.include <bsd.port.mk>
