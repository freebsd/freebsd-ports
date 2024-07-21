PORTNAME=	build
PORTVERSION=	1.2.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEP517 package builder
WWW=		https://build.pypa.io/en/stable/ \
		https://github.com/pypa/build

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=19.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject_hooks>=0:devel/py-pyproject_hooks@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	allflavors autoplist concurrent pep517

NO_ARCH=	yes

PEP517_BUILD_CMD=	${PYTHON_CMD} -m flit_core.wheel
PEP517_BUILD_DEPEND=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.8:devel/py-flit-core@${PY_FLAVOR}

.include <bsd.port.pre.mk>

#.if ${PYTHON_REL} < 31200
#RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.6:devel/py-importlib-metadata@${PY_FLAVOR}
#.endif

.include <bsd.port.post.mk>
