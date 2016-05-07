# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtualenvwrapper
PORTVERSION=	4.7.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Set of extensions to virtualenv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr
RUN_DEPENDS=	${PKGNAMEPREFIX}stevedore>0:devel/py-stevedore \
		${PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv \
		${PKGNAMEPREFIX}virtualenv-clone>0:devel/py-virtualenv-clone

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
			${PYTHON_PKGNAMEPREFIX}sphinxcontrib-bitbucket>=1.0:textproc/py-sphinxcontrib-bitbucket

USES=		python
USE_PYTHON=	autoplist concurrent distutils

DOCS_VARS=	DOCSDIR=${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME} \
		PYDISTUTILS_BUILD_TARGET+=build_sphinx \
		PYDISTUTILS_BUILDARGS="-a -E"

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e 's|python setup.py|${PYTHON_CMD} setup.py|' \
		${WRKSRC}/docs/source/conf.py

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs/build/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
