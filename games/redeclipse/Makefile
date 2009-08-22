# New ports collection makefile for:	sauerbraten
# Date created:		2006-02-01
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	sauerbraten
PORTVERSION=	20090504
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2009_05_04
DISTNAME=	${PORTNAME}_2009_05_04_trooper_edition_linux

MAINTAINER=	acm@FreeBSD.org
COMMENT=	First person shooter based on Cube

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CONFIGURE_ENV=	ACLOCAL=true AUTOCONF=true AUTOMAKE=true
CONFIGURE_WRKSRC=	${WRKSRC}/src/enet
BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	libenet
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on

SUB_FILES=	sauer_client sauer_server pkg-message

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED)
IGNORE=		needs at least one executable (CLIENT or DEDICATED)
.endif

.if !defined(WITHOUT_CLIENT)
USE_GL=		yes
USE_SDL=	image mixer sdl
ALL_TARGET+=	client
PLIST_SUB+=	CLIENT=""
SAUER_BIN+=	client
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
ALL_TARGET+=	server
PLIST_SUB+=	DEDICATED=""
SAUER_BIN+=	server
.else
PLIST_SUB+=	DEDICATED="@comment "
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
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "packages data" ${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
