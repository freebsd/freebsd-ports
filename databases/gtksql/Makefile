# New ports collection makefile for:	gtksql
# Date created:				19 November 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gtksql
PORTVERSION=	0.3
CATEGORIES=	databases
MASTER_SITES=	http://www.multimania.com/bbrox/GtkSQL/

MAINTAINER=	domi@saargate.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

.if defined(PACKAGE_BUILDING) && !defined(USE_MYSQL) && !defined(USE_PGSQL)
USE_MYSQL=	yes
.endif

.if defined(USE_MYSQL)
LIB_DEPENDS +=	mysqlclient.6:${PORTSDIR}/databases/mysql322-client
.endif
.if defined(USE_PGSQL)
LIB_DEPENDS +=	pq.2:${PORTSDIR}/databases/postgresql
.endif

USE_X_PREFIX=	yes

pre-patch:
.if !defined(USE_MYSQL) && !defined(USE_PGSQL)
	@ ${ECHO} "You must specify which database to use, possible are:"
	@ ${ECHO}
	@ ${ECHO} "make USE_MYSQL=yes (for MySQL support)"
	@ ${ECHO} "make USE_PGSQL=yes (for PostgreSQL support)"
	@ ${ECHO} "make USE_MYSQL=yes USE_PGSQL=yes (for both MySQL and PostgreSQL support)"
	@ ${FALSE}
.endif

do-configure:
.if defined(USE_MYSQL)
	@ ${PERL} -i -pe "s/^#MYSQL/MYSQL/g" ${WRKDIR}/${DISTNAME}/Makefile
.endif
.if defined(USE_PGSQL)
	@ ${PERL} -i -pe "s/^#PGSQL/PGSQL/g" ${WRKDIR}/${DISTNAME}/Makefile
.endif

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/gtksql ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/gtksql
.for file in COPYING Changelog README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gtksql
.endfor
.endif

.include <bsd.port.mk>
