PORTNAME=	dhall-yaml
DISTVERSION=	1.2.12
PORTREVISION=	2
CATEGORIES=	converters lang haskell

MAINTAINER=	malcolm.matalka@acsl.se
COMMENT=	Compile Dhall expressions to YAML
WWW=		https://dhall-lang.org/ \
		https://hackage.haskell.org/package/dhall-yaml

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ghc-9.6.7:lang/ghc96

USES=		cabal

CABAL_PROJECT=		remove
CABAL_EXECUTABLES=	dhall-to-yaml-ng yaml-to-dhall
CABAL_REVISION=		5

.include <bsd.port.mk>
