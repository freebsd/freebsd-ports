# $FreeBSD$

PORTNAME=	lens
PORTVERSION=	4.15.3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Lenses, Folds and Traversals

LICENSE=	BSD3CLAUSE

USE_CABAL=	base-orphans>=0.3 bifunctors>=5 comonad>=4 \
		contravariant>=0.3 distributive>=0.3 exceptions>=0.1.1 \
		free>=4 hashable>=1.1.2.3 kan-extensions>=4.2.1 mtl>=2.0.1 \
		parallel>=3.1.0.1 profunctors>=5 reflection>=2 \
		semigroupoids>=5 semigroups>=0.8.4 tagged>=0.4.4 text>=0.11 \
		th-abstraction transformers-compat>=0.4 unordered-containers>=0.2.4 \
		vector>=0.9 void>=0.5

FLAGS_DISABLE=	test-hlint test-doctests test-hunit test-properties test-templates

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
