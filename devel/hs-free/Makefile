# $FreeBSD$

PORTNAME=	free
PORTVERSION=	5.0.1
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Monads for free

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	bifunctors>=4 comonad>=4 distributive>=0.2.1 exceptions>=0.6 \
		mtl>=2.0.1.0 prelude-extras>=0.4 profunctors>=4 \
		semigroupoids>=4 semigroups>=0.8.3.1 transformers-base

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
