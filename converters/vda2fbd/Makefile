# New ports collection makefile for:	vda2fbd
# Date created:		19 April 2003
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	vda2fbd
PORTVERSION=	0.9
CATEGORIES=	converters cad
MASTER_SITES=	http://www.dhondt.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An add-on converter for CalculiX

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc/*.ps \
	  ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/*.ps
.endif

.include <bsd.port.mk>
