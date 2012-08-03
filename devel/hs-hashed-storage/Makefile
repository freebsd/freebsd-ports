# New ports collection makefile for: hs-hashed-storage
# Date created:        May 14, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hashed-storage
PORTVERSION=	0.5.9
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Hashed file storage support code

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	dataenc mmap>=0.5 mtl zlib

CONFIGURE_ARGS+=	--flags="-test"

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
