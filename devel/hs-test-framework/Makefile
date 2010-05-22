# New ports collection makefile for: hs-test-framework
# Date created:        May 21, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	test-framework
PORTVERSION=	0.3.1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Framework for running and organising tests

USE_HACKAGE=	ansi-terminal>=0.4.0 ansi-wl-pprint>=0.5.1 hostname>=1.0 xml>=1.3.5

CONFIGURE_ARGS+=	--flags="-Tests"

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
