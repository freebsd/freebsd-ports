# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	redeclipse
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}_${PORTVERSION:C/^([0-9]+\.[0-9]+)\..*/\1/}
DISTNAME=	${PORTNAME}_${PORTVERSION}_nix

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
USE_AUTOTOOLS=	aclocal:env automake:env autoconf:env
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

ALL_TARGET=	libenet

SUB_FILES=	redeclipse redeclipse_server

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS
OPTIONS_MULTI=	COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT DEDICATED
OPTIONS_DEFAULT=CLIENT DEDICATED OPTIMIZED_CFLAGS
CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not build on sparc64
.endif

.if ${PORT_OPTIONS:MCLIENT}
USE_GL=		yes
USE_SDL=	image mixer sdl
PLIST_FILES+=	bin/redeclipse libexec/redeclipse share/pixmaps/redeclipse.ico
BINARIES+=	redeclipse
ALL_TARGET+=	client

DESKTOP_ENTRIES="Red Eclipse" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/redeclipse.ico" \
		"redeclipse" \
		"Game;" \
		false
.endif

.if ${PORT_OPTIONS:MDEDICATED}
PLIST_FILES+=	bin/redeclipse_server libexec/redeclipse_server
BINARIES+=	redeclipse_server
ALL_TARGET+=	server
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -fomit-frame-pointer
CXXFLAGS+=	-O3 -fomit-frame-pointer
.endif

do-install:
.for f in ${BINARIES}
	${INSTALL_SCRIPT} ${WRKDIR}/${f} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${f} ${PREFIX}/libexec
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "*" ${DOCSDIR}/
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "game data" ${DATADIR}/
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
