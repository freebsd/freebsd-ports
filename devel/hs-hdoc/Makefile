# New ports collection makefile for:	hdoc
# Date created:				25 October 2002
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	hdoc
PORTVERSION=	0.8.3
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.fmi.uni-passau.de/~groessli/hdoc/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	HTML documentation tool for Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

BROKEN=	does not fetch, ${MASTER_SITES} is gone
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2007-06-08

PLIST_FILES=	bin/hdoc
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
ALL_TARGET=	# empty

.include <bsd.port.mk>
