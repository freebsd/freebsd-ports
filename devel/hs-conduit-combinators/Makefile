# $FreeBSD$

PORTNAME=	conduit-combinators
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Commonly used conduit functions, for both chunked and unchunked data

LICENSE=	MIT

USE_CABAL=	base16-bytestring base64-bytestring>=0.1.1.1 chunked-data \
		conduit>=1.2.2 conduit-extra>=1.1.1 monad-control \
		mono-traversable>=0.4 mwc-random primitive resourcet \
		transformers-base unix-compat vector void

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
