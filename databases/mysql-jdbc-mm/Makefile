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

ALL_TARGET=	jar

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes
	@${INSTALL_DATA} ${WRKSRC}/mysql_comp.jar ${LOCALBASE}/share/java/classes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mysql-jdbc
	@(cd ${WRKSRC}/doc && ${TAR} -c -f - .) \
		| (cd ${PREFIX}/share/doc/mysql-jdbc && ${TAR} --unlink -x -f -)
	@(cd ${PREFIX} \
		&& find share/doc/mysql-jdbc -type f -print >> ${TMPPLIST})
.endif

.include <bsd.port.mk>
