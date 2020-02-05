# $FreeBSD$

PORTNAME=	edumips64
DISTVERSION=	1.2.6
CATEGORIES=	emulators java
MASTER_SITES=	https://github.com/lupino3/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}.jar

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Free, cross-platform, educational, visual MIPS64 CPU simulator

LICENSE=	GPLv2

USE_JAVA=	yes

DESKTOP_ENTRIES=	"EduMIPS64" \
			"${COMMENT}" \
			"" \
			"${PORTNAME}" \
			"Education;Emulator;" \
			false

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# none
EXTRACT_AFTER_ARGS=	${WRKSRC}

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST=	JARFILE=${_JARFILE} \
		JAVA=${JAVA}

NO_WRKSUBDIR=	yes

PLIST_FILES=	${JAVAJARDIR}/${_JARFILE} \
		bin/${PORTNAME}
PORTDOCS=	${DOCS_DISTFILES}

OPTIONS_DEFINE=	DOCS
DOCS_DISTFILES=	${DISTNAME}-en.pdf \
		${DISTNAME}-it.pdf

_JARFILE=	${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${_JARFILE}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${DOCS_DISTFILES} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
