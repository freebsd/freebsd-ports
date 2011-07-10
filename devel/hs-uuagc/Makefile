# New ports collection makefile for: hs-uuagc
# Date created:        February 27 2008
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	uuagc
PORTVERSION=	0.9.38.5
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Attribute Grammar System of Universiteit Utrecht

LICENSE=	GPLv2

CABAL_SETUP=	Setup.hs
USE_CABAL=	haskell-src-exts>=1.11.1 mtl>=1.1.1.1 uulib>=0.9.12

EXECUTABLE=	uuagc
HADDOCK_EXE=

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
