# $FreeBSD$

PORTNAME=	edumips64
DISTVERSION=	1.2.5
CATEGORIES=	emulators java
MASTER_SITES=	https://github.com/lupino3/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}.jar
EXTRACT_ONLY=

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Free, cross-platform, educational, visual MIPS64 CPU simulator

LICENSE=	GPLv2

USE_JAVA=	yes

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/${JARFILE} bin/${PORTNAME}
PORTDOCS=	${DISTNAME}-manual-en.pdf \
		${DISTNAME}-manual-it.pdf

SUB_FILES=	${PORTNAME}
SUB_LIST=	JAVA=${JAVA} JARFILE=${JARFILE}

DESKTOP_ENTRIES="EduMIPS64" "${COMMENT}" "" "${PORTNAME}" \
		"Education;Emulator;" false

OPTIONS_DEFINE=	DOCS
DOCS_DISTFILES=	${DISTNAME}-manual-en.pdf \
		${DISTNAME}-manual-it.pdf

JARFILE=	${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${JARFILE}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} \
		${DISTDIR}/${DISTNAME}-manual-en.pdf \
		${DISTDIR}/${DISTNAME}-manual-it.pdf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
