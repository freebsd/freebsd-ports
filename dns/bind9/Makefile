# New ports collection makefile for:	bind
# Version required:	8.1.1
# Date created:		18 July 1997
# Whom:			jseger@scds.com
#
# $Id: Makefile,v 1.1.1.1 1997/11/26 00:24:18 jseger Exp $
#

DISTNAME=	bind-8.1.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind/src/8.1.1/
DISTFILES=	bind-src.tar.gz bind-doc.tar.gz

MAINTAINER=	jseger@FreeBSD.org

WRKSRC=		${WRKDIR}/src

MAN1=		dig.1 dnsquery.1 host.1
MAN3=		gethostbyname.3 getnetent.3 resolver.3
MAN5=		resolver.5
MAN7=		hostname.7 mailaddr.7
MAN8=		named-xfer.8 named.8 ndc.8 nslookup.8

PATCH_ARGS?=	-d ${WRKDIR} -E ${PATCH_STRIP}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/named/named-bootconf.pl ${PREFIX}/bin/
#	for i in ${MAN1}; do \
#		${INSTALL_MAN} ${WRKDIR}/doc/man/$$i ${PREFIX}/man/man1/; \
#	done
#	for i in ${MAN3}; do \
#		${INSTALL_MAN} ${WRKDIR}/doc/man/$$i ${PREFIX}/man/man3/; \
#	done
#	for i in ${MAN5}; do \
#		${INSTALL_MAN} ${WRKDIR}/doc/man/$$i ${PREFIX}/man/man5/; \
#	done
#	for i in ${MAN7}; do \
#		${INSTALL_MAN} ${WRKDIR}/doc/man/$$i ${PREFIX}/man/man7/; \
#	done
#	for i in ${MAN8}; do \
#		${INSTALL_MAN} ${WRKDIR}/doc/man/$$i ${PREFIX}/man/man8/; \
#	done
	@(cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} clean all ${INSTALL_TARGET})
.include <bsd.port.mk>
