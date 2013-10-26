# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fretsonfire
PORTVERSION=	1.3.110
PORTREVISION=	4
CATEGORIES=	games python
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:S/f/F/g:S/o/O/}-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A game of musical skill and fast fingers

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}game>=0:${PORTSDIR}/devel/py-game \
		${PYTHON_PKGNAMEPREFIX}opengl>=0:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging \
		${LOCALBASE}/share/${PORTNAME}/default.ttf:${PORTSDIR}/games/fretsonfire-data

USE_PYTHON=	yes
USE_DOS2UNIX=	*.txt
NO_BUILD=	yes

DATADIR=	share/${PORTNAME}
EXTRACT_AFTER_ARGS=	--exclude 'data'
SUB_FILES=	pkg-message FretsOnFire
SUB_LIST=	PROGRAM_DIR="${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}"
WRKSRC=		"${WRKDIR}/Frets on Fire-${PORTVERSION}"

FOF_DIR=	${PREFIX}/lib/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}
	@cd ${WRKSRC}/src && \
		${FIND} * -type d -exec ${MKDIR} "${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}/{}" \; && \
			${FIND} -E * -type f -iregex ".*\.(py)" -exec ${INSTALL_DATA} "{}" "${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}/{}" \;

	${MKDIR} ${FOF_DIR}/data
	${LN} -s ${LOCALBASE}/${DATADIR}/* ${FOF_DIR}/data
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME:S/f/F/g:S/o/O/} ${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/install.txt ${DOCSDIR}/INSTALL
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
