# New ports collection makefile for:	cpphs
# Date created:		14 June 2004
# Whom:			obraun@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cpphs
PORTVERSION=	1.2
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.cs.york.ac.uk/fp/cpphs/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A simplified re-implementation of cpp in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

PLIST_FILES=	bin/cpphs

MAN1=	cpphs.1

do-build:
	@(cd ${WRKSRC} && ghc -o cpphs --make cpphs)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cpphs ${PREFIX}/bin/cpphs
	@${INSTALL_MAN} ${WRKSRC}/docs/cpphs.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
