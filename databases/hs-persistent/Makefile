# New ports collection makefile for:	hs-persistent
# Date created:		December 26, 2011
# Whom:			haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	persistent
PORTVERSION=	0.9.0.4
PORTREVISION=	1
CATEGORIES=	databases haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Type-safe, multi-backend data serialization

LICENSE=	BSD

USE_CABAL=	aeson>=0.5 attoparsec base64-bytestring blaze-html>=0.4 \
		blaze-markup>=0.5.1 conduit>=0.4 lifted-base>=0.1 \
		monad-control>=0.3 path-pieces>=0.1 pool-conduit>=0.1 \
		resourcet>=0.3 text>=0.8 transformers>=0.2.1 transformers-base \
		unordered-containers vector

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
