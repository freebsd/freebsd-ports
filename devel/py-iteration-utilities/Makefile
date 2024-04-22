PORTNAME=	iteration-utilities
PORTVERSION=	0.12.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/MSeifert04/iteration_utilities/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	iteration_utilities-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utilities based on Pythons iterators and generators
WWW=		https://iteration-utilities.readthedocs.io/en/latest/ \
		https://github.com/MSeifert04/iteration_utilities

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
