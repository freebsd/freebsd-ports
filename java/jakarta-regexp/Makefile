# Ports collection makefile for:    Jakarta Regexp
# Date created:         2000/12/01
# Whom:                 Dave Glowacki <dglo@ssec.wisc.edu> #
# $FreeBSD$
#

PORTNAME=	jakarta-regexp
PORTVERSION=	1.2
CATEGORIES=	java
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-regexp/release/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	dglo@ssec.wisc.edu

BUILD_DEPENDS=	${JAVA_HOME}/bin/javac:${PORTSDIR}/java/jdk12
RUN_DEPENDS=	${JAVA_HOME}/bin/java:${PORTSDIR}/java/jdk12

JAVA_HOME?=	${LOCALBASE}/jdk1.2.2

do-build:
	@cd ${WRKSRC}/build && PATH=$$PATH:${JAVA_HOME}/bin JAVA_HOME=${JAVA_HOME} ${SH} build-regexp.sh package

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${LOCALBASE}/share/java/classes/${PORTNAME}.jar

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@(cd ${WRKSRC}/docs/api && ${TAR} -c -f - .) \
		| (cd ${PREFIX}/share/doc/${PORTNAME} && ${TAR} --unlink -x -f -)
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/${PORTNAME} 
	@(cd ${PREFIX} \
		&& find share/doc/${PORTNAME} -type f -print >> ${TMPPLIST})
.endif

.include <bsd.port.mk> END-of-jakarta-regexp/Makefile
