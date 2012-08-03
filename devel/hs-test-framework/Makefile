# New ports collection makefile for: hs-test-framework
# Date created:        May 21, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	test-framework
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Framework for running and organising tests, with HUnit and QuickCheck support

LICENSE=	BSD

USE_CABAL=	ansi-terminal>=0.4.0 ansi-wl-pprint>=0.5.1 hostname>=1.0 \
		random>=1.0 regex-posix>=0.72 xml>=1.3.5

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
