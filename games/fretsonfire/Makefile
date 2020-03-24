# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fretsonfire
PORTVERSION=	1.3.110
PORTREVISION=	14
CATEGORIES=	games python
MASTER_SITES=	SF
DISTNAME=	${PORTNAME_UCASE}-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Game of musical skill and fast fingers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/copying.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYGAME} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>=0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${LOCALBASE}/share/${PORTNAME}/default.ttf:games/fretsonfire-data

USES=		dos2unix python
DOS2UNIX_FILES=	*.txt
NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	share/${PORTNAME}
EXTRACT_AFTER_ARGS=	--exclude 'data'
SUB_FILES=	pkg-message FretsOnFire
SUB_LIST=	PROGRAM_DIR="${FOF_DIR}/${PORTNAME_UCASE}"
WRKSRC=		"${WRKDIR}/Frets on Fire-${PORTVERSION}"

FOF_DIR=	${PREFIX}/lib/${PORTNAME}

OPTIONS_DEFINE=	DOCS

PORTNAME_UCASE=	FretsOnFire

do-install:
	@${MKDIR} ${STAGEDIR}${FOF_DIR}/${PORTNAME_UCASE}
	@cd ${WRKSRC}/src && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${FOF_DIR}/${PORTNAME_UCASE}/{}" \; && \
			${FIND} -E * -type f -iregex ".*\.(py)" -exec ${INSTALL_DATA} {} "${STAGEDIR}${FOF_DIR}/${PORTNAME_UCASE}/{}" \;

	@${MKDIR} ${STAGEDIR}${FOF_DIR}/data
	@${LN} -s ${LOCALBASE}/${DATADIR}/* ${STAGEDIR}${FOF_DIR}/data
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME_UCASE} ${STAGEDIR}${PREFIX}/bin
	@${REINPLACE_CMD} -i '' -e 's|#!.*|#!${PYTHON_CMD}|' ${STAGEDIR}${PREFIX}/bin/${PORTNAME_UCASE}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/install.txt ${STAGEDIR}${DOCSDIR}/INSTALL

.include <bsd.port.mk>
