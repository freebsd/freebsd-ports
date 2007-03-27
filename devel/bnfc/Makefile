# New ports collection makefile for:	bnfc
# Date created:		2007-02-11
# Whom:			Kai Wang <kaiw27@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bnfc
PORTVERSION=	2.3b
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.chalmers.se/~markus/BNFC/ \
		http://www.cs.chalmers.se/Cs/Grundutb/Kurser/komp/current/resources/
DISTNAME=	BNFC_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kaiw27@gmail.com
COMMENT=	A Labelled BNF converter

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bnfc ${PREFIX}/bin

post-install:
	${RM} -f ${WRKSRC}/examples/.cvsignore
	${RM} -f ${WRKSRC}/examples/haskell-core/.cvsignore
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/LBNF-report.tex ${DOCSDIR}
.endif

.include <bsd.port.mk>
