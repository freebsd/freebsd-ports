# $FreeBSD$

PORTNAME=	basic-prelude
PORTVERSION=	0.3.1.0
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	An enhanced core prelude; a common foundation for alternate preludes

LICENSE=	MIT

CABAL_SETUP=	Setup.hs

USE_CABAL=	hashable ReadArgs>=1.2 system-filepath>=0.4 text \
		transformers unordered-containers vector

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
