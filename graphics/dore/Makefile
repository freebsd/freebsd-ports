# New ports collection makefile for:	dore
# Date created:		10 February 1995
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	pdore
PORTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Dynamic Object Rendering Environment

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/dore
EXTRACT_CMD=	${MKDIR} ${WRKSRC}; cd ${WRKSRC}; ${GZIP_CMD}
MAKEFILE=	mk.stdx
MAKE_ENV=	DORE_LOC=${WRKDIR}
NOPRECIOUSMAKEVARS=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/subsys/*.c

pre-install:
	@${MKDIR} ${PREFIX}/share/dore

.include <bsd.port.post.mk>
