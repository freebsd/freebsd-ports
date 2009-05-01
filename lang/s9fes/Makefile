# New ports collection makefile for:	s9fes
# Date created:				23 February 2009
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	s9fes
PORTVERSION=	20090429
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.t3x.org/s9fes/

MAINTAINER=	nmh@t3x.org
COMMENT=	A simple and comprehensible Scheme interpreter

WRKSRC=		${WRKDIR}/s9fes

MAN1=		s9.1
MANCOMPRESSED=	yes

post-patch:
	${REINPLACE_CMD} -e "s,PREFIX=.*,PREFIX=${PREFIX}," ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s,LIBDIR=.*,LIBDIR=${DATADIR}," ${WRKSRC}/Makefile

.include <bsd.port.mk>
