# New ports collection makefile for:	drift
# Date created:				13 August 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	drift
PORTVERSION=	2.0.3
CATEGORIES=	devel haskell
MASTER_SITES=	http://repetae.net/john/computer/haskell/DrIFT/drop/
PKGNAMEPREFIX=	hs-
DISTNAME=	DrIFT-${PORTVERSION}

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A type sensitive preprocessor for Haskell

.if !defined(WITH_NHC98)
BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
.else
BUILD_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
.endif

USE_SIZE=	yes
HAS_CONFIGURE=	yes

INFO=	drift

.if !defined(WITH_NHC98)
CONFIGURE_ARGS+=	--with-hc=ghc
.else
CONFIGURE_ARGS+=	--with-hc=nhc98
.endif

.if !defined(WITH_GHC)
pre-everything::
	@${ECHO} ""
	@${ECHO} " DrIFT will be build with ghc"
	@${ECHO} " Define WITH_NHC98 to build with nhc98."
	@${ECHO} ""
.endif

.include <bsd.port.mk>
