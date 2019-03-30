# $FreeBSD$

PORTNAME=	dns
PORTVERSION=	3.0.2
PORTREVISION=	2
CATEGORIES=	dns haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	DNS library in Haskell

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	attoparsec auto-update base64-bytestring blaze-builder \
		conduit>=1.1 conduit-extra>=1.1 cryptonite iproute>=1.2.4 \
		mtl network>=2.3 psqueues random resourcet safe

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
