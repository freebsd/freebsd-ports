# New ports collection makefile for:	eperl
# Version required:		2.0.2
# Date created:			Sat Jan  4 18:04:13 MET 1997
# Whom:				Ralf S. Engelschall <rse@engelschall.com>
#
# $Id$
#

DISTNAME=	eperl-2.0.2
CATEGORIES=	www
MASTER_SITES=	http://www.engelschall.com/sw/eperl/dist/

MAINTAINER=	rse@engelschall.com

BUILD_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	${PREFIX}/etc/apache/srm.conf:${PORTSDIR}/www/apache

GNU_CONFIGURE=	yes

do-install:
	@if [ ! -d ${PREFIX}/www/cgi-bin ]; then \
		${MKDIR} ${PREFIX}/www/cgi-bin; \
	fi
	cd ${WRKSRC}; ${INSTALL_PROGRAM} nph-eperl ${PREFIX}/www/cgi-bin/
	@if [ ".`grep ePerl ${PREFIX}/etc/apache/srm.conf`" = . ]; then \
		echo "Adding glue config to ${PREFIX}/etc/apache/srm.conf."; \
		echo "" >>${PREFIX}/etc/apache/srm.conf; \
		echo "#   ePerl -- Embedded Perl 5 for HTML (server-side scripting language)" >>${PREFIX}/etc/apache/srm.conf; \
		echo "AddType application/x-httpd-eperl .phtml .eperl .epl" >>${PREFIX}/etc/apache/srm.conf; \
		echo "Action  application/x-httpd-eperl /cgi-bin/nph-eperl" >>${PREFIX}/etc/apache/srm.conf; \
		echo "" >>${PREFIX}/etc/apache/srm.conf; \
	fi

.include <bsd.port.mk>
