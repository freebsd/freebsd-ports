# New ports collection makefile for:	antlr
# Date created:		5 July 2002
# Whom:			Geoffrey Mainland <mainland@apeiron.net>
#
# $FreeBSD$
#

PORTNAME=	antlr
PORTVERSION=	2.7.2
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://www.antlr.org/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mainland@apeiron.net
COMMENT=	ANTLR: ANother Tool for Language Recognition

CONFLICTS=	pccts*

USE_GMAKE=	yes
USE_JAVA=	1.2+
NEED_JAVAC=	YES

ALL_TARGET=	${PORTNAME}

.include <bsd.port.pre.mk>

BUILD_DEPENDS=	${JAVAC}:${PORTSDIR}/${JAVA_PORT} \
		${JAVA}:${PORTSDIR}/${JAVA_PORT}
RUN_DEPENDS=	${JAVA}:${PORTSDIR}/${JAVA_PORT}

post-extract:
	(cd ${WRKSRC} && ${CP} antlr.jar antlrall.jar)

post-configure:
	(cd ${WRKSRC} && \
	JAVAC=${JAVAC} JAR=${JAR} JAVA=${JAVA} \
	./configure --prefix=${PREFIX})

do-build:
	(cd ${WRKSRC} && PATH="${PATH}:${JAVA_HOME}/bin" ${JAVA} -classpath "." antlr.build.Tool build)
	(cd ${WRKSRC} && PATH="${PATH}:${JAVA_HOME}/bin" ${JAVA} -classpath "." antlr.build.Tool jar)
	(cd ${WRKSRC} && ${GMAKE})
	@${RM} -f ${WRKDIR}/antlr.sh
	@${SED} "s|%%JAVA_CLASSES%%|${PREFIX}/java/classes|" ${FILESDIR}/antlr.sh \
	| ${SED} "s|%%JAVA%%|${JAVA}|" >${WRKDIR}/antlr.sh

do-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/antlr
	@${MKDIR} ${PREFIX}/java/classes
	@${INSTALL_SCRIPT} ${WRKDIR}/antlr.sh ${PREFIX}/bin/antlr
	@${INSTALL_SCRIPT} ${WRKSRC}/antlr.jar ${PREFIX}/java/classes
	(cd ${WRKSRC}/lib/cpp && ${GMAKE} install)
	(cd ${WRKSRC} && (${TAR} cf - doc examples/cpp examples/java | ${TAR} xf - -C ${PREFIX}/share/antlr))

.include <bsd.port.post.mk>
