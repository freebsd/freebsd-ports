# New ports collection makefile for:   green-card
# Date created:        01 June 2002
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	green-card
PORTVERSION=	2.04
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.galois.com/~sof/
DISTNAME=	gc-${PORTVERSION}
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

WRKSRC=		${WRKDIR}/gc-${PORTVERSION}

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
