# New ports collection makefile for:	wfb2sql
# Date created:		August 21st, 2003
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wfb2sql
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	CIA World Fact Book to SQL Conversion Utility

BUILD_DEPENDS=	${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-Pod-Parser \
		${SITE_PERL}/Config/General.pm:${PORTSDIR}/devel/p5-Config-General
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wfb2sql ${LOCALBASE}/bin/wfb2sql
	@${ECHO} "bin/wfb2sql" >> ${TMPPLIST}

	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/wfb2sqlrc ${EXAMPLESDIR}/wfb2sqlrc
	@${ECHO} "share/examples/${PORTNAME}/wfb2sqlrc" >> ${TMPPLIST}
	@${ECHO} "@dirrm share/examples/${PORTNAME}" >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/wfb2sql.html ${DOCSDIR}
	@${ECHO} "share/doc/${PORTNAME}/wfb2sql.html" >> ${TMPPLIST}
	@${ECHO} "@dirrm share/doc/${PORTNAME}/" >> ${TMPPLIST}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
