# Created by: Choe, Cheng-Dae
# $FreeBSD$

PORTNAME=	kid
PORTVERSION=	0.9.6
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	http://www.kid-templating.org/dist/${PORTVERSION}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Simple template language for XML based written in Python

USES=		python:2.7 shebangfix
USE_PYTHON=	distutils autoplist
SHEBANG_FILES=	misc/upgrade-0.6.py

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTDOCS=	*
PORTEXAMPLES=	*

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} ; ${CP} README HISTORY COPYING misc/* ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
