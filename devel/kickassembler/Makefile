# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	kickassembler
PORTVERSION=	3.42
CATEGORIES=	devel java
MASTER_SITES=	http://www.theweb.dk/KickAssembler/
DISTNAME=	KickAssembler${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced MOS 65xx assembler with embedded script language

LICENSE=	NONE

DEPRECATED=	unknown license
EXPIRATION_DATE=	2018-08-15

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_ARCH=	yes

SUB_LIST=	PORTNAME=${PORTNAME}
SUB_FILES=	kickassembler.sh
WRKSRC=		${WRKDIR}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract-script:
	@${MV} "${WRKSRC}/Examples/MusicIrq/ode to 64.bin" ${WRKSRC}/Examples/MusicIrq/odeto64.bin

do-install:
	@${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/KickAss.jar ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/KickAss.cfg ${STAGEDIR}${JAVASHAREDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/kickassembler.sh ${STAGEDIR}${PREFIX}/bin/kickassembler

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/KickAssembler.pdf ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Examples/*/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
