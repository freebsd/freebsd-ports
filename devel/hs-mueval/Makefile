# New ports collection makefile for: hs-mueval
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mueval
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Safely evaluate Haskell expressions

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	hint>=0.3.1 show>=0.3 utf8-string

EXECUTABLE=	mueval mueval-core

PORTDATA=	*
SHOW_PKGMSG=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
