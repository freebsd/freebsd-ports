# New ports collection makefile for:	an
# Date created:		28 Feb 1997
# Whom:			proff
#
# $FreeBSD$
#

PORTNAME=	an
PORTVERSION=	0.95
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast anagram generator

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_REINPLACE=	yes
ALL_TARGET=	with-getopt
MAN6=		an.6

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CC=|CC?=|g ; \
		 s|^CFLAGS=-O2|CFLAGS+=|g ; \
		 s| make| \$$\(MAKE\)|g'
	@${REINPLACE_CMD} -e 's|^\#OBJS|OBJS|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/<stdint.h>/d' ${WRKSRC}/an.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/an ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/an.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
