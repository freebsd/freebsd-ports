# New ports collection makefile for:   cocktail
# Date created:        12 november 2003
# Whom:                wjw
#
# $FreeBSD$
#

PORTNAME=	cocktail
PORTVERSION=	9309
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://wwwold.first.fraunhofer.de/cocktail/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	wjw@withagen.nl
COMMENT=	Compiler tools with attribute grammars

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAN1=		ag.1 puma.1 mpp.1 lalr.1 ell.1 bnf.1 ast.1 rex.1 mtc.1
MAN2=		mtc.2

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
BROKEN=		Segfault during build on FreeBSD >= 8.0
.endif

post-extract:
		${RM} -f ${WRKSRC}/mtc/m2c/SYSTEM_.h
		${RM} -f ${WRKSRC}/mtc/m2c/SYSTEM_.c

.include <bsd.port.post.mk>
