# New ports collection makefile for: hs-ansi-terminal
# Date created:        May 21, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ansi-terminal
PORTVERSION=	0.5.5
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Simple ANSI terminal support, with Windows compatibility

OPTIONS=	EXAMPLE "Build the example application" off

LICENSE=	BSD

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_EXAMPLE)
CONFIGURE_ARGS+=	--flags="Example"
EXECUTABLE=		ansi-terminal-example
.else
CONFIGURE_ARGS+=	--flags="-Example"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
