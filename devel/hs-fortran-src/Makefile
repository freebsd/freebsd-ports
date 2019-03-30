# $FreeBSD$

PORTNAME=	fortran-src
DISTVERSION=	0.2.1.1
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	hello@blubee.me
COMMENT=	Parser and analyses for Fortran standard 66, 77, 90 & 95

LICENSE=	APACHE20

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

BROKEN=		Doesn't build with newest GHC

USE_CABAL=	fgl>=5.0 GenericPretty>=1.2.2 uniplate>=1.6 alex>=3.1 \
		happy>=1.19 unordered-containers>=0.2.9.0 syb>=0.7 \
		hashable>=1.2.3.0

EXECUTABLE=	fortran-src

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
