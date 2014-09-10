# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	1.3.8
PORTREVISION=	9
CATEGORIES=	ftp haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell binding to libcurl

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USE_GHC_NATIVE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
