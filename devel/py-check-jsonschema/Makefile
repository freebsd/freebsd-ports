PORTNAME=	check-jsonschema
PORTVERSION=	0.27.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/python-jsonschema/check-jsonschema/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	jsonschema CLI and pre-commit hook
WWW=		https://github.com/python-jsonschema/check-jsonschema

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8<9:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.18.0<5.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regress>=0.4.0:devel/py-regress@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0<3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.18.5:devel/py-ruamel.yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=1.4.0:devel/py-importlib-resources@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
