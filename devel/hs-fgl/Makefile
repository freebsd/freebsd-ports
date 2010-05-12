# New ports collection makefile for: hs-fgl
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fgl
PORTVERSION=	5.4.2.2
CATEGORIES=	devel haskell

MAINTAINER=	jacula@gmail.com
COMMENT=	Martin Erwig Functional Graph Library

CABAL_SETUP=	Setup.hs

PORTDATA=		*
INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/doc/CHANGES ${DATADIR} \
			  && ${INSTALL_DATA} ${WRKSRC}/doc/README ${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
