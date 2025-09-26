PORTNAME=	madoka
DISTVERSION=	0.7.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Memory-efficient CountMin Sketch key-value structure
WWW=		https://github.com/ikegami-yukino/madoka-python

LICENSE=		BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=		multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/src/COPYING
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

PORTDOCS=	CHANGES.rst README.rst

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_madoka.*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
