# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	OpenAL
PORTVERSION=	1.6.0.0
PORTREVISION=	1
CATEGORIES=	audio haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the OpenAL cross-platform 3D audio API

LICENSE=	BSD3CLAUSE

USE_CABAL=	OpenGL>=2.9.0.0
USES=		openal:al

INSTALL_PORTEXAMPLES=	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
