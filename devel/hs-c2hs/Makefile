# New ports collection makefile for:   c2hs
# Date created:        23 August 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c2hs
PORTVERSION=	0.10.15
CATEGORIES=	devel
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/c2hs/

MAINTAINER=	obraun@FreeBSD.org

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX} --enable-add-package

.include <bsd.port.mk>
