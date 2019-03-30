# $FreeBSD$

PORTNAME=	gnuidn
PORTVERSION=	0.2.2
PORTREVISION=	4
CATEGORIES=	dns haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Bindings for GNU IDN

LICENSE=	GPLv3

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_C2HS=	yes

USES=		pkgconfig
LIB_DEPENDS=	libidn.so:dns/libidn

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
