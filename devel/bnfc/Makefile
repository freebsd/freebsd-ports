# New ports collection makefile for:	bnfc
# Date created:		2007-02-11
# Whom:			Kai Wang <kaiw27@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bnfc
PORTVERSION=	2.4b
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.chalmers.se/Cs/Research/Language-technology/BNFC/download/ \
		http://web.student.chalmers.se/~kaiw/FreeBSD/disfiles/
DISTNAME=	BNFC-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kaiw27@gmail.com
COMMENT=	A Labelled BNF converter

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

WRKSRC=		${WRKDIR}/BNFC
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bnfc ${PREFIX}/bin

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
