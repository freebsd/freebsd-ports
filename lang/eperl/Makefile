# New ports collection makefile for:	eperl
# Version required:	2.1.1
# Date created:		Fri May  2 13:16:31 MET DST 1997
# Whom:			Ralf S. Engelschall <rse@engelschall.com>
#
# $Id: Makefile,v 1.6 1997/05/24 13:17:10 jfitz Exp $
#

DISTNAME=	eperl-2.1.1
CATEGORIES=	lang www perl5
MASTER_SITES=	http://www.engelschall.com/sw/eperl/distrib/ \
		ftp://ftp.engelschall.com/sw/

MAINTAINER=	rse@engelschall.com

# User-controlled variables list
#
# Server-Side Scripting Language (SSSL) support:
# INSTALL_ALSO_AS_SSSL - install ePerl also as SSSL for Apache
# ENABLE_UID_SWITCHING - allow ePerl to switch the UID/GID to the
#                        owner of the executed script when operating 
#                        as a SSSL. Implies usage of SetUID bit!
#
INSTALL_ALSO_AS_SSSL=	yes
#ENABLE_UID_SWITCHING=	yes

.if defined(INSTALL_ALSO_AS_SSSL)
RUN_DEPENDS=	${PREFIX}/etc/apache/srm.conf:${PORTSDIR}/www/apache
.endif

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-perl=${PREFIX}/bin/perl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eperl ${PREFIX}/bin/eperl
	${INSTALL_MAN} ${WRKSRC}/eperl.1 ${PREFIX}/man/man1/eperl.1
.if defined(INSTALL_ALSO_AS_SSSL)
	@if [ ! -d ${PREFIX}/www/cgi-bin ]; then \
		${MKDIR} -p ${PREFIX}/www/cgi-bin; \
	fi
.if defined(ENABLE_UID_SWITCHING)
	${INSTALL_PROGRAM} -o root -m u+s ${WRKSRC}/eperl \
		${PREFIX}/www/cgi-bin/nph-eperl
.else
	${INSTALL_PROGRAM} ${WRKSRC}/eperl ${PREFIX}/www/cgi-bin/nph-eperl
.endif
.endif
.if !defined(NOPORTDOCS)
	@if [ ! -d ${PREFIX}/share/examples/eperl ]; then \
		${MKDIR} -p ${PREFIX}/share/examples/eperl; \
	fi
	${INSTALL_DATA} ${WRKSRC}/eg/demo-01.phtml \
		${PREFIX}/share/examples/eperl/demo-01.phtml
	${INSTALL_DATA} ${WRKSRC}/eg/demo-02.phtml \
		${PREFIX}/share/examples/eperl/demo-02.phtml
	${INSTALL_DATA} ${WRKSRC}/eg/demo-03.phtml \
		${PREFIX}/share/examples/eperl/demo-03.phtml
	${INSTALL_DATA} ${WRKSRC}/eg/demo-04.phtml \
		${PREFIX}/share/examples/eperl/demo-04.phtml
	${INSTALL_DATA} ${WRKSRC}/eg/demo-05.phtml \
		${PREFIX}/share/examples/eperl/demo-05.phtml
	${INSTALL_DATA} ${WRKSRC}/eg/demo-06.phtml \
		${PREFIX}/share/examples/eperl/demo-06.phtml
	${INSTALL_DATA} ${WRKSRC}/eg/demo-07.phtml \
		${PREFIX}/share/examples/eperl/demo-07.phtml
	${INSTALL_DATA} ${WRKSRC}/eg/demo-08.phtml \
		${PREFIX}/share/examples/eperl/demo-08.phtml
.endif                                    

.if defined(INSTALL_ALSO_AS_SSSL)
	@if [ ".`grep x-httpd-eperl ${PREFIX}/etc/apache/srm.conf`" = . ]; then \
		echo "AddType  application/x-httpd-eperl  .phtml .eperl .epl" \
			>>${PREFIX}/etc/apache/srm.conf; \
		echo "Action   application/x-httpd-eperl  /cgi-bin/nph-eperl" \
			>>${PREFIX}/etc/apache/srm.conf; \
		echo "Added knowledge about ePerl to Apache's srm.conf"; \
	else \
		echo "Apache srm.conf is already aware of ePerl"; \
	fi
.endif                                    

.include <bsd.port.mk>
