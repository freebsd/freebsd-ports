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

.if defined(PACKAGE_BUILDING) && !defined(WITH_MYSQL) && !defined(WITH_PGSQL)
WITH_MYSQL=	yes
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS +=	mysqlclient.6:${PORTSDIR}/databases/mysql322-client
.endif
.if defined(WITH_PGSQL)
LIB_DEPENDS +=	pq.2:${PORTSDIR}/databases/postgresql
.endif

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

pre-patch:
.if !defined(WITH_MYSQL) && !defined(WITH_PGSQL)
	@ ${ECHO} "You must specify which database to use, possible are:"
	@ ${ECHO}
	@ ${ECHO} "make WITH_MYSQL=yes (for MySQL support)"
	@ ${ECHO} "make WITH_PGSQL=yes (for PostgreSQL support)"
	@ ${ECHO} "make WITH_MYSQL=yes WITH_PGSQL=yes (for both MySQL and PostgreSQL support)"
	@ ${FALSE}
.endif

do-configure:
.if defined(WITH_MYSQL)
	@ ${PERL} -i -pe "s/^#MYSQL/MYSQL/g" ${WRKDIR}/${DISTNAME}/Makefile
.endif
.if defined(WITH_PGSQL)
	@ ${PERL} -i -pe "s/^#PGSQL/PGSQL/g" ${WRKDIR}/${DISTNAME}/Makefile
.endif

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/gtksql ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/gtksql
.for file in Changelog README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gtksql
.endfor
.endif

.include <bsd.port.mk>
