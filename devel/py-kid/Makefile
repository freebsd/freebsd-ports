# New ports collection makefile for:	py-kid
# Date created:		2005-11-02
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	kid
PORTVERSION=	0.9.4
CATEGORIES=	devel python
MASTER_SITES=	http://www.kid-templating.org/dist/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	whitekid@gmail.com
COMMENT=	A simple template language for XML based written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

PORTDOCS=	*

post-install:

.for f in kid kidc
	${CP} files/$f ${PREFIX}/bin/$f
	${REINPLACE_CMD} -i '' -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' ${PREFIX}/bin/$f
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} ; ${CP} README HISTORY COPYING misc/* ${DOCSDIR}
	${CP} -r ${WRKSRC}/doc/* ${DOCSDIR}

	${MKDIR} ${EXAMPLESDIR}
	${CP} -r ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
