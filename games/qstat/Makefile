# New ports collection makefile for:   qstat
# Version required:    2.3c
# Date created:        28 May 1998
# Whom:                Daniel O'Connor <darius@dons.net.au>
#
# $Id: Makefile,v 1.2 1999/03/15 01:35:02 steve Exp $
#

DISTNAME=	qstat23c
PKGNAME=	qstat-2.3c
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.activesw.com/pub/quake/

MAINTAINER=	darius@dons.net.au

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qstat ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Installing documents in ${PREFIX}/share/doc/qstat"
	@${ECHO_MSG} ""
	${MKDIR} ${PREFIX}/share/doc/qstat
	${INSTALL_DATA} ${WRKSRC}/qstat.txt ${PREFIX}/share/doc/qstat
	${INSTALL_DATA} ${WRKSRC}/qstatdoc.html ${PREFIX}/share/doc/qstat
.endif

.include <bsd.port.mk>
