# New ports collection makefile for:	sauerbraten
# Date created:		2006-02-01
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	sauerbraten
PORTVERSION=	20100728
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2010_07_19
DISTNAME=	${PORTNAME}_2010_07_28_justice_edition_linux

MAINTAINER=	acm@FreeBSD.org
COMMENT=	First person shooter based on Cube

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CONFIGURE_ENV=	ACLOCAL=true AUTOCONF=true AUTOMAKE=true
CONFIGURE_WRKSRC=	${WRKSRC}/src/enet
CONFIGURE_ARGS=	--enable-shared=no --enable-static=yes
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	libenet
MAKE_JOBS_SAFE=	yes

MANUAL_PACKAGE_BUILD=	distfile exceeds pointyhat file size limits

PORTDATA=	data packages
PORTDOCS=	*

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		MASTER "Build master server" off

SUB_FILES=	sauer_client sauer_master sauer_server pkg-message

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED) && defined(WITHOUT_MASTER)
IGNORE=		needs at least one executable (CLIENT, DEDICATED or MASTER)
.endif

.if !defined(WITHOUT_CLIENT)
USE_GL=		yes
USE_SDL=	image mixer sdl
ALL_TARGET+=	client
SAUER_BIN+=	client
.endif

.if !defined(WITHOUT_DEDICATED)
ALL_TARGET+=	server
SAUER_BIN+=	server
.endif

.if !defined(WITHOUT_MASTER)
ALL_TARGET+=	master
SAUER_BIN+=	master
.endif

post-extract:
	@${FIND} ${WRKSRC} -type d -name CVS -type d -print0 | \
		${XARGS} -0 ${RM} -R

post-patch:
	@${REINPLACE_CMD} -Ee '/^#define (HAS_GETHOSTBY(NAME|ADDR)_R) 1/d' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
.for f in ${SAUER_BIN}
	${INSTALL_SCRIPT} ${WRKDIR}/sauer_${f} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/sauer_${f} ${PREFIX}/libexec
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
.for f in ${SAUER_BIN}
	@${ECHO_CMD} bin/sauer_${f} >> ${TMPPLIST}
	@${ECHO_CMD} libexec/sauer_${f} >> ${TMPPLIST}
.endfor
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
