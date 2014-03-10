# $FreeBSD$

PORTNAME=	lens
PORTVERSION=	3.9.0.2
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Lenses, Folds and Traversals

LICENSE=	BSD

USE_CABAL=	bifunctors>=3 comonad>=3 comonad-transformers>=3 \
		comonads-fd>=3 contravariant>=0.2.0.2 distributive>=0.3 \
		generic-deriving hashable>=1.1.2.3 \
		MonadCatchIO-transformers>=0.3 mtl>=2.0.1 parallel>=3.1.0.1 \
		profunctor-extras>=3.3 profunctors>=3.2 reflection>=1.1.6 \
		semigroupoids>=3 semigroups>=0.8.4 split tagged>=0.4.4 \
		text>=0.11 transformers>=0.3 unordered-containers>=0.2 \
		vector>=0.9 void>=0.5

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
