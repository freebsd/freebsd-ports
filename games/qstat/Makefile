# New ports collection makefile for:   qstat
# Date created:        28 May 1998
# Whom:                Daniel O'Connor <darius@dons.net.au>
#
# $FreeBSD$
#

PORTNAME=	qstat
PORTVERSION=	2.4.a
CATEGORIES=	games
MASTER_SITES=	http://www.activesw.com/people/steve/
DISTNAME=	qstat${PORTVERSION:S/.//g}

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
