# New ports collection makefile for: hs-epic
# Date created:        December 2, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	epic
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	lang haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Compiler for a simple functional language

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	mtl
USE_HAPPY=	yes

BUILD_DEPENDS+=	boehm-gc>=7.1:${PORTSDIR}/devel/boehm-gc \
		gmp>=5.0.2:${PORTSDIR}/math/gmp
RUN_DEPENDS+=	boehm-gc>=7.1:${PORTSDIR}/devel/boehm-gc \
		gmp>=5.0.2:${PORTSDIR}/math/gmp

EXECUTABLE=	epic

post-patch::
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/evm/Makefile

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
