# New ports collection makefile for:	happy
# Date created:				22 December 2000
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	happy
PORTVERSION=	1.18.4
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	An LALR(1) parser generator for the functional language Haskell

XMLDOCS=	doc/happy:html
USE_AUTOTOOLS=	autoconf:262:env

STANDALONE=	yes
EXECUTABLE=	happy

PORTDATA=		*
PORTEXAMPLES=		*
INSTALL_PORTEXAMPLES=	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
