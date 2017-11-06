# $FreeBSD$

PORTNAME=	hastache
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell implementation of Mustache templates

LICENSE=	BSD3CLAUSE

USE_CABAL=	blaze-builder ieee754 mtl syb text

EXECUTABLE=	mkReadme

INSTALL_PORTDATA=	cd ${WRKSRC} && ${INSTALL_DATA} README.md ${STAGEDIR}${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
