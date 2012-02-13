# New ports collection makefile for: hs-libmpd
# Date created:        May 16, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmpd
PORTVERSION=	0.7.0
CATEGORIES=	audio haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	An MPD client library

LICENSE=	LGPL21

USE_CABAL=	mtl>=2.0 network>=2.1 utf8-string>=0.3.1

CONFIGURE_ARGS+=	--flags="-test -coverage"

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
