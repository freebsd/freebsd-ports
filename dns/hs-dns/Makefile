# $FreeBSD$

PORTNAME=	dns
PORTVERSION=	3.0.2
CATEGORIES=	dns haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	DNS library in Haskell

LICENSE=	BSD3CLAUSE

USE_CABAL=	attoparsec auto-update base64-bytestring blaze-builder \
		conduit>=1.1 conduit-extra>=1.1 cryptonite iproute>=1.2.4 \
		mtl network>=2.3 psqueues random resourcet safe

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
