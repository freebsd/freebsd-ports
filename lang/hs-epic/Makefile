# $FreeBSD$

PORTNAME=	epic
PORTVERSION=	0.9.3
PORTREVISION=	10
CATEGORIES=	lang haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Compiler for a simple functional language

LICENSE=	BSD3CLAUSE

USE_CABAL=	mtl
USE_HAPPY=	yes

BUILD_DEPENDS+=	boehm-gc>=7.1:${PORTSDIR}/devel/boehm-gc \
		gmp>=5.0.2:${PORTSDIR}/math/gmp
RUN_DEPENDS+=	boehm-gc>=7.1:${PORTSDIR}/devel/boehm-gc \
		gmp>=5.0.2:${PORTSDIR}/math/gmp

EXECUTABLE=	epic

# Force regeneration of the parser.
post-patch::
	@${RM} -rf ${WRKSRC}/dist
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/evm/Makefile

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
