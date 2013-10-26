# $FreeBSD$

PORTNAME=	hastache
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell implementation of Mustache templates

LICENSE=	BSD

USE_CABAL=	blaze-builder ieee754 mtl syb text transformers utf8-string

INSTALL_PORTDATA=	cd ${WRKSRC} && ${INSTALL_DATA} README.md ${DATADIR}

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
