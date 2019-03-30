# $FreeBSD$

PORTNAME=	esqueleto
PORTVERSION=	2.5.3
PORTREVISION=	4
CATEGORIES=	databases haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Type-safe EDSL for SQL queries on persistent backends

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	blaze-html conduit monad-logger persistent \
		resourcet tagged unordered-containers

IGNORE=		Doesn't build with recent Persistent

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
