# $FreeBSD$

PORTNAME=	aeson
PORTVERSION=	1.3.1.0
PORTREVISION=	2
CATEGORIES=	converters haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Fast JSON parsing and encoding

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	attoparsec>=0.13.0.1 base-compat>=0.9.1 dlist>=0.6 hashable>=1.1.2.0 \
		scientific>=0.3.1 tagged  th-abstraction time-locale-compat>=0.1.1 \
		unordered-containers>=0.2.3.0 uuid-types>=1.0.3  vector>=0.8

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
