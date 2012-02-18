# New ports collection makefile for:	hs-persistent
# Date created:		December 26, 2011
# Whom:			haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	persistent
PORTVERSION=	0.6.4.4
CATEGORIES=	databases haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Type-safe, non-relational, multi-backend persistence

LICENSE=	BSD

USE_CABAL=	blaze-html>=0.4 data-object>=0.3.1.7 enumerator>=0.4.9 \
		monad-control>=0.2 mtl>=2.0 path-pieces pool>=0.1 \
		text>=0.8 transformers>=0.2.1 transformers-base

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
