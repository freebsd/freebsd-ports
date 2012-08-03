# New ports collection makefile for: hs-ansi-terminal
# Date created:        May 21, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ansi-terminal
PORTVERSION=	0.5.5
PORTREVISION=	4
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Simple ANSI terminal support, with Windows compatibility

LICENSE=	BSD

CONFIGURE_ARGS+=	--flags="-Example"

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
