# New ports collection makefile for: hs-MissingH
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	MissingH
PORTVERSION=	1.1.1.0
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Large Haskell utility library

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	hslogger HUnit mtl network parsec random regex-compat

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
