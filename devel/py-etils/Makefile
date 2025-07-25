PORTNAME=	etils
PORTVERSION=	1.13.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of common python utils
WWW=		https://etils.readthedocs.io/en/latest/ \
		https://github.com/google/etils

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.8<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ARRAY_TYPES EAPP ECOLAB EDC ENP EPATH EPATH_GCS EPATH_S3 EPY ETREE ETQDM
OPTIONS_DEFAULT=ARRAY_TYPES EAPP EDC ENP EPATH EPY ETREE ETQDM
ARRAY_TYPES_DESC=	Typing annotations for jax, numpy, ... arrays
ARRAY_TYPES_IMPLIES=	ENP
EAPP_DESC=		Absl flags/app utilities
EAPP_IMPLIES=		EPY
ECOLAB_DESC=		Colab utilities
ECOLAB_IMPLIES=		ENP EPY ETREE
EDC_DESC=		Dataclasses utilities
EDC_IMPLIES=		EPY
ENP_DESC=		Numpy utilities
ENP_IMPLIES=		EPY
EPATH_DESC=		Pathlib-like API
EPATH_GCS_DESC=		Pathlib-like API for GCS
EPATH_GCS_IMPLIES=	EPATH
EPATH_S3_DESC=		Pathlib-like API for S3
EPATH_S3_IMPLIES=	EPATH
EPATH_IMPLIES=		EPY
EPY_DESC=		Collection of generic python utilities
ETREE_DESC=		Tree utilities for tf.nest, jax.tree_utils, DeepMind tree
ETREE_IMPLIES=		ENP EPY ETQDM
ETQDM_DESC=		Tqdm utilities
ETQDM_IMPLIES=		EPY

EAPP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}absl-py>=0:devel/py-absl-py@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}simple-parsing>=0:devel/py-simple-parsing@${PY_FLAVOR}
ECOLAB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jupyter>=0:devel/py-jupyter@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mediapy>=0:devel/py-mediapy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}protobuf>=0,1:devel/py-protobuf@${PY_FLAVOR}
ENP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}einops>=0:misc/py-einops@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}
EPATH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fsspec>=0:filesystems/py-fsspec@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}importlib-resources>=0:devel/py-importlib-resources@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}zipp>=0:devel/py-zipp@${PY_FLAVOR}
EPATH_GCS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gcsfs>=0:filesystems/py-gcsfs@${PY_FLAVOR}
EPATH_S3_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}s3fs>=0:filesystems/py-s3fs@${PY_FLAVOR}
EPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
ETQDM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}absl-py>=0:devel/py-absl-py@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR}

.include <bsd.port.mk>
