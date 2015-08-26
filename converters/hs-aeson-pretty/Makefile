# $FreeBSD$

PORTNAME=	aeson-pretty
PORTVERSION=	0.7.2
CATEGORIES=	converters haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	JSON pretty-printing library and command-line tool

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson>=0.7 attoparsec>=0.10 cmdargs>=0.7 text>=0.11 \
		unordered-containers>=0.1.3.0 vector>=0.9

EXECUTABLE=	aeson-pretty

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
