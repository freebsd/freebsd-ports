# New ports collection makefile for:	bnfc
# Date created:		2007-02-11
# Whom:			Kai Wang <kaiw27@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	BNFC
PORTVERSION=	2.4.2.0
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	kaiw27@gmail.com
COMMENT=	A Labelled BNF converter

LICENSE=	GPLv2
FILE_LICENSE=	COPYING

USE_CABAL=	mtl

STANDALONE=	yes
EXECUTABLE=	bnfc

HASKELL98=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
