# New ports collection makefile for:	cpphs
# Date created:		14 June 2004
# Whom:			obraun@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cpphs
PORTVERSION=	0.6
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.cs.york.ac.uk/fp/cpphs/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A simplified re-implementation of cpp in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

PLIST_FILES=	bin/cpphs

do-build:
	@(cd ${WRKSRC} && ghc -o cpphs --make Main)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cpphs ${PREFIX}/bin/cpphs

.include <bsd.port.mk>
