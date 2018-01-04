# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtualenvwrapper
PORTVERSION=	4.8.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Set of extensions to virtualenv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}stevedore>0:devel/py-stevedore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv-clone>0:devel/py-virtualenv-clone@${FLAVOR}

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinxcontrib-bitbucket>=1.0:textproc/py-sphinxcontrib-bitbucket@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist concurrent distutils

DOCS_VARS=	DOCSDIR=${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME} \
		PYDISTUTILS_BUILD_TARGET+=build_sphinx \
		PYDISTUTILS_BUILDARGS="-a -E"

post-patch:
	@${REINPLACE_CMD} -e 's|$$(command \\which python)|${PYTHON_CMD}|1' \
		${WRKSRC}/${PORTNAME}.sh

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e 's|python setup.py|${PYTHON_CMD} setup.py|' \
		${WRKSRC}/docs/source/conf.py

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs/build/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
