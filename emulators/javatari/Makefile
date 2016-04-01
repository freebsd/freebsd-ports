# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	javatari
PORTVERSION=	4.1
CATEGORIES=	emulators java
MASTER_SITES=	http://javatari.org/java/files/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Multiplayer Atari 2600 emulator written in pure Java

LICENSE=	AGPLv3

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
PLIST_FILES=	%%JAVAJARDIR%%/${DISTNAME}${EXTRACT_SUFX} \
		bin/javatari
SUB_FILES=	javatari
SUB_LIST+=	JARFILE="${JARFILE}"
JARFILE=	${DISTNAME}${EXTRACT_SUFX}

DESKTOP_ENTRIES=	"Javatari" "${COMMENT}" "${PORTNAME}" "${PORTNAME}"  \
			"Game;" false
PLIST_FILES+=	share/pixmaps/${PORTNAME}.png

post-extract:
	@(cd ${DISTDIR}/${DIST_SUBDIR} && ${UNZIP_CMD} -d ${WRKDIR} ${JARFILE} \
		org/javatari/pc/screen/images/LogoIcon32.png)

do-install:
	${INSTALL_DATA} ${DISTDIR}/${JARFILE} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/javatari ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/org/javatari/pc/screen/images/LogoIcon32.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
