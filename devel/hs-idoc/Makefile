# New ports collection makefile for:	idoc
# Date created:				25 October 2002
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	idoc
PORTVERSION=	0.2.6
PORTREVISION=	3
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/idoc/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A No Frills Haskell Interface Documentation System

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4

PLIST_FILES=	bin/idoc
USE_GMAKE=	yes
MAKE_ARGS=	PREFIX="${PREFIX}"

ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -e 's|IOExts|Debug.Trace|' ${WRKSRC}/IDoc.hs

.include <bsd.port.mk>
