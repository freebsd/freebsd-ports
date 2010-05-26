# New ports collection makefile for: hs-ALUT
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ALUT
PORTVERSION=	2.2.0.0
PORTREVISION=	1
CATEGORIES=	audio haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell binding for the OpenAL Utility Toolkit

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	OpenAL StateVar
USE_OPENAL=	al alut

PORTEXAMPLES=		*
INSTALL_PORTEXAMPLES=	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
