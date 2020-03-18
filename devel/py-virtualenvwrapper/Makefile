# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtualenvwrapper
PORTVERSION=	4.8.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Enhancements to virtualenv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}stevedore>0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv-clone>0:devel/py-virtualenv-clone@${PY_FLAVOR}

# Actually 2.6-2.7,3.3-3.6
USES=		python
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinxcontrib-bitbucket>=1.0:textproc/py-sphinxcontrib-bitbucket@${PY_FLAVOR}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+=build_sphinx \
			PYDISTUTILS_BUILDARGS="-a -E"

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|$$(command \\which python)|${PYTHON_CMD}|1' \
		-e 's|="virtualenv"|="virtualenv${UNIQUE_SUFFIX}"|1' \
		-e 's|="virtualenv-clone"|="virtualenv-clone${UNIQUE_SUFFIX}"|1' \
		${WRKSRC}/${PORTNAME}.sh
	${REINPLACE_CMD} \
		-e 's|which virtualenvwrapper.sh|which ${PORTNAME}.sh${UNIQUE_SUFFIX}|' \
		${WRKSRC}/${PORTNAME}_lazy.sh

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e 's|python setup.py|${PYTHON_CMD} setup.py|' \
		${WRKSRC}/docs/source/conf.py

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs/build/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
