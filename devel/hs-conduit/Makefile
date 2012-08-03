# New ports collection makefile for: hs-conduit
# Date created:        December 30, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	conduit
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Streaming data processing library

LICENSE=	BSD

USE_CABAL=	lifted-base>=0.1 monad-control>=0.3.1 resourcet>=0.3 \
		text>=0.11 transformers>=0.2.2 transformers-base>=0.4.1 \
		void>=0.5.5

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
