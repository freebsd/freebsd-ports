# New ports collection makefile for:    qyeryfile
# Date created:                         28 August 2005
# Whom:                                 Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=       queryperf
PORTVERSION=    2.1
CATEGORIES=     dns net benchmarks
MASTER_SITES=   ftp://ftp.nominum.com/pub/nominum/
MASTER_SITE_SUBDIR=     bind9/${BINDVERSION}
DISTNAME=       ${PORTNAME}-nominum-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org
COMMENT=	DNS Query Performance Testing Tool

HAS_CONFIGURE=	yes
PORTDOCS=	queryperf.txt
USE_PYTHON_RUN=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/queryperf ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/utils/gen-data-queryperf.py ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/queryperf.txt
.endif

.include <bsd.port.mk>
