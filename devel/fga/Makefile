# New ports collection makefile for:	fga
# Date created:		2006-11-29
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	fga
PORTVERSION=	1.4
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Fast Genetic Algorithm library

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

EXAMPLES=	graph_gen maxbit tsp tsp_bf

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	${INSTALL_DATA}	${WRKSRC}/include/fga.hpp ${PREFIX}/include
	${INSTALL_PROGRAM} ${EXAMPLES:S,^,${WRKSRC}/,} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,:S,$,.cpp,} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}/
.endif

.include <bsd.port.mk>
