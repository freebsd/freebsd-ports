PORTNAME=	dataclass-array
PORTVERSION=	1.5.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dataclass_array-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dataclasses that behave like numpy arrays (with indexing, slicing, vectorization)
WWW=		https://dataclass-array.readthedocs.io/en/latest/ \
		https://github.com/google-research/dataclass_array

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.8<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}einops>=0:misc/py-einops@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}etils>=0:devel/py-etils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lark>=0:devel/py-lark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
IGNORE=		devel/py-etils requires Python 3.10+
.endif

.include <bsd.port.post.mk>
