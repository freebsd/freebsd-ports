# New ports collection makefile for: hs-system-fileio
# Date created:        June 10, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	system-fileio
PORTVERSION=	0.3.8
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Consistent filesystem interaction across GHC versions

LICENSE=	MIT
FILE_LICENSE=	license.txt

CABAL_SETUP=	Setup.hs

USE_CABAL=	system-filepath>=0.3.1 text>=0.7.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
