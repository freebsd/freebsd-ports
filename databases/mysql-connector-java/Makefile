# New ports collection makefile for:	The mm MySql JDBC interface
# Date created:		2 January 2000
# Whom:			Dave Glowacki <dglo@ssec.wisc.edu>
#
# $FreeBSD$
#

PORTNAME=	mysql-jdbc-mm
PORTVERSION=	1.2c
CATEGORIES=	databases java
MASTER_SITES=	http://www.worldserver.com/mm.mysql/dist/
DISTNAME=	mm.mysql.jdbc-${PORTVERSION}

MAINTAINER=	dglo@SSEC.WISC.EDU

BUILD_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/javac:${PORTSDIR}/java/jdk
RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/java:${PORTSDIR}/java/jdk

MAKE_ENV+=	JAVAC=${LOCALBASE}/jdk1.1.8/bin/javac

ALL_TARGET=	jar

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes
	@${INSTALL_DATA} ${WRKSRC}/mysql_comp.jar ${LOCALBASE}/share/java/classes

.include <bsd.port.mk>
