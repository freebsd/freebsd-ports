# $FreeBSD$

PORTNAME=	aeson-compat
PORTVERSION=	0.3.7.1
CATEGORIES=	converters haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Fast JSON parsing and encoding

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson attoparsec attoparsec-iso8601 base-compat exceptions \
		hashable scientific semigroups tagged time-locale-compat \
		unordered-containers vector

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
