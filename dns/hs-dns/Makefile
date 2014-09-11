# $FreeBSD$

PORTNAME=	dns
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	dns haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	DNS library in Haskell

LICENSE=	BSD3CLAUSE

USE_CABAL=	attoparsec blaze-builder conduit>=1.1 conduit-extra>=1.1 \
		iproute>=1.2.4 mtl network>=2.3 random resourcet

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
