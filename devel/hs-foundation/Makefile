# $FreeBSD$

PORTNAME=	foundation
PORTVERSION=	0.0.21
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A custom prelude with no dependencies apart from base

LICENSE=	BSD3CLAUSE

USE_CABAL=	basement

post-extract:
	${ECHO} "import Distribution.Simple" > ${WRKSRC}/Setup.hs
	${ECHO} "main = defaultMain" >>  ${WRKSRC}/Setup.hs

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
