# New ports collection makefile for:	pyching
# Date created:			5 July 2001
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	pyching
PORTVERSION=	1.2.1
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Consult a I Ching, an ancient Chinese book of wisdom

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

NO_WRKSUBDIR=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes

PLIST_SUB+=	LIB_TARGET=${LIB_TARGET:S,^${PREFIX}/,,g} \
		DOC_TARGET=${DOC_TARGET:S,^${PREFIX}/,,g}

EXEC_FILENAME=	${PORTNAME}
LIB_FILES=	pyching_*.py* smg*.py* icon.xbm
DOC_FILES=	[A-Z]*
LIB_TARGET=	${PREFIX}/lib/${PORTNAME}
DOC_TARGET=	${PREFIX}/share/doc/${PORTNAME}

post-patch:
	${SED} 's@^\(import sys\)$$@\1; sys.path.append("${LIB_TARGET}")@' \
		${WRKSRC}/pyching.py >${WRKSRC}/${EXEC_FILENAME}

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${EXEC_FILENAME} ${PREFIX}/bin
	${MKDIR} ${LIB_TARGET}
	cd ${WRKSRC} && ${INSTALL_DATA} ${LIB_FILES} ${LIB_TARGET}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOC_TARGET}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOC_FILES} ${DOC_TARGET}
.endif

.include <bsd.port.mk>
