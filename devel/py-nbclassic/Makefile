PORTNAME=	nbclassic
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/jupyter/nbclassic/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Jupyter Notebook as a Jupyter Server Extension
WWW=		https://github.com/jupyter/nbclassic

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-packaging>=0.9<2:devel/py-jupyter-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server>=1.17.0:devel/py-jupyter-server@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argon2-cffi>=0:security/py-argon2-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=0:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>=0:devel/py-ipython_genutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-client>=6.1.1:devel/py-jupyter-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-core>=4.6.1:devel/py-jupyter-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-server>=1.8:devel/py-jupyter-server@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbconvert>=5:devel/py-nbconvert@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nest-asyncio>=1.5:devel/py-nest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notebook-shim>=0.2.3:devel/py-notebook-shim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=17:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>=1.8.0:deskutils/py-send2trash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}terminado>=0.8.3:net/py-terminado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=6.1:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.2.1:devel/py-traitlets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DESKTOP
DESKTOP_DESC=	Install desktop entry file

DESKTOP_USES=		desktop-file-utils
DESKTOP_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-setup.cfg

.include <bsd.port.mk>
