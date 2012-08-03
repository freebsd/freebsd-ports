# New ports collection makefile for: hs-filesystem-conduit
# Date created:        June 10, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	filesystem-conduit
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Use system-filepath data types with conduits

LICENSE=	BSD

USE_CABAL=	conduit>=0.4 system-fileio>=0.3.3 system-filepath>=0.4.3 \
		text>=0.11 transformers>=0.2.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
