# New ports collection makefile for:	mysql-connector-java
# Date created:		8 October 2003
# Whom:			Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	mysql-connector-java
PORTVERSION=	3.0.9
CATEGORIES=	databases java
MASTER_SITES=	ftp://mysql.secsup.org/pub/software/mysql/Downloads/Connector-J/ \
		http://mysql.tzone.it/Downloads/Connector-J/ \
		ftp://planetmirror.com/pub/mysql/Downloads/Connector-J/ \
		http://www.softagency.co.jp/MySQL/Downloads/Connector-J/ \
		ftp://sunsite.dk/mirrors/mysql/Downloads/Connector-J/ \
		http://mysql.mediatraffic.fi/Downloads/Connector-J/ \
		ftp://filepile.tiscali.de/mirror/mysql/Downloads/Connector-J/ \
		http://mirrors.tilian.co.uk/mysql.com/Downloads/Connector-J/ \
		ftp://ftp.rtfm.no/pub/mysql/Downloads/Connector-J/ \
		http://www.mysql.cz/Downloads/Connector-J/ \
		ftp://ftp.u-paris10.fr/mysql.com/Downloads/Connector-J/ \
		http://mysql.oms-net.nl/Downloads/Connector-J/ \
		ftp://ftp.free.fr/pub/MySQL/Downloads/Connector-J/
DISTNAME=	${PORTNAME}-${PORTVERSION}-stable

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	MySQL Connector/J: JDBC interface for MySQL

.if !defined(WITHOUT_COMPILE)

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant \
		${LOCALBASE}/share/java/classes/junit.jar:${PORTSDIR}/java/junit
USE_JAVA=	1.4+
NEED_JAVAC=	YES

ANT?=		${LOCALBASE}/bin/ant
ANT_TARGET=	clean compile-driver
BUILDDIR=	${WRKDIR}/build-mysql-jdbc/${DISTNAME}

.else

USE_JAVA=	1.2+
BUILDDIR=	${WRKDIR}/${DISTNAME}

.endif

APIDOCSDIR=	${DOCSDIR}/javadoc
DESTJARFILE=	${PORTNAME}.jar
EXTRAJARS=	jdbc2_0-stdext.jar jta-spec1_0_1.jar
EXTRADOCS=	README CHANGES
JARFILE=	${DISTNAME}-bin.jar
JDCLASSPATH=	${WRKSRC}:${WRKSRC}/lib/jdbc2_0-stdext.jar:${WRKSRC}/lib/jta-spec1_0_1.jar:${CLASSPATH}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "    WITHOUT_COMPILE-yes    Install the pre-compiled .jar file"
	@${ECHO} ""
	@${ECHO} "This port requires JDK 1.4.x or better to compile, but the"
	@${ECHO} "JDBC driver will operate with JVM 1.2.x or better"
	@${ECHO} ""

do-build:
.if !defined(WITHOUT_COMPILE)
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${BUILDDIR}/doc && cd ${WRKSRC} && \
	 ${JAVADOC} -d ${BUILDDIR}/doc -package      \
	     -classpath  ${JDCLASSPATH}              \
	      com.mysql.jdbc org.gjt.mm.mysql
.endif

do-install: do-install-jar do-install-apidocs

do-install-jar:
	@${ECHO_CMD} -n ">> Installing .jar files..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${BUILDDIR}/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@for extrajar in ${EXTRAJARS} ; do                                 \
	  ${INSTALL_DATA} ${INSTALL_WRKSRC}/lib/$$extrajar ${JAVAJARDIR} ; \
	done
	@${ECHO_CMD} " [ DONE ]"

do-install-apidocs:
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${APIDOCSDIR}
	@${CP} -r ${BUILDDIR}/doc/* ${APIDOCSDIR}
	@for extradoc in ${EXTRADOCS} ; do                    \
	  ${INSTALL_DATA} ${BUILDDIR}/$$extradoc ${DOCSDIR} ; \
	done
	@${ECHO_CMD} " [ DONE ]"
.endif

.include <bsd.port.mk>
