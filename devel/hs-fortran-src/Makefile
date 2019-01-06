# $FreeBSD$

PORTNAME=	fortran-src
DISTVERSION=	0.2.1.1
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	hello@blubee.me
COMMENT=	Parser and analyses for Fortran standard 66, 77, 90 & 95

LICENSE=	APACHE20

BROKEN=		Doesn't build with newest GHC

USE_CABAL=	fgl>=5.0 GenericPretty>=1.2.2 uniplate>=1.6 alex>=3.1 \
		happy>=1.19 unordered-containers>=0.2.9.0 syb>=0.7 \
		hashable>=1.2.3.0

EXECUTABLE=	fortran-src

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
