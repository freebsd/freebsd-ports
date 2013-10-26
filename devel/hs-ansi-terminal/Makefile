# $FreeBSD$

PORTNAME=	ansi-terminal
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Simple ANSI terminal support, with Windows compatibility

LICENSE=	BSD

CONFIGURE_ARGS+=	--flags="-Example"

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
