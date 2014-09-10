# $FreeBSD$

PORTNAME=	hspec
PORTVERSION=	1.11.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Behavior-Driven Development for Haskell

LICENSE=	MIT

USE_CABAL=	ansi-terminal>=0.5 async>=2 hspec-expectations>=0.5.0 \
		HUnit>=1.2.5 QuickCheck>=2.5.1 quickcheck-io random \
		setenv tf-random

EXECUTABLE=	hspec-discover

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
