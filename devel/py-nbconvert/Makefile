PORTNAME=	nbconvert
PORTVERSION=	6.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Converting Jupyter Notebooks

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bleach>=0:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}entrypoints>=0.2.2:devel/py-entrypoints@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-core>=0:devel/py-jupyter-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab-pygments>=0:textproc/py-jupyterlab-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistune>=0.8.1<2:textproc/py-mistune@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbclient>=0.5.0<0.6.0:devel/py-nbclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=4.4:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandocfilters>=1.4.1:textproc/py-pandocfilters@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.4.1:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testpath>=0:devel/py-testpath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=5.0:devel/py-traitlets@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
