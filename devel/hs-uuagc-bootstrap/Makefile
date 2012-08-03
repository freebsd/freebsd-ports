# New ports collection makefile for: hs-uuagc-bootstrap
# Date created:        August 12, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	uuagc-bootstrap
PORTVERSION=	0.9.40.2
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Attribute Grammar System of Universiteit Utrecht

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	haskell-src-exts>=1.11.1 mtl>=1.1.1.1 uulib>=0.9.14

EXECUTABLE=	uuagc-bootstrap

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
