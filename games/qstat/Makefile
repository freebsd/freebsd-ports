# New ports collection makefile for:   qstat
# Date created:        28 May 1998
# Whom:                Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	qstat
PORTVERSION=	2.5.b
PORTREVISION=	1
CATEGORIES=	games net
MASTER_SITES=	http://www.qstat.org/
DISTNAME=	qstat${PORTVERSION:S/.//g}

MAINTAINER=	pat@FreeBSD.org

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/qstat ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Installing documents and templates in: \
		${DOCSDIR}"
	@${ECHO_MSG} ""
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/template
	@${INSTALL_DATA} ${WRKSRC}/qstatdoc.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/template/* ${DOCSDIR}/template
.endif

.include <bsd.port.mk>
