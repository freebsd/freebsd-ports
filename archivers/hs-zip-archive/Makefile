# New ports collection makefile for:	zip-archive
# Date created:				December 15, 2008
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zip-archive
PORTVERSION=	0.1.1.8
PORTREVISION=	1
CATEGORIES=	archivers haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Library for creating and modifying zip archives

LICENSE=	BSD

USE_CABAL=	digest>=0.0.0.1 mtl utf8-string>=0.3.1 zlib

OPTIONS_DEFINE=		EXECUTABLE

EXECUTABLE_DESC=	Build the Zip executable

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXECUTABLE}
CONFIGURE_ARGS+=	--flags="executable"
EXECUTABLE=		Zip
.else
CONFIGURE_ARGS+=	--flags="-executable"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
