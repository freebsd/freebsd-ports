# New ports collection makefile for:	openjit
# Date created:				26 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openjit
PORTVERSION=	1.1.16
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	http://www.openjit.org/dist/
DISTNAME=	OpenJIT-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-performance reflective Java Just-In-Time (JIT) bytecode compiler

# Only native JDKs are allowed.  Default is java/diablo-jdk13
.if defined(WITH_JDK13)
JAVA_HOME=	${PREFIX}/jdk1.3.1
BUILD_DEPENDS=	${JAVA_HOME}/bin/java:${PORTSDIR}/java/jdk13
.elif defined(WITH_JDK12)
JAVA_HOME=	${PREFIX}/jdk1.2.2
BUILD_DEPENDS=	${JAVA_HOME}/bin/java:${PORTSDIR}/java/jdk12
.elif defined(WITH_JDK11)
JAVA_HOME=	${PREFIX}/jdk1.1.8
BUILD_DEPENDS=	${JAVA_HOME}/bin/java:${PORTSDIR}/java/jdk11
.else
JAVA_HOME=	${PREFIX}/diablo-jdk1.3.1
BUILD_DEPENDS=	${JAVA_HOME}/bin/java:${PORTSDIR}/java/diablo-jdk13
.endif

ONLY_FOR_ARCHS=	i386

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-jdk=${JAVA_HOME}

PLIST_SUB+=	JAVADIR=${JAVA_HOME:S,${PREFIX}/,,}
.if defined(WITH_JDK11)
JAVALIBDIR=	${PREFIX}/lib/OpenJIT
PLIST_SUB+=	JAVA2:="@comment " JAVA11:=""
.else
PLIST_SUB+=	JAVA2:="" JAVA11:="@comment "
.endif

post-configure:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/INSTALL

do-install:
.if defined(WITH_JDK11)
	@${MKDIR} ${JAVALIBDIR}
	@${INSTALL_DATA} ${WRKSRC}/libOpenJIT.so ${JAVALIBDIR}
	@${INSTALL_DATA} ${WRKSRC}/OpenJIT.jar ${JAVALIBDIR}
.else
	@${MKDIR} ${JAVA_HOME}/jre/classes
	@${INSTALL_DATA} ${WRKSRC}/libOpenJIT.so ${JAVA_HOME}/jre/lib/i386
	@cd ${WRKSRC} && ${FIND} org -name '*.class' \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${JAVA_HOME}/jre/classes
	@${FIND} ${JAVA_HOME}/jre/classes -type d | ${XARGS} ${CHMOD} a+rx
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}/INSTALL
	@${ECHO_MSG} ""
	@${ECHO_MSG} "See ${DOCSDIR}/INSTALL for usage instructions."
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
