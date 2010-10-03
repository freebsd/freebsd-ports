# New ports collection makefile for:	sauerbraten
# Date created:		2006-02-01
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	bloodfrontier
DISTVERSION=	B2
PORTREVISION=	3
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

ALL_TARGET=	libenet ${BINARIES}
MAKE_JOBS_SAFE=	yes

SUB_FILES=	bfclient bfserver pkg-message

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not build on sparc64
.endif

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED)
IGNORE=		needs at least one executable (CLIENT or DEDICATED)
.endif

.if !defined(WITHOUT_CLIENT)
USE_GL=		yes
USE_SDL=	image mixer sdl
PLIST_FILES+=	bin/bfclient libexec/bfclient
BINARIES+=	client
.endif

.if !defined(WITHOUT_DEDICATED)
PLIST_FILES+=	bin/bfserver libexec/bfserver
BINARIES+=	server
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

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
