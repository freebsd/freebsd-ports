# $FreeBSD$

PORTNAME=	hlint
PORTVERSION=	2.0.9
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Source code suggestions

LICENSE=	BSD3CLAUSE

USE_CABAL=	ansi-terminal>=0.6.2 cmdargs>=0.10 cpphs>=1.18.1 extra>=0.5 \
		haskell-src-exts>=1.16 hscolour>=1.21 refact uniplate>=1.5 yaml

EXECUTABLE=	hlint

IGNORE=		Doesn't build with recent GHC version

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
