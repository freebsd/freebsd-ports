# New ports collection makefile for:	cpphs
# Date created:		14 June 2004
# Whom:			obraun@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cpphs
PORTVERSION=	1.9
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A simplified re-implementation of cpp in Haskell

CABAL_SETUP=	Setup.hs

MAN1=		cpphs.1
MAN1SRC=	docs

EXECUTABLE=	cpphs

PORTDATA=		*
INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/docs/index.html ${DATADIR} \
			  && ${INSTALL_DATA} ${WRKSRC}/docs/design ${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
