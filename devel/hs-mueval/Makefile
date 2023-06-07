PORTNAME=	mueval
PORTVERSION=	0.9.3
PORTREVISION=	13
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Safely evaluate pure Haskell expressions
WWW=		https://github.com/gwern/mueval

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ghc-9.2.8:lang/ghc92

USES=		cabal

USE_CABAL=	QuickCheck-2.14.2 \
		extensible-exceptions-0.1.1.4 \
		ghc-paths-0.1.0.12_4 \
		hint-0.9.0.6 \
		random-1.2.1.1 \
		show-0.6 \
		simple-reflect-0.3.3 \
		splitmix-0.1.0.4_1 \
		syb-0.7.2.2 \
		temporary-1.3

CABAL_EXECUTABLES=	mueval mueval-core

.include <bsd.port.mk>
