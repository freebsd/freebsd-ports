# New ports collection makefile for: hs-persistent-sqlite
# Date created:        June 10, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	persistent-sqlite
PORTVERSION=	0.9.0.2
PORTREVISION=	1
CATEGORIES=	databases haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Backend for the persistent library using sqlite3

LICENSE=	MIT

USE_CABAL=	aeson>=0.5 conduit>=0.4 monad-control>=0.2 persistent>=0.9 \
		text>=0.7 transformers>=0.2.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
