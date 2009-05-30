# New ports collection makefile for:	fretsonfire
# Date created:		2006-09-01
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fretsonfire
PORTVERSION=	1.3.110
CATEGORIES=	games python
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:S/f/F/g:S/o/O/}-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A game of musical skill and fast fingers

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numpy/core/numeric.py:${PORTSDIR}/math/py-numpy \
		${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${LOCALBASE}/share/${PORTNAME}/default.ttf:${PORTSDIR}/games/fretsonfire-data

USE_PYTHON=	yes
USE_DOS2UNIX=	*.txt
NO_BUILD=	yes

DATADIR=	share/${PORTNAME}
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude 'data'
SUB_FILES=	pkg-message FretsOnFire
SUB_LIST=	PROGRAM_DIR="${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}"
WRKSRC=		"${WRKDIR}/Frets on Fire-${PORTVERSION}"

FOF_DIR=	${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_PSYCO=	yes
.endif

.if !defined(WITHOUT_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif

do-install:
	${MKDIR} ${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}
	@cd ${WRKSRC}/src && \
		${FIND} * -type d -exec ${MKDIR} "${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}/{}" \; && \
			${FIND} -E * -type f -iregex ".*\.(py)" -exec ${INSTALL_DATA} "{}" "${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}/{}" \;

	${MKDIR} ${FOF_DIR}/data
	${LN} -s ${LOCALBASE}/${DATADIR}/* ${FOF_DIR}/data
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME:S/f/F/g:S/o/O/} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/install.txt ${DOCSDIR}/INSTALL
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
