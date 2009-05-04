# New ports collection makefile for:	re2c
# Date created:		14 May 1998
# Whom:			Eivind Eklund <eivind@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	re2c
PORTVERSION=	0.13.5
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Compile regular expression to C (much faster final code than flex)

GNU_CONFIGURE=	yes

MAN1=		re2c.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
.include <bsd.port.mk>
