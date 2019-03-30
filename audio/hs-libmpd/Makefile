# $FreeBSD$

PORTNAME=	libmpd
PORTVERSION=	0.9.0.9
PORTREVISION=	1
CATEGORIES=	audio haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	MPD client library

LICENSE=	MIT

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	attoparsec>=0.10.1 data-default-class>=0.0.1 mtl>=2.0 \
		network>=2.1 old-locale>=1.0 utf8-string>=0.3.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
