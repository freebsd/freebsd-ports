# Created by: Matthias Sund <m.sund@arcor.de>
# $FreeBSD$

PORTNAME=	antlrworks
PORTVERSION=	1.4.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel java
MASTER_SITES=	http://www.antlr.org/download/
EXTRACT_SUFX=	.jar

MAINTAINER=	m.sund@arcor.de
COMMENT=	The ANTLR GUI Development Environment

BROKEN=		Does not fetch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+

DESKTOP_ENTRIES="ANTLRWorks" \
	"ANTLR GUI Development Environment" \
	"${PREFIX}/share/pixmaps/antlrworks.png" \
	"antlrworks" \
	"Development;Java;" \
	true

PLIST_FILES=	bin/antlrworks \
		${JAVAJARDIR:C,${PREFIX}/?,,}/${PORTNAME}.jar \
		share/pixmaps/antlrworks.png

do-install:
	${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|' \
	-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	-e 's|%%PORTNAME%%|${PORTNAME}|' \
	-e 's|%%JAVA_VERSION%%|${JAVA_VERSION}|' ${FILESDIR}/antlrworks.sh > ${WRKDIR}/antlrworks.sh

	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing antlrworks script as ${PREFIX}/bin/antlrworks..."
	@${INSTALL_SCRIPT} ${WRKDIR}/antlrworks.sh ${STAGEDIR}${PREFIX}/bin/antlrworks
	@${ECHO_MSG} " [ DONE ]"
	@${INSTALL_DATA} ${WRKDIR}/icons/app_64x64.png ${STAGEDIR}${PREFIX}/share/pixmaps/antlrworks.png

.include <bsd.port.mk>
