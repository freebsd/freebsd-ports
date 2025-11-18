PORTNAME=	napari-console
DISTVERSION=	0.1.4
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Napari plugin: Add a console to Napari
WWW=		https://github.com/napari/napari-console

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipykernel>=5.2.0:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=7.7.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qtconsole>0:devel/py-qtconsole@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=1.7.0:devel/py-QtPy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
