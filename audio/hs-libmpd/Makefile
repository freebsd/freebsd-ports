# New ports collection makefile for: hs-libmpd
# Date created:        May 16, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmpd
PORTVERSION=	0.4.1
CATEGORIES=	audio haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	An MPD client library

USE_HACKAGE=	utf8-string>=0.3.1 QuickCheck>=2.1.0.0

CONFIGURE_ARGS+=	--flags="-test -coverage"

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
