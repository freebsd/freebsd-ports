PORTNAME=	ReText
DISTVERSION=	8.1.0
CATEGORIES=	editors
MASTER_SITES=	PYPI
DISTNAME=	retext-${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Markdown editor
WWW=		https://github.com/retext-project/retext

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE_GPL

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>=0:textproc/py-enchant@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markups>=4.0.0:textproc/py-markups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-markdown-math>=0.6:textproc/py-python-markdown-math@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymdown-extensions>0:textproc/py-pymdown-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		Xvfb:x11-servers/xorg-server@xvfb

USES=		desktop-file-utils pyqt:6 python:3.9+ qt:6
USE_PYQT=	pyqt6:run
USE_PYTHON=	autoplist noflavors pep517
USE_QT=		tools:build

NO_ARCH=	yes

# Run tests in Xvfb using an approach to upstream CI:
# https://github.com/retext-project/retext/blob/2ef7142e9422e8423e168a7ab30f8e491510f9b6/.github/workflows/main.yml#L59
# run: xvfb-run -a -s "-screen 0 1024x768x24" python -m unittest discover -s tests -v
do-test:
	Xvfb :1 -screen 0 1024x768x24 & \
	cd ${WRKSRC} && ${SETENV} DISPLAY=:1 ${PYTHON_CMD} -m pytest -rs -v ; \
	killall -v Xvfb

.include <bsd.port.mk>
