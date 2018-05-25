# $FreeBSD$

PORTNAME=	mono-traversable
PORTVERSION=	1.0.8.1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Type classes for mapping, folding, and traversing monomorphic containers

LICENSE=	MIT

USE_CABAL=	comonad>=3.0.3 dlist>=0.6 dlist-instances>=0.1 hashable \
		semigroupoids>=3.0 semigroups>=0.10 split \
		unordered-containers>=0.2 vector>=0.10 vector-algorithms>=0.6 \
		vector-instances

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
