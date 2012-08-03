# New ports collection makefile for:	hs-hastache
# Date created:		December 2, 2011
# Whom:			haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hastache
PORTVERSION=	0.4.1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell implementation of Mustache templates

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	blaze-builder ieee754 mtl syb text utf8-string

INSTALL_PORTDATA=	cd ${WRKSRC} && ${INSTALL_DATA} README.md ${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
