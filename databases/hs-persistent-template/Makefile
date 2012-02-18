# New ports collection makefile for:	hs-persistent-template
# Date created:		December 26, 2011
# Whom:			haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	persistent-template
PORTVERSION=	0.6.3.1
CATEGORIES=	databases haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Type-safe, non-relational, multi-backend persistence

LICENSE=	BSD

USE_CABAL=	monad-control>=0.2 persistent>=0.6.2 text>=0.5 \
		transformers>=0.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
