# $FreeBSD$

PORTNAME=	persistent
PORTVERSION=	2.9.0
PORTREVISION=	1
CATEGORIES=	databases haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Type-safe, multi-backend data serialization

LICENSE=	MIT

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	aeson>=0.5 attoparsec base64-bytestring blaze-html>=0.5 \
		blaze-markup>=0.5.1 conduit>=1.0 exceptions>=0.6 \
		fast-logger>=2.1 haskell-src-meta http-api-data lifted-base \
		monad-control>=0.3 monad-logger>=0.3 mtl old-locale \
		path-pieces>=0.1 resource-pool resourcet>=1.1 scientific \
		silently tagged transformers-base unordered-containers vector

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
