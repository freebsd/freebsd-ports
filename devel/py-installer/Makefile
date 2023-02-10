PORTNAME=	installer
DISTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Library for installing Python wheels
WWW=		https://github.com/pypa/installer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	allflavors autoplist concurrent pep517
PEP517_BUILD_CMD=	${PYTHON_CMD} -m flit_core.wheel
PEP517_BUILD_DEPEND=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
PEP517_INSTALL_DEPEND=
MAKE_ENV+=	PYTHONPATH=${BUILD_WRKSRC}/src

NO_ARCH=	yes

.include <bsd.port.mk>
