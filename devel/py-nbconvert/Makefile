PORTNAME=	nbconvert
PORTVERSION=	7.12.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Converting Jupyter Notebooks
WWW=		https://jupyter.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.5:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bleach>=0:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-core>=4.7:devel/py-jupyter-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyterlab-pygments>=0:textproc/py-jupyterlab-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=2.0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistune>=2.0.3<4:textproc/py-mistune@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbclient>=0.5.0:devel/py-nbclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=5.7:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandocfilters>=1.4.1:textproc/py-pandocfilters@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.4.1:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tinycss2>=0:textproc/py-tinycss2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=5.1:devel/py-traitlets@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

SHEBANG_FILES=	nbconvert/nbconvertapp.py

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=3.6:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
