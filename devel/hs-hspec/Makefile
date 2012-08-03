# New ports collection makefile for: hs-hspec
# Date created:        June 10, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hspec
PORTVERSION=	1.2.0.1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Behavior Driven Development for Haskell

LICENSE=	BSD

USE_CABAL=	ansi-terminal==0.5.5_4 HUnit>=1 QuickCheck>=2.4.0.1 \
		silently>=1.1.1 transformers>=0.2.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
