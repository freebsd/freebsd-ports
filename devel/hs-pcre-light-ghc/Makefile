# New ports collection makefile for:	pcre-light
# Date created:				December 16, 2008
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pcre-light
PORTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	devel haskell
PKGNAMESUFFIX=	-ghc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A lightweight Haskell regex library compatible with Perl 5

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
