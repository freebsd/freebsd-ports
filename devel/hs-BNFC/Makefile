# Created by: Kai Wang <kaiw27@gmail.com>
# $FreeBSD$

PORTNAME=	BNFC
PORTVERSION=	2.6.0.3
PORTREVISION=	8
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Compiler front-end generator

LICENSE=	GPLv2

USE_CABAL=	mtl
USE_ALEX=	yes
USE_HAPPY=	yes

EXECUTABLE=	bnfc

# Force regeneration of the lexer and parser.
post-patch::
	@${RM} -rf ${WRKSRC}/dist

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
