# New ports collection makefile for:	eperl
# Version required:		2.0.3
# Date created:			Sat Jan  4 18:04:13 MET 1997
# Whom:				Ralf S. Engelschall <rse@engelschall.com>
#				Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.2 1997/01/04 23:40:16 andreas Exp $
#

DISTNAME=	eperl-2.0.3
CATEGORIES=	www perl5
MASTER_SITES=	http://www.engelschall.com/sw/eperl/dist/

MAINTAINER=	rse@engelschall.com

BUILD_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5 \
		${PREFIX}/etc/apache/srm.conf:${PORTSDIR}/www/apache

GNU_CONFIGURE=	yes

do-install:
	@if [ ! -d ${PREFIX}/www/cgi-bin ]; then \
		${MKDIR} -p ${PREFIX}/www/cgi-bin; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/nph-eperl ${PREFIX}/www/cgi-bin/
.if !defined(NOPORTDOCS)
	${MKDIR} -p ${PREFIX}/share/doc/eperl
	${INSTALL_DATA} ${WRKSRC}/doc/about.txt \
		${PREFIX}/share/doc/eperl/about.txt
	${INSTALL_DATA} ${WRKSRC}/doc/about.ps \
		${PREFIX}/share/doc/eperl/about.ps
	${INSTALL_DATA} ${WRKSRC}/doc/faq.txt \
		${PREFIX}/share/doc/eperl/faq.txt
	${INSTALL_DATA} ${WRKSRC}/doc/faq.ps \
		${PREFIX}/share/doc/eperl/faq.ps
.endif                                    

.include <bsd.port.mk>
