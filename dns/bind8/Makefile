# New ports collection makefile for:	bind
# Date created:		18 July 1997
# Whom:			jseger@scds.com
#
# $FreeBSD$
#

PORTNAME=	bind
PORTVERSION=	8.2.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind/src/8.2.3/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/bind/src/8.2.3/,}
DISTFILES=	bind-src.tar.gz bind-doc.tar.gz

MAINTAINER=	DougB@FreeBSD.org

WRKSRC=		${WRKDIR}/src

MAN1=		dig.1 dnskeygen.1 dnsquery.1 host.1
MAN3=		getaddrinfo.3 gethostbyname.3 getipnodebyname.3 getnetent.3 \
		getnameinfo.3 inet_cidr.3 hesiod.3 resolver.3 tsig.3
MAN5=		irs.conf.5 named.conf.5 resolver.5
MAN7=		hostname.7 mailaddr.7
MAN8=		named-bootconf.8 named-xfer.8 named.8 ndc.8 nslookup.8 \
		nsupdate.8

PATCH_ARGS=	-d ${WRKDIR}
PATCH_DIST_ARGS=	-d ${WRKDIR}

post-install:
	@(cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} clean all ${INSTALL_TARGET})
	${MKDIR} ${PREFIX}/share/doc/bind8
	${INSTALL_DATA} ${WRKDIR}/doc/html/* ${PREFIX}/share/doc/bind8

.include <bsd.port.mk>
