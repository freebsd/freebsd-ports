# New ports collection makefile for:	Merchant Of Venice
# Date created:		Thu Jan 20 03:24:01 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	venice
PORTVERSION=	0.5.1.a
DISTVERSION=	0.51alpha
CATEGORIES=	finance java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mov
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Merchant Of Venice, a stock market trading program

BUILD_DEPENDS=	${JYTHON_PREFIX}/jython.jar:${PORTSDIR}/lang/jython

USE_JAVA=	yes
JAVA_EXTRACT=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes
ALL_TARGET=	build jar

BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/build

JARFILE=	${PORTNAME}.jar

PLIST_FILES=	\
		bin/${PKGNAMEPREFIX}${PORTNAME} \
		%%JAVAJARDIR%%/${JARFILE}

# docs
DOC_FILES=	\
		doc/manual.txt \
		changelog.txt \
		readme.txt

.ifndef(NOPORTDOCS)
PORTDOCS=	\
		*
.endif

# jython
JYTHON_PREFIX=	${LOCALBASE}/jython21
JYTHON_JAR=	${JYTHON_PREFIX}/jython.jar

post-extract:
# extract docs
	@cd ${BUILD_WRKSRC}/src && ${JAR} -xf ${WRKSRC}/venice.jar org/mov/help/doc
	@cd ${BUILD_WRKSRC}/src && ${JAR} -xf ${WRKSRC}/venice.jar org/mov/quote/samples
	@cd ${BUILD_WRKSRC} && ${JAR} -xf ${WRKSRC}/venice.jar META-INF
	@${MV} ${BUILD_WRKSRC}/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/src

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|(build),[[:space:]]*doc|\1|' \
		-e 's|%%CLASSPATH%%|${CLASSPATH}|' \
		${BUILD_WRKSRC}/build.xml
	@${SED} -E \
		-e "s|%%JAVAVM%%|${LOCALBASE}/bin/java|" \
		-e "s|%%JAVA_VERSION%%|${JAVA_VERSION}|" \
		-e "s|%%JAVAJARDIR%%|${JAVAJARDIR}|" \
		-e "s|%%JARFILE%%|${JARFILE}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
# wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${PREFIX}/bin/${PORTNAME}
# jar
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${BUILD_WRKSRC}/${JARFILE} ${JAVAJARDIR}/${JARFILE}

.include <bsd.port.pre.mk>

CLASSPATH+=	${JYTHON_JAR}

.include <bsd.port.post.mk>
