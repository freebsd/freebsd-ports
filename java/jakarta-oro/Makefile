# Ports collection makefile for:    Jakarta ORO
# Date created:         2000/12/01
# Whom:                 Dave Glowacki <dglo@ssec.wisc.edu>
#
# $FreeBSD$
#

PORTNAME=	jakarta-oro
PORTVERSION=	2.0.6
CATEGORIES=	java
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-oro/release/v${PORTVERSION}/

MAINTAINER=	dglo@ssec.wisc.edu

BUILD_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/jakarta-ant

USE_JAVA=	1.2+
NEED_JAVAC=	YES

PLIST=	${WRKDIR}/PLIST

post-extract:
	@${CP} ${.CURDIR}/pkg-plist ${WRKDIR}/PLIST

do-build:
	@(cd ${WRKSRC}; ${SETENV} JAVA_HOME=${JAVA_HOME} ant jar javadocs)

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes
	@${INSTALL_DATA} ${WRKSRC}/jakarta-oro-${PORTVERSION}.jar ${LOCALBASE}/share/java/classes/jakarta-oro.jar
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs/api && ${TAR} -c -f - .) \
		| (cd ${DOCSDIR} && ${TAR} --unlink -x -f -)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@cd ${PREFIX} \
		&& ${FIND} share/doc/jakarta-oro -type f -print >> ${PLIST}
	@cd ${PREFIX} \
		&& ${FIND} share/doc/jakarta-oro -type d -print | sort -r | \
		${SED} "s,^,@dirrm ,g" >> ${PLIST}
.endif

.include <bsd.port.mk>
