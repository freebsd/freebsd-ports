PORTNAME=	mueval
PORTVERSION=	0.9.4
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Safely evaluate pure Haskell expressions
WWW=		https://github.com/gwern/mueval

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ghc-9.4.8:lang/ghc94

USES=		cabal

USE_CABAL=	QuickCheck-2.14.3 \
		extensible-exceptions-0.1.1.4 \
		ghc-paths-0.1.0.12_5 \
		hint-0.9.0.8 \
		random-1.2.1.1_1 \
		show-0.6 \
		simple-reflect-0.3.3 \
		splitmix-0.1.0.5 \
		syb-0.7.2.4 \
		temporary-1.3

.include <bsd.port.mk>
