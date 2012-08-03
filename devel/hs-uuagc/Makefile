# New ports collection makefile for: hs-uuagc
# Date created:        February 27 2008
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	uuagc
PORTVERSION=	0.9.40.3
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Attribute Grammar System of Universiteit Utrecht

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	haskell-src-exts>=1.11.1 mtl>=1.1.1.1 uuagc-bootstrap>=0.9.40.0 \
		uuagc-cabal>=1.0.2.0 uulib>=0.9.14

EXECUTABLE=	uuagc

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
