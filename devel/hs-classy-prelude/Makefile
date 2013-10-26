# $FreeBSD$

PORTNAME=	classy-prelude
PORTVERSION=	0.5.7
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Typeclass-based Prelude

LICENSE=	MIT

USE_CABAL=	basic-prelude>=0.3.4 hashable lifted-base>=0.2 \
		system-filepath>=0.4 text transformers unordered-containers \
		vector

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
