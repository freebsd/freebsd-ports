# $FreeBSD$

PORTNAME=	uuagc-bootstrap
PORTVERSION=	0.9.40.2
PORTREVISION=	18
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Attribute Grammar System of Universiteit Utrecht

LICENSE=	BSD3CLAUSE

DEPRECATED=	No release since 2011
BROKEN=		Doesn't build with newest GHC
EXPIRATION_DATE=	2019-01-31

USE_CABAL=	haskell-src-exts>=1.11.1 mtl>=1.1.1.1 uulib>=0.9.14

EXECUTABLE=	uuagc-bootstrap

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
