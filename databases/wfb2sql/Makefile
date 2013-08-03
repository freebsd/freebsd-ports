# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wfb2sql
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CIA World Fact Book to SQL Conversion Utility

BUILD_DEPENDS=	p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
NO_BUILD=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wfb2sql ${PREFIX}/bin/wfb2sql
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
