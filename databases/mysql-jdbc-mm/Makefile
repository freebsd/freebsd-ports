# New ports collection makefile for:	The mm MySql JDBC interface
# Date created:		2 January 2000
# Whom:			Dave Glowacki <dglo@ssec.wisc.edu>
#
# $FreeBSD$
#

PORTNAME=	mysql-jdbc-mm
PORTVERSION=	2.0.14
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mmmysql
DISTNAME=	mm.mysql-${PORTVERSION}
EXTRACT_SUFX=	-you-must-unjar-me.jar

MAINTAINER=	dglo@SSEC.WISC.EDU

USE_JAVA=	1.2+
NEED_JAVAC=	YES

EXTRACT_CMD=	${JAR}
EXTRACT_BEFORE_ARGS=	-xf

post-patch:
	@(cd ${WRKSRC}; ${MV} build.xml build.xml.patched; \
	 ${SED} -e "s;%%WRKSRC%%;${WRKSRC};g" -e "s;%%PREFIX%%;${PREFIX};g" \
		< build.xml.patched > build.xml)
	@(cd ${WRKSRC}; ${MV} j1c j1c.patched; \
	 ${SED} "s;%%PREFIX%%;${PREFIX};g" < j1c.patched > j1c; \
	 ${CHMOD} 555 j1c)

do-build:
	@(cd ${WRKSRC}; ${SETENV} JAVA_HOME=${JAVA_HOME} ant clean dist)
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}; ${MKDIR} doc; \
	 ${JAVADOC} -d doc -package \
	     -classpath ${WRKSRC}:${WRKSRC}/lib/jdbc2_0-stdext.jar:${WRKSRC}/lib/jta-spec1_0_1.jar:${CLASSPATH} \
	     org.gjt.mm.mysql org.gjt.mm.mysql.jdbc2)
.endif

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes
	@${INSTALL_DATA} ${WRKSRC}/build/mm.mysql-${PORTVERSION}/mm.mysql-${PORTVERSION}-bin.jar \
		${PREFIX}/share/java/classes/mm.mysql-${PORTVERSION}.jar
	@${INSTALL_DATA} ${WRKSRC}/lib/jdbc2_0-stdext.jar \
		${PREFIX}/share/java/classes/
	@${INSTALL_DATA} ${WRKSRC}/lib/jta-spec1_0_1.jar \
		${PREFIX}/share/java/classes/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mysql-jdbc
	@(cd ${WRKSRC}/doc && ${TAR} -c -f - .) \
		| (cd ${PREFIX}/share/doc/mysql-jdbc && ${TAR} --unlink -x -f -)
.endif

post-install:
	@${ECHO} share/java/classes/mm.mysql-${PORTVERSION}.jar >> ${TMPPLIST}
	@${ECHO} share/java/classes/jdbc2_0-stdext.jar >> ${TMPPLIST}
	@${ECHO} share/java/classes/jta-spec1_0_1.jar >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@(cd ${PREFIX} \
		&& find share/doc/mysql-jdbc -type f -print >> ${TMPPLIST})
	@${ECHO} "@dirrm share/doc/mysql-jdbc" >> ${TMPPLIST}
.endif
	@${ECHO} "@unexec ${RMDIR} %D/share/java/classes 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO} "@unexec ${RMDIR} %D/share/java 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
