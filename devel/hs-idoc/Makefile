# New ports collection makefile for:	idoc
# Date created:				25 October 2002
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	idoc
PORTVERSION=	0.2.5
PORTCOMMENT=	A No Frills Haskell Interface Documentation System
CATEGORIES=	devel
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/idoc/
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

USE_REINPLACE=	yes
USE_GMAKE=	yes

ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -e 's|^\(PREFIX\)|#\1|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|IOExts|Debug.Trace|' ${WRKSRC}/IDoc.hs

.include <bsd.port.mk>
