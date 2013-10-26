# $FreeBSD$

PORTNAME=	zip-archive
PORTVERSION=	0.1.3.4
PORTREVISION=	2
CATEGORIES=	archivers haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Library for creating and modifying zip archives

LICENSE=	BSD

USE_CABAL=	digest>=0.0.0.1 mtl utf8-string>=0.3.1 zlib
NO_STAGE=	yes

OPTIONS_DEFINE=		EXECUTABLE

EXECUTABLE_DESC=	Build the Zip executable

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MEXECUTABLE}
CONFIGURE_ARGS+=	--flags="executable"
EXECUTABLE=		Zip
.else
CONFIGURE_ARGS+=	--flags="-executable"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
