# New ports collection makefile for:   cocktail
# Date created:        12 november 2003
# Whom:                wjw
#
# $FreeBSD$
#

PORTNAME=	cocktail
PORTVERSION=	9309
CATEGORIES=	devel
MASTER_SITES=	http://www.first.gmd.de/cocktail/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	wjw@withagen.nl
COMMENT=	Compiler tools with attribute grammars

WRKSRC=		${WRKDIR}/cocktail-9309
MAN1=		ag.1 puma.1 mpp.1 lalr.1 ell.1 bnf.1 ast.1 rex.1 mtc.1
MAN2=		mtc.2

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Coredump during build on !i386"
.endif

.include <bsd.port.post.mk>
