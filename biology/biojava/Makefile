# New ports collection makefile for: biojava
# Date created:	15 September 2000
# Whom:		FreeBSD Bio porters (bio@freebsd.net)
#
# $FreeBSD$
#

PORTNAME=	biojava
PORTVERSION=	1.01
CATEGORIES=	biology java
MASTER_SITES=	ftp://ftp.biojava.org/pub/biojava/source/

MAINTAINER=	bio@freebsd.net

BUILD_DEPENDS=	${JAVA_COMMAND}:${PORTSDIR}/java/linux-jdk

JDK_VERSION=	1.2.2
JAVAVERSION=	linux-jdk${JDK_VERSION}
JAVADIR=	${PREFIX}/${JAVAVERSION}
JAVA_COMPILE=	${JAVADIR}/bin/javac
JAVA_COMMAND=	${JAVADIR}/bin/java

do-build:
	@(cd ${WRKSRC}; \
		${JAVA_COMPILE} build/Builder.java; \
		${SETENV} PATH=${PATH}:${JAVADIR}/bin \
		${JAVA_COMMAND} build.Builder all;)

.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}; ${SETENV} PATH=${PATH}:${JAVADIR}/bin \
	${JAVA_COMMAND} build.Builder docs;)
.endif

do-install:
	@(cd ${WRKSRC}; \
		${MKDIR} ${PREFIX}/share/java/classes/; \
		${CP} ${WRKSRC}/biojava.jar ${PREFIX}/share/java/classes/; \
		${CP} ${WRKSRC}/xml.jar ${PREFIX}/share/java/classes/; \
		${MKDIR} ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} -R README LICENSE ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} -R ${WRKSRC}/demos ${PREFIX}/share/java/${PKGNAME}/;)

.if !defined(NOPORTDOCS)
	@(${CP} -R ${WRKSRC}/docs ${PREFIX}/share/java/${PKGNAME})
.endif)

post-install:
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Libraries installed at: ${PREFIX}/share/java/classes/"
	@${ECHO_MSG} "You should edit your CLASSPATH to include the jar files"
	@${ECHO_MSG} "in this directory."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Docs and demos are installed in:"
	@${ECHO_MSG} "${PREFIX}/share/java/${PKGNAME}"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
