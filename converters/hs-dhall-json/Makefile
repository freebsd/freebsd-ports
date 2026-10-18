PORTNAME=	dhall-json
DISTVERSION=	1.7.12
PORTREVISION=	2
CATEGORIES=	converters lang haskell

MAINTAINER=	malcolm.matalka@acsl.se
COMMENT=	Compile Dhall expressions to JSON
WWW=		https://dhall-lang.org/ \
		https://hackage.haskell.org/package/dhall-json

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ghc-9.6.7:lang/ghc96

USES=		cabal

CABAL_PROJECT=		remove
CABAL_EXECUTABLES=	dhall-to-json json-to-dhall
CABAL_REVISION=		4

.include <bsd.port.mk>
