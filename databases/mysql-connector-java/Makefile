# New ports collection makefile for:	The mm MySql JDBC interface
# Version required:	1.2b
# Date created:		2 January 2000
# Whom:			Dave Glowacki <dglo@ssec.wisc.edu>
#
# $FreeBSD$
#

DISTNAME=	mm.mysql.jdbc-1.2b
PKGNAME=	mysql-jdbc-mm-1.2b
CATEGORIES=	databases
MASTER_SITES=	http://www.worldserver.com/mm.mysql/dist/

MAINTAINER=	dglo@SSEC.WISC.EDU

BUILD_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/javac:${PORTSDIR}/java/jdk
RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/java:${PORTSDIR}/java/jdk

ALL_TARGET=	jar

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes
	@${INSTALL_DATA} ${WRKSRC}/mysql_comp.jar ${LOCALBASE}/share/java/classes

.include <bsd.port.mk>
