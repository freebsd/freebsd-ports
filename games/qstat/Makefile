# New ports collection makefile for:   qstat
# Date created:        28 May 1998
# Whom:                Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	qstat
PORTVERSION=	2.6
CATEGORIES=	games net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	A command line program to query game servers on the net

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/qstat ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Installing documents and templates in: \
		${DOCSDIR}"
	@${ECHO_MSG} ""
	@${MKDIR} ${DOCSDIR}/info ${DOCSDIR}/template
	@${INSTALL_DATA} ${WRKSRC}/qstatdoc.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/template/* ${DOCSDIR}/template
	@${INSTALL_DATA} ${WRKSRC}/info/* ${DOCSDIR}/info
.endif

.include <bsd.port.mk>
