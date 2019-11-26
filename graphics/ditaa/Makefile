# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	ditaa
DISTVERSION=	0_9
CATEGORIES=	graphics java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert ASCII art diagrams into proper bitmap graphics

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/COPYING

USES=		zip
USE_JAVA=	yes

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	%%JAVASHAREDIR%%/${PORTNAME}/${PORTNAME}.jar bin/${PORTNAME}

pre-install:
	${ECHO} "#!/bin/sh" > ${WRKDIR}/${PORTNAME}.sh
	${ECHO} "${PREFIX}/bin/java -jar ${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}.jar \$$*" >> ${WRKDIR}/${PORTNAME}.sh

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}${DISTVERSION}.jar ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
