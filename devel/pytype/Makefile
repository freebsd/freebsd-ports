# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	pytype
PORTVERSION=	2022.1.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python type inferencer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>=0:devel/py-pybind11@${PY_FLAVOR}
RUN_DEPENDS=	ninja>=1.10.2:devel/ninja \
		${PYTHON_PKGNAMEPREFIX}attrs>=21.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlab>=0.6.1:devel/py-importlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libcst>=0:devel/py-libcst@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR}

USES=		compiler:c++11-lang python:3.7+
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typed-ast>=1.5.0:devel/py-typed-ast@${PY_FLAVOR}
.endif

post-patch:
	@${RM} ${WRKSRC}/pytype/tools/merge_pyi/test_data/packed_tuple.py
	@${RM} ${WRKSRC}/pytype/tools/merge_pyi/test_data/packed_tuple.comment.py
	@${RM} ${WRKSRC}/pytype/tools/merge_pyi/test_data/packed_tuple.pep484.py
	@${RM} ${WRKSRC}/pytype/tools/merge_pyi/test_data/parse_error.py
	@${RM} ${WRKSRC}/pytype/tools/merge_pyi/test_data/pyi_variations.comment.py
	@${RM} ${WRKSRC}/pytype/tools/merge_pyi/test_data/simple_defaults.py

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
