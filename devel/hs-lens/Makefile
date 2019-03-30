# $FreeBSD$

PORTNAME=	lens
PORTVERSION=	4.17
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Lenses, Folds and Traversals

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

BROKEN=		Doesn't build with recent GHC

USE_CABAL=	base-orphans>=0.3 bifunctors>=5 call-stack comonad>=4 \
		contravariant distributive>=0.3 exceptions>=0.1.1 \
		free>=4 hashable>=1.1.2.3 kan-extensions>=4.2.1 mtl>=2.0.1 \
		parallel>=3.1.0.1 profunctors>=5 reflection>=2 \
		semigroupoids>=5 semigroups>=0.8.4 tagged>=0.4.4 \
		th-abstraction transformers-compat>=0.4 unordered-containers>=0.2.4 \
		vector>=0.9 void>=0.5

FLAGS_DISABLE=	test-hlint test-doctests test-hunit test-properties test-templates

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
