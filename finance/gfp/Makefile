# New ports collection makefile for:	gfp
# Date created:		Ter  6 Mar 2007 03:51:58 UTC
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gfp
PORTVERSION=	0.7.2
PORTREVISION=	5
CATEGORIES=	finance java
MASTER_SITES=	SFE
MASTER_SITE_SUBDIR=	gfd
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Personal finances administration software

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_EXTRACT=	yes
JAVA_BUILD=	jdk
JAVA_RUN=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native
WRKSRC=		${WRKDIR}/GFP

JAVAVM=		${LOCALBASE}/bin/java
JAR_FILE=	gfd.jar

PLIST_FILES+=	\
		bin/${PORTNAME}

post-extract:
# backup launcher
	@${CP} -f ${WRKSRC}/${JAR_FILE} ${WRKDIR}
# prepare custom made extraction
	@${MKDIR} ${WRKDIR}/extract.jar
	@cd ${WRKDIR}/extract.jar && ${JAR} xf ${WRKSRC}/${JAR_FILE}
	@${CP} -f ${FILESDIR}/Launcher.java ${WRKDIR}/extract.jar

post-patch:
	@${SED} -e  "s|%%JAR_DIR%%|${JAR_DIR}|; \
		s|%%DATADIR%%|${DATADIR}|; \
		s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%JAVA_OS%%|${JAVA_OS}|; \
		s|%%JAVA_VERSION%%|${JAVA_VERSION}|; \
		s|%%JAVAVM%%|${JAVAVM}|; \
		s|%%LN%%|${LN}|; \
		s|%%MKDIR%%|${MKDIR}|; \
		s|%%RM%%|${RM}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-build:
# prepare custom made extraction jar
	@${RM} -f ${WRKDIR}/extract.jar/Launcher.class
	@cd ${WRKDIR}/extract.jar && ${JAVAC} Launcher.java && \
		${JAR} -uf ${WRKSRC}/${JAR_FILE} Launcher.class && \
		cd ${WRKSRC} && ${JAVA} -jar ${WRKSRC}/${JAR_FILE} && \
		${CP} -f ${WRKDIR}/${JAR_FILE} ${WRKSRC}

do-install:
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}; ${FIND} * -type d -exec ${MKDIR} ${DATADIR}/{} \;)
	@(cd ${WRKSRC}; ${FIND} * -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;)
	@(cd ${WRKSRC}; ${FIND} -s * -not -type d) \
		| ${SED} -ne 's,^,${DATADIR:S,^${PREFIX}/,,}/,p' >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} -s -d * -type d) \
		| ${SED} -ne 's,^,@dirrm ${DATADIR:S,^${PREFIX}/,,}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR_REL}' >> ${TMPPLIST}
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
