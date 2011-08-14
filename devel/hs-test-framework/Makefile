# New ports collection makefile for: hs-test-framework
# Date created:        May 21, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	test-framework
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Framework for running and organising tests

LICENSE=	BSD

USE_CABAL=	ansi-terminal>=0.4 ansi-wl-pprint>=0.5.1 hostname>=1 \
		regex-posix>=0.72 xml>=1.3.5

CONFIGURE_ARGS+=	--flags="-Tests"

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
