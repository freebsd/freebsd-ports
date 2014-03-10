# $FreeBSD$

PORTNAME=	hspec
PORTVERSION=	1.5.4
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Behavior-Driven Development for Haskell

LICENSE=	BSD

USE_CABAL=	ansi-terminal>=0.5 hspec-expectations HUnit>=1.2.5 \
		QuickCheck>=2.5.1 quickcheck-io random setenv \
		transformers>=0.2.2.0

EXECUTABLE=	hspec-discover

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
