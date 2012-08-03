# New ports collection makefile for: hs-resource-pool
# Date created:        April 7, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	resource-pool
PORTVERSION=	0.2.1.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A high-performance striped resource pooling implementation

LICENSE=	BSD

USE_CABAL=	hashable monad-control>=0.2.0.1 stm transformers \
		transformers-base>=0.4 vector>=0.7

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
