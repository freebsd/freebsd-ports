# New ports collection makefile for:	eperl
# Date created:		03-Sep-1997
# Whom:			Ralf S. Engelschall <rse@engelschall.com>
#
# $FreeBSD$
#

PORTNAME=	eperl
PORTVERSION=	2.2.14
CATEGORIES=	lang www perl5
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	tool/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embedded Perl 5 Language

# User-controlled variables list
# INSTALL_ALSO_AS_SSSL
#	install ePerl also as a Server-Side
#	Scripting Language (SSSL) for Apache
#INSTALL_ALSO_AS_SSSL=	yes

.if defined(INSTALL_ALSO_AS_SSSL)
RUN_DEPENDS=	${PREFIX}/etc/apache/srm.conf:${PORTSDIR}/${APACHE_PORT}
PLIST_SUB=	SSSL=""
.else
PLIST_SUB=	SSSL="@comment "
.endif

USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl=${PERL5}

MAN1=	eperl.1

.include <bsd.port.pre.mk>

test:
	@(cd ${WRKSRC}; ${MAKE} test)

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*.[ch]" | \
		${XARGS} ${GREP} -l strnstr | \
		${XARGS} ${PERL} -pi -e 's|strnstr|ePerl_strnstr|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eperl ${PREFIX}/bin/eperl
	${INSTALL_MAN} ${WRKSRC}/eperl.1 ${PREFIX}/man/man1/eperl.1
.if !defined(NOPORTDOCS)
	@if [ ! -d ${PREFIX}/share/examples/eperl ]; then \
		${MKDIR} ${PREFIX}/share/examples/eperl; \
	fi
	${CP} ${WRKSRC}/eg/* ${PREFIX}/share/examples/eperl/
.endif
.if defined(INSTALL_ALSO_AS_SSSL)
	@if [ ! -d ${PREFIX}/www/cgi-bin ]; then \
		${MKDIR} ${PREFIX}/www/cgi-bin; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/eperl ${PREFIX}/www/cgi-bin/nph-eperl
	@if [ ".`${GREP} x-httpd-eperl ${PREFIX}/etc/apache/srm.conf`" = . ]; then \
		${ECHO_CMD} "AddType  application/x-httpd-eperl  .phtml .eperl .epl" \
			>>${PREFIX}/etc/apache/srm.conf; \
		${ECHO_CMD} "Action   application/x-httpd-eperl  /cgi-bin/nph-eperl" \
			>>${PREFIX}/etc/apache/srm.conf; \
		${ECHO} "Added knowledge about ePerl to Apache's srm.conf"; \
	else \
		${ECHO} "Apache srm.conf is already aware of ePerl"; \
	fi
.endif

.include <bsd.port.post.mk>
