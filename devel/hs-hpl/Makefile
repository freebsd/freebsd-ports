# New ports collection makefile for:   hpl
# Date created:        23 August 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hpl
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/ports/
PKGNAMEPREFIX=	hs-
DISTNAME=	ports-${PORTVERSION}

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Haskell Ports Library provides ports in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include <bsd.port.mk>
