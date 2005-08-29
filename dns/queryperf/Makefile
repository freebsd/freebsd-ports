# New ports collection makefile for:    qyeryfile
# Date created:                         28 August 2005
# Whom:                                 Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=       queryperf
PORTVERSION=    1.1.1.2.2.5.4.3
CATEGORIES=     dns net benchmarks
MASTER_SITES=   ${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=     bind9/${BINDVERSION}
DISTNAME=       bind-${BINDVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	DNS Query Performance Testing Tool

BINDVERSION=	9.3.1
WRKSRC=		${WRKDIR}/bind-${BINDVERSION}/contrib/queryperf/
HAS_CONFIGURE=	yes
USE_PYTHON_RUN=	yes
PORTDOCS=	queryperf.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/queryperf ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/utils/gen-data-queryperf.py ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/queryperf.txt
.endif

.include <bsd.port.mk>
