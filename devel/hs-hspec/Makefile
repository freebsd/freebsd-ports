# $FreeBSD$

PORTNAME=	hspec
PORTVERSION=	1.4.2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Behavior Driven Development for Haskell

LICENSE=	BSD

USE_CABAL=	ansi-terminal==0.5.5_5 hspec-expectations HUnit>=1.2.5 \
		QuickCheck>=2.4.0.1 setenv silently>=1.1.1 transformers>=0.2.0

EXECUTABLE=	hspec-discover

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
