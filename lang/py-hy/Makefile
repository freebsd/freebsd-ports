PORTNAME=	hy
PORTVERSION=	1.1.0
CATEGORIES=	lang python
MASTER_SITES=	PYPI \
		https://github.com/hylang/hy/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lisp dialect embedded in Python
WWW=		https://hylang.org/ \
		https://docs.hylang.org/en/stable/ \
		https://github.com/hylang/hy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}funcparserlib>=1.0<2:devel/py-funcparserlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}funcparserlib>=1.0<2:devel/py-funcparserlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
