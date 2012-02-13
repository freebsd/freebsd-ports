# New ports collection makefile for: hs-ansi-wl-pprint
# Date created:        May 21, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ansi-wl-pprint
PORTVERSION=	0.6.4
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	The Wadler/Leijen Pretty Printer for colored ANSI terminal output

LICENSE=	BSD

USE_CABAL=	ansi-terminal>=0.4.0

OPTIONS=	EXAMPLE "Build the example application" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_EXAMPLE)
CONFIGURE_ARGS+=	--flags="Example"
EXECUTABLE=		ansi-wl-pprint-example
.else
CONFIGURE_ARGS+=	--flags="-Example"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
