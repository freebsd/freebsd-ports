# $FreeBSD$

PORTNAME=	classy-prelude-conduit
PORTVERSION=	0.4.3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conduit instances for classy-prelude

LICENSE=	MIT

CABAL_SETUP=	Setup.hs

USE_CABAL=	classy-prelude>=0.4.3 conduit>=0.5.4.1 monad-control \
		resourcet transformers void xml-conduit>=1.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
