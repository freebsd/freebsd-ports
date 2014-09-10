# $FreeBSD$

PORTNAME=	conduit-combinators
PORTVERSION=	0.2.8.2
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Commonly used conduit functions, for both chunked and unchunked data

LICENSE=	MIT

USE_CABAL=	base16-bytestring base64-bytestring>=0.1.1.1 chunked-data \
		conduit>=1.0.12 conduit-extra monad-control \
		mono-traversable>=0.4 mwc-random primitive resourcet \
		streaming-commons system-fileio system-filepath text \
		transformers-base unix-compat vector void

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
