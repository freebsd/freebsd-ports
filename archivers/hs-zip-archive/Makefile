# New ports collection makefile for:	zip-archive
# Date created:				December 15, 2008
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zip-archive
PORTVERSION=	0.1.1.7
PORTREVISION=	2
CATEGORIES=	archivers haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell library for working with zip archives

LICENSE=	GPLv2

USE_CABAL=	binary digest>=0.0.0.1 mtl utf8-string>=0.3.1 zlib

OPTIONS=	EXECUTABLE "Build the Zip executable" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_EXECUTABLE)
CONFIGURE_ARGS+=	--flags="executable"
EXECUTABLE=		Zip
PLIST_SUB+=		MAYBE_EXECUTABLE=""
.else
CONFIGURE_ARGS+=	--flags="-executable"
PLIST_SUB+=		MAYBE_EXECUTABLE="@comment "
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
