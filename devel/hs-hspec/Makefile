# $FreeBSD$

PORTNAME=	hspec
PORTVERSION=	2.5.0
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Testing Framework for Haskell

LICENSE=	MIT

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	hspec-core>=2.1.10 hspec-discover>=2.1.10 \
		hspec-expectations>=0.7.1 HUnit>=1.2.5 QuickCheck>=2.5.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
