# New ports collection makefile for:	frink
# Date created:			8 May 2001
# Whom:				Mikhail Teterin
#
# $FreeBSD$
#

PORTNAME=	frink
PORTVERSION=	2.1.5
CATEGORIES=	devel
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	mi@aldan.algebra.com

#MAN1=		${PORTNAME}.1
MANCOMPRESSED=	maybe

MAKEFILE=	${FILESDIR}/Makefile.bsd

.ifndef NOPORTDOCS
PLIST_SUB+=	DOCSDIR=${DOCSDIR:S,${PREFIX:S,/$,,}/,,}
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/README \
		${WRKSRC}/README.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
