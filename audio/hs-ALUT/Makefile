# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	ALUT
PORTVERSION=	2.2.0.0
PORTREVISION=	8
CATEGORIES=	audio haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell binding for the OpenAL Utility Toolkit

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	OpenAL StateVar
USE_OPENAL=	al alut

INSTALL_PORTEXAMPLES=	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
