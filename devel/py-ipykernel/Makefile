# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	ipykernel
PORTVERSION=	6.15.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	IPython Kernel for Jupyter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}debugpy>=1.0:devel/py-debugpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=7.23.1:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-client>=6.1.12:devel/py-jupyter-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib-inline>=0.1:math/py-matplotlib-inline@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nest-asyncio>=0:devel/py-nest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=17:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=6.1:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=5.1.0:devel/py-traitlets@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.mk>
