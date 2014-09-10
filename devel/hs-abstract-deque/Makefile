# $FreeBSD$

PORTNAME=	abstract-deque
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Abstract, parameterized interface to mutable Deques

LICENSE=	BSD3CLAUSE

USE_CABAL=	random

FLAGS_DEFINE=	USECAS

USECAS_DESC=		Use hardware compare-and-swap
USECAS_FLAG_ENABLE=	useCAS
USECAS_FLAG_CABAL=	atomic-primops>=0.5.0.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
