# New ports collection makefile for:	bind
# Version required:	8.1.2
# Date created:		18 July 1997
# Whom:			jseger@scds.com
#
# $Id: Makefile,v 1.6 1998/07/19 05:11:59 gpalmer Exp $
#

DISTNAME=	bind-8.1.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind/src/8.1.2/
DISTFILES=	bind-8.1.2-src.tar.gz bind-8.1.2-doc.tar.gz

MAINTAINER=	jseger@FreeBSD.org

WRKSRC=		${WRKDIR}/src

MAN1=		dig.1 dnsquery.1 host.1
MAN3=		gethostbyname.3 getnetent.3 resolver.3
MAN5=		irs.conf.5 resolver.5
MAN7=		hostname.7 mailaddr.7
MAN8=		named-xfer.8 named.8 ndc.8 nslookup.8

PATCH_ARGS?=	-d ${WRKDIR} -E ${PATCH_STRIP}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/named/named-bootconf.pl ${PREFIX}/bin/
	@(cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} clean all ${INSTALL_TARGET})
	${MKDIR} ${PREFIX}/share/doc/bind8
	${INSTALL_DATA} ${WRKDIR}/doc/html/* ${PREFIX}/share/doc/bind8

.include <bsd.port.mk>
