# $FreeBSD$

PORTNAME=	abstract-deque
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Abstract, parameterized interface to mutable Deques

LICENSE=	BSD

USE_CABAL=	HUnit random

OPTIONS_DEFINE=	USECAS

USECAS_DESC=	Use hardware compare-and-swap

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MUSECAS}
CONFIGURE_ARGS+=	--flags="useCAS"
USE_CABAL+=		IORefCas>=0.2
.else
CONFIGURE_ARGS+=	--flags="-useCAS"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
