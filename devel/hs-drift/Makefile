# New ports collection makefile for:	drift
# Date created:				13 August 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	drift
PORTVERSION=	2.0.r3
CATEGORIES=	devel
MASTER_SITES=	http://repetae.net/john/computer/haskell/DrIFT/
DISTNAME=	DrIFT-${PORTVERSION:S/.r/rc/}
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org

.if !defined(WITH_GHC)
BUILD_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
.else
BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
.endif

HAS_CONFIGURE=	yes

.if !defined(WITH_GHC)
CONFIGURE_ARGS+=	--with-hc=nhc98
.else
CONFIGURE_ARGS+=	--with-hc=ghc
.endif

.if !defined(WITH_GHC)
pre-everything:
	@${ECHO} ""
	@${ECHO} " DrIFT will be build with nhc98."
	@${ECHO} " Define WITH_GHC to build with ghc."
	@${ECHO} ""
.endif

.include <bsd.port.mk>
