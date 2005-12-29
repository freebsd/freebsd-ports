# New ports collection makefile for:	py-kid
# Date created:		2005-11-02
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	kid
PORTVERSION=	0.8
CATEGORIES=	devel python
MASTER_SITES=	http://lesscode.org/dist/kid/${PORTVERSION}/
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} ; ${CP} README HISTORY COPYING misc/* ${DOCSDIR}
	${CP} -r ${WRKSRC}/doc/* ${DOCSDIR}

	${MKDIR} ${EXAMPLESDIR}
	${CP} -r ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
