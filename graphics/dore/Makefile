# New ports collection makefile for:	dore
# Date created:		10 February 1995
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	pdore
PORTVERSION=	6.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Dynamic Object Rendering Environment

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_XORG=	x11
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/dore
EXTRACT_CMD=	${MKDIR} ${WRKSRC}; cd ${WRKSRC}; ${GZIP_CMD}
MAKEFILE=	mk.stdx
MAKE_ENV=	DORE_LOC=${WRKDIR}
NOPRECIOUSMAKEVARS=	yes
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/subsys/*.c

pre-install:
	@${MKDIR} ${PREFIX}/share/dore

.include <bsd.port.post.mk>
