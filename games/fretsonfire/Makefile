# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fretsonfire
PORTVERSION=	1.3.110
PORTREVISION=	7
CATEGORIES=	games python
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:S/f/F/g:S/o/O/}-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Game of musical skill and fast fingers

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}game>=0:${PORTSDIR}/devel/py-game \
		${PYTHON_PKGNAMEPREFIX}opengl>=0:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging \
		${LOCALBASE}/share/${PORTNAME}/default.ttf:${PORTSDIR}/games/fretsonfire-data

USES=		dos2unix
USE_PYTHON=	yes
DOS2UNIX_FILES=	*.txt
NO_BUILD=	yes

DATADIR=	share/${PORTNAME}
EXTRACT_AFTER_ARGS=	--exclude 'data'
SUB_FILES=	pkg-message FretsOnFire
SUB_LIST=	PROGRAM_DIR="${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}"
WRKSRC=		"${WRKDIR}/Frets on Fire-${PORTVERSION}"

FOF_DIR=	${PREFIX}/lib/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}
	@cd ${WRKSRC}/src && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}/{}" \; && \
			${FIND} -E * -type f -iregex ".*\.(py)" -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}/{}" \;

	@${MKDIR} ${STAGEDIR}${FOF_DIR}/data
	${LN} -s ${LOCALBASE}/${DATADIR}/* ${STAGEDIR}${FOF_DIR}/data
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME:S/f/F/g:S/o/O/} ${STAGEDIR}${PREFIX}/bin

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/install.txt ${STAGEDIR}${DOCSDIR}/INSTALL

.include <bsd.port.mk>
