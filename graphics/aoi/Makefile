# New ports collection makefile for:	Art Of Illusion
# Date created:				Fri Jun 21 17:10:56 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aoi
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	graphics java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aoi
DISTNAME=	AoI${PORTVERSION:S/.//}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	An open source Java written 3D modelling and rendering studio

USE_JAVA=	1.3+
USE_ZIP=	yes
NO_BUILD=	yes
NO_BUILD_DEPENDS_JAVA=	yes
PLIST_SUB=	JAR_DIR=${JAR_DIR} \
		JAR_FILE=${JAR_FILE}
WRKSRC=		${WRKDIR}/ArtOfIllusion${PORTVERSION}

EXTRACT_BEFORE_ARGS=	-a -q

JAVAVM=		${LOCALBASE}/bin/javavm
JAR_DIR=	share/java/jar/${PORTNAME}/
JAR_MANIFEST=	${FILESDIR}/manifest

DOC_FILES=	HISTORY LICENSE README
JAR_FILES=	ArtOfIllusion.jar
JAR_PLUGIN_FILES=	OSSpecific.jar Renderers.jar Tools.jar Translators.jar

post-patch:
# remove trailing ^M
	@${SED} -e "s|%%JAR_DIR%%|${JAR_DIR}|;s|%%JAR_FILE%%|${JAR_FILE}|; \
		s|%%JAVAVM%%|${JAVAVM}|;s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
	@${MKDIR} ${PREFIX}/${JAR_DIR}
.for jar in ${JAR_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${jar} ${PREFIX}/${JAR_DIR}
.endfor
	@${MKDIR} ${PREFIX}/${JAR_DIR}/Plugins
.for jar in ${JAR_PLUGIN_FILES}
	@${INSTALL_DATA} ${WRKSRC}/Plugins/${jar} \
		${PREFIX}/${JAR_DIR}/Plugins
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

JAR_FILE=	ArtOfIllusion.jar

.include <bsd.port.post.mk>
