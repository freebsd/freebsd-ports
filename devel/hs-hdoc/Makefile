# New ports collection makefile for:	hdoc
# Date created:				25 October 2002
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	hdoc
PORTVERSION=	0.8.2
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.fmi.uni-passau.de/~groessli/hdoc/
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	HTML documentation tool for Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

USE_SIZE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
ALL_TARGET=	# empty

.include <bsd.port.mk>
