# New ports collection makefile for:   green-card
# Date created:        01 June 2002
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	green-card
PORTVERSION=	2.05
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.galois.com/~sof/
PKGNAMEPREFIX=	hs-
DISTNAME=	gc-${PORTVERSION}-src

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A foreign function interface preprocessor for Haskell

BUILD_DEPENDS=	ghc-5.04.3:${PORTSDIR}/lang/ghc5

WRKSRC=		${WRKDIR}/gc-${PORTVERSION}

USE_SIZE=	yes
USE_GMAKE=	yes
ALL_TARGET=	all

do-install:
	@(cd ${WRKSRC}/src && ${CP} green-card ${PREFIX}/bin)
	-@mkdir ${PREFIX}/lib/green-card
	@(cd ${WRKSRC}/lib/ghc && ${CP} StdDIS.* libHSgreencard.a ${PREFIX}/lib/green-card)
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}/doc && ${CP} -R green-card ${PREFIX}/share/doc \
	  && ${CP} green-card.dvi.gz green-card.ps.gz ${DOCSDIR})
.endif

.include <bsd.port.mk>
