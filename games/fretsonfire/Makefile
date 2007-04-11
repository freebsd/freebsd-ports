# New ports collection makefile for:	fretsonfire
# Date created:		2006-09-01
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fretsonfire
PORTVERSION=	1.2.438
CATEGORIES=	games python
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:S/f/F/g:S/o/O/}-${PORTVERSION:S/^/src-/}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A game of musical skill and fast fingers

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric/_numpy.so:${PORTSDIR}/math/py-numeric \
		${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_SITELIBDIR}/amanith.py:${PORTSDIR}/graphics/py-amanith \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/glew/__init__.py:${PORTSDIR}/graphics/py-glewpy \
		${LOCALBASE}/share/${PORTNAME}/default.ttf:${PORTSDIR}/games/fretsonfire-data

USE_PYTHON=	yes
NO_BUILD=	yes
DATADIR=	share/${PORTNAME}
FOF_DIR=	${PREFIX}/lib/${PORTNAME}
SUB_FILES=	pkg-message FretsOnFire
SUB_LIST=	PROGRAM_DIR="${FOF_DIR}/${PORTNAME:S/f/F/g:S/o/O/}"

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
	${LN} -s ${PREFIX}/${DATADIR}/* ${FOF_DIR}/data
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME:S/f/F/g:S/o/O/} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && \
		${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}/README
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
