# New ports collection makefile for: hs-curl
# Date created:        May 14, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	1.3.5
CATEGORIES=	ftp haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell binding to libcurl

CABAL_SETUP=	Setup.hs

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
