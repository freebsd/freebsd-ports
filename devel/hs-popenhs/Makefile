# New ports collection makefile for:   popenhs
# Date created:        09 April 2002
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	popenhs
PORTVERSION=	1.00.0
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/~petersen/haskell/popenhs/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A popen-like library for Haskell

BUILD_DEPENDS=	ghc-5.04.3:${PORTSDIR}/lang/ghc5
RUN_DEPENDS=	ghc-5.04.3:${PORTSDIR}/lang/ghc5

USE_GMAKE=	yes
HAS_CONFIGURE=	yes

.include <bsd.port.mk>
