PORTNAME=	nbclassic
PORTVERSION=	1.1.0
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipykernel>=0:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>=0:devel/py-ipython_genutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nest-asyncio>=1.5:devel/py-nest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notebook-shim>=0.2.3:devel/py-notebook-shim@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DESKTOP
DESKTOP_DESC=	Install desktop entry file

DESKTOP_USES=		desktop-file-utils
DESKTOP_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-setup.cfg

.include <bsd.port.mk>
