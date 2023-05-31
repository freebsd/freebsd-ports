PORTNAME=	retext
DISTVERSION=	8.0.1
CATEGORIES=	editors
MASTER_SITES=	PYPI
DISTNAME=	ReText-${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Markdown editor
WWW=		https://github.com/retext-project/retext

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE_GPL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>=0:textproc/py-enchant@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markups>=3.0.0:textproc/py-markups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-markdown-math>=0.6:textproc/py-python-markdown-math@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymdown-extensions>0:textproc/py-pymdown-extensions@${PY_FLAVOR}

USES=		desktop-file-utils pyqt:6 python:3.9+
USE_PYTHON=	autoplist distutils noflavors pytest
USE_PYQT=	pyqt6:run sip:run

NO_ARCH=	yes

.include <bsd.port.mk>
