# New ports collection makefile for:	pcre-light
# Date created:				December 16, 2008
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pcre-light
PORTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A lightweight Haskell regex library compatible with Perl 5

LICENSE=	BSD

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
