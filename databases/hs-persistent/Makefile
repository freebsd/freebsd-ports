# $FreeBSD$

PORTNAME=	persistent
PORTVERSION=	2.8.2
CATEGORIES=	databases haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Type-safe, multi-backend data serialization

LICENSE=	MIT

USE_CABAL=	aeson>=0.5 attoparsec base64-bytestring blaze-html>=0.5 \
		blaze-markup>=0.5.1 conduit>=1.0 exceptions>=0.6 \
		fast-logger>=2.1 haskell-src-meta http-api-data lifted-base \
		monad-control>=0.3 monad-logger>=0.3 mtl old-locale \
		path-pieces>=0.1 resource-pool resourcet>=1.1 scientific \
		silently tagged transformers-base unordered-containers vector

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
