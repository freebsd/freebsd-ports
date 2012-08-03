# New ports collection makefile for: hs-blaze-builder-conduit
# Date created:        December 30, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	blaze-builder-conduit
PORTVERSION=	0.4.0.2
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Convert streams of builders to streams of bytestrings

LICENSE=	BSD

USE_CABAL=	blaze-builder>=0.2.1.4 conduit>=0.4 text>=0.11 \
		transformers>=0.2.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
