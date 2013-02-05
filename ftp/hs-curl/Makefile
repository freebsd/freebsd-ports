# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	1.3.8
PORTREVISION=	1
CATEGORIES=	ftp haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell binding to libcurl

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_GHC_NATIVE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
