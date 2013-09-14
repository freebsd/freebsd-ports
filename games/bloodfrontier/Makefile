# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	bloodfrontier
DISTVERSION=	B2
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Blood%20Frontier%20Beta%202
DISTNAME=	${PORTNAME}-${DISTVERSION}-linux

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Single- and multi-player first-person shooter based on Cube 2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/src/enet
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_XORG=	x11

ALL_TARGET=	libenet ${BINARIES}

SUB_FILES=	bfclient bfserver

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT DEDICATED
CLIENT_DESC=	Build client
DEDICATED_DESC= Build dedicated server
FLAVOR_DESC=	Executable Selections

OPTIONS_DEFAULT=	CLIENT DEDICATED OPTIMIZED_CFLAGS

.include <bsd.port.options.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.if ${PORT_OPTIONS:MCLIENT}
USE_GL=		yes
USE_SDL=	image mixer sdl
PLIST_FILES+=	bin/bfclient libexec/bfclient
BINARIES+=	client
.endif

.if ${PORT_OPTIONS:MDEDICATED}
PLIST_FILES+=	bin/bfserver libexec/bfserver
BINARIES+=	server
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -fomit-frame-pointer
CXXFLAGS+=	-O3 -fomit-frame-pointer
.endif

do-install:
.for f in ${BINARIES}
	${INSTALL_SCRIPT} ${WRKDIR}/bf${f} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bf${f} ${PREFIX}/libexec
.endfor
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} "." ${DATADIR}/

post-install:
	@${FIND} ${DATADIR} -type f | \
		${SED} -e 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} -e 's|^${PREFIX}/|@dirrm |' >> ${TMPPLIST}

.include <bsd.port.mk>
