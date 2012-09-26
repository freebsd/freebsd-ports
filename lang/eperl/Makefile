# New ports collection makefile for:	eperl
# Date created:		03-Sep-1997
# Whom:			Ralf S. Engelschall <rse@engelschall.com>
#
# $FreeBSD$
#

PORTNAME=	eperl
PORTVERSION=	2.2.14
PORTREVISION=	4
CATEGORIES=	lang www perl5
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	tool/${PORTNAME}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Embedded Perl 5 Language

FORBIDDEN=	Vulnerable since 2001-06-21, http://portaudit.freebsd.org/73efb1b7-07ec-11e2-a391-000c29033c32.html
DEPRECATED=	Unfixed upstream remote vulnerability and no activity since 1998
EXPIRATION_DATE=2012-10-26

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

# Remove the strndup function from eperl, since
# certain versions of FreeBSD include it
.if ${OSVERSION} >= 701101
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-eperl_proto.h \
		${PATCHDIR}/extra-patch-eperl_parse.c
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: duplicate definition of strndup
.endif
.endif

# Perl 5.14 changed some symbol names
.if ${PERL_LEVEL} >= 501400
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-eperl_perl5.c
.endif

test:
	@(cd ${WRKSRC}; ${MAKE} test)

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*.[ch]" | \
		${XARGS} ${GREP} -l strnstr | \
		${XARGS} ${PERL} -pi -e 's|strnstr|ePerl_strnstr|g'
	@${REINPLACE_CMD} -e 's#%%PERL_VERSION%%#${PERL_VERSION}#g' \
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/eperl ${PREFIX}/bin/eperl
	${INSTALL_MAN} ${WRKSRC}/eperl.1 ${PREFIX}/man/man1/eperl.1
.if !defined(NOPORTEXAMPLES)
	${INSTALL} -d ${EXAMPLESDIR}
	${CP} ${WRKSRC}/eg/* ${EXAMPLESDIR}/
.endif
.if defined(INSTALL_ALSO_AS_SSSL)
	${INSTALL} -d ${PREFIX}/www/cgi-bin; \
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
