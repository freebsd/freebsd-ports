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

MAINTAINER=	dglo@ssec.wisc.edu

BUILD_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/jakarta-ant

USE_REINPLACE=	YES

USE_JAVA=	1.2+
NEED_JAVAC=	YES

EXTRACT_CMD=	${JAR}
EXTRACT_BEFORE_ARGS=	-xf

PLIST= ${WRKDIR}/PLIST

JAVALIBNAME=   ${PORTNAME}-${PORTVERSION}
APIDOCSDIR=    ${DOCSDIR}/${JAVALIBNAME}

post-patch:
	@${REINPLACE_CMD} \
		-e "s;%%WRKSRC%%;${WRKSRC};g" \
		-e "s;%%PREFIX%%;${PREFIX};g" \
			${WRKSRC}/build.xml
	@${REINPLACE_CMD} "s;%%PREFIX%%;${PREFIX};g" ${WRKSRC}/j1c
	@${CHMOD} 544 ${WRKSRC}/j1c

do-build:
	@cd ${WRKSRC} && \
		${SETENV} JAVA_HOME=${JAVA_HOME} ant clean dist
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ${MKDIR} doc && \
	 ${JAVADOC} -d doc -package \
	     -classpath ${WRKSRC}:${WRKSRC}/lib/jdbc2_0-stdext.jar:${WRKSRC}/lib/jta-spec1_0_1.jar:${CLASSPATH} \
	     org.gjt.mm.mysql org.gjt.mm.mysql.jdbc2
.endif

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}

do-install: do-install-jar do-install-apidocs

do-install-jar:
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/build/mm.mysql-${PORTVERSION}/mm.mysql-${PORTVERSION}-bin.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${INSTALL_DATA} ${WRKSRC}/lib/jdbc2_0-stdext.jar \
		${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/lib/jta-spec1_0_1.jar \
		${JAVAJARDIR}
	@${ECHO} ${JAVAJARDIR}/jta-spec1_0_1.jar | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${ECHO} ${JAVAJARDIR}/jdbc2_0-stdext.jar | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${ECHO} ${JAVAJARDIR}/${PORTNAME}.jar | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${ECHO} "@unexec ${RMDIR} ${JAVAJARDIR} 2>/dev/null || true" | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}

do-install-apidocs:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${APIDOCSDIR}
	@${CP} -r ${WRKSRC}/doc/* ${APIDOCSDIR}
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${APIDOCSDIR}
	@${FIND} ${APIDOCSDIR} -type f -print | \
		${SED} "s,${PREFIX}/*,," >> ${PLIST}
	@${FIND} ${APIDOCSDIR} -type d -print | sort -r | \
		${SED} -e "s,${PREFIX}/*,," -e "s,^,@dirrm ,g" >> ${PLIST}
.endif

.include <bsd.port.mk>
