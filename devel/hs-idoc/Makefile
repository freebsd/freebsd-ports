# New ports collection makefile for:	idoc
# Date created:				25 October 2002
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	idoc
PORTVERSION=	0.2.5
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/idoc/
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A No Frills Haskell Interface Documentation System

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

PLIST_FILES=	bin/idoc
USE_SIZE=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -e 's|^\(PREFIX\)|#\1|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|IOExts|Debug.Trace|' ${WRKSRC}/IDoc.hs

.include <bsd.port.mk>
