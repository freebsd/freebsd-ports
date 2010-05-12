# New ports collection makefile for: hs-OpenAL
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	OpenAL
PORTVERSION=	1.4.0.0
PORTREVISION=	1
CATEGORIES=	audio haskell

MAINTAINER=	jacula@gmail.com
COMMENT=	A Haskell binding to the OpenAL cross-platform 3D audio API

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	ObjectName StateVar Tensor
USE_OPENAL=	al

PORTEXAMPLES=		*
INSTALL_PORTEXAMPLES=	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
