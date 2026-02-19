PORTNAME=	violet
DISTVERSION=	2.2.2
CATEGORIES=	devel editors java
MASTER_SITES=	SF/${PORTNAME}/violetumleditor/${DISTVERSION}-SNAPSHOT/
DISTNAME=	violetumleditor-${DISTVERSION}-SNAPSHOT
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Easy to learn and use UML editor
WWW=		https://horstmann.com/violet/ \
		https://sourceforge.net/projects/violet/

LICENSE=	GPLv2

USES=		java

NO_ARCH=	YES
NO_BUILD=	YES

PLIST_FILES=	${JAVASHAREDIR}/${PORTNAME}/violetumleditor.jar bin/${PORTNAME}

pre-install:
	${ECHO} "#!/bin/sh" > ${WRKDIR}/violet.sh
	${ECHO} "${PREFIX}/bin/java -jar ${JAVASHAREDIR}/${PORTNAME}/violetumleditor.jar" \
		>> ${WRKDIR}/violet.sh

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/violetumleditor-${DISTVERSION}-SNAPSHOT.jar \
		${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/violetumleditor.jar
	${INSTALL_SCRIPT} ${WRKDIR}/violet.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
