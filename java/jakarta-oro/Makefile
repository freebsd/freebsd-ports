# Ports collection makefile for:    Jakarta ORO
# Date created:         2000/12/01
# Whom:                 Dave Glowacki <dglo@ssec.wisc.edu>
#
# $FreeBSD$
#

PORTNAME=	jakarta-oro
PORTVERSION=	2.0.1
CATEGORIES=	java
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-oro/release/v${PORTVERSION}/

MAINTAINER=	dglo@ssec.wisc.edu

BUILD_DEPENDS=	${JAVA_HOME}/bin/javac:${PORTSDIR}/java/jdk
RUN_DEPENDS=	${JAVA_HOME}/bin/java:${PORTSDIR}/java/jdk

JAVA_HOME?=	${LOCALBASE}/jdk1.2.2
PLIST=	${WRKDIR}/PLIST

post-extract:
	@${CP} ${.CURDIR}/pkg-plist ${WRKDIR}/PLIST

do-build:
	@cd ${WRKSRC}/build && ${SETENV} PATH=$$PATH:${JAVA_HOME}/bin \
		JAVA_HOME=${JAVA_HOME} ${SH} build-oro.sh package

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes
	@${INSTALL_DATA} ${WRKSRC}/jakarta-oro-2.0.1.jar ${LOCALBASE}/share/java/classes/jakarta-oro.jar
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc/api && ${TAR} -c -f - .) \
		| (cd ${DOCSDIR} && ${TAR} --unlink -x -f -)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@cd ${PREFIX} \
		&& find share/doc/jakarta-oro -type f -print >> ${PLIST}
	@cd ${PREFIX} \
		&& find share/doc/jakarta-oro -type d -print | sort -r | \
		${SED} "s,^,@dirrm ,g" >> ${PLIST}
.endif

.include <bsd.port.mk>
