# New ports collection makefile for:	gtksql
# Date created:				19 November 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gtksql
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://membres.lycos.fr/bbrox/GtkSQL/

MAINTAINER=	domi@saargate.de
COMMENT=	Graphical query tool for PostgreSQL and/or MySQL

.if defined(PACKAGE_BUILDING) && !defined(WITH_MYSQL) && !defined(WITH_PGSQL)
WITH_MYSQL=	yes
.endif

USE_X_PREFIX=	yes
USE_GNOME=	gtk12

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL) || (exists(${LOCALBASE}/lib/mysql/libmysqlclient.a) \
	&& !defined(WITHOUT_MYSQL))
HAVE_MYSQL=	yes
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.endif
.if defined(WITH_PGSQL) || (exists(${LOCALBASE}/lib/libpq.a) \
	&& !defined(WITHOUT_PGSQL))
HAVE_PGSQL=	yes
USE_PGSQL=	yes
.endif

pre-patch:
.if !defined(HAVE_MYSQL) && !defined(HAVE_PGSQL)
	@${ECHO} "You must specify which database to use, possible are:"
	@${ECHO}
	@${ECHO} "make WITH_MYSQL=yes (for MySQL support)"
	@${ECHO} "make WITH_PGSQL=yes (for PostgreSQL support)"
	@${ECHO} "make WITH_MYSQL=yes WITH_PGSQL=yes (for both MySQL and PostgreSQL support)"
	@${FALSE}
.endif

do-configure:
.if defined(HAVE_MYSQL)
	@${REINPLACE_CMD} -e "s/^#MYSQL/MYSQL/g" ${WRKSRC}/Makefile
.endif
.if defined(HAVE_PGSQL)
	@${REINPLACE_CMD} -e "s/^#PGSQL/PGSQL/g" ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtksql ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gtksql
.for file in Changelog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gtksql
.endfor
.endif

.include <bsd.port.post.mk>
