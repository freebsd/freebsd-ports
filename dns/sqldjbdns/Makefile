# New ports collection makefile for:	sqldjbdns
# Date created:		1 Sep 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	sqldjbdns
PORTVERSION=	0.72
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://home.tiscali.cz:8080/~cz210552/distfiles/

MAINTAINER=	ports@freebsd.org
COMMENT=	DJB dns server with PostgreSQL backend

DJ_PORT?=	${PORTSDIR}/dns/djbdns
BUILD_DEPENDS=	${NONEXISTENT}:${DJ_PORT}:extract
RUN_DEPENDS=	setuidgid:${PORTSDIR}/sysutils/daemontools

USE_PGSQL=	YES

PORTDOCS=	ANNOUNCEMENT STATUS pgsqldns.html NEWS TODO README \
		pgsqldns-conf.html sqldns.html pgsqldns-schema.html
DJ_SRC=		`cd ${DJ_PORT} && make -V WRKSRC`
ALL_TARGET=	default
PLIST_FILES=	bin/dnsbench bin/pgsqldns bin/pgsqldns-conf bin/pgsqldnscache \
		share/examples/${PORTNAME}/create.sql
PLIST_DIRS=	share/examples/${PORTNAME}

pre-build:
		${CP} -R ${DJ_SRC} ${WRKSRC}/djbdns-1.05
		${PATCH} < ${WRKSRC}/djbdns-1.05.patch -d ${WRKSRC}/djbdns-1.05
		${MV} ${WRKSRC}/sqldns-schema.html ${WRKSRC}/pgsqldns-schema.html

post-install:
		${MKDIR} ${EXAMPLESDIR}
		${INSTALL_DATA}  ${WRKSRC}/create.sql ${EXAMPLESDIR}
.ifndef NOPORTDOCS
		${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
