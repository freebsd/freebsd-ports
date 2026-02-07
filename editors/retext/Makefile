PORTNAME=	ReText
DISTVERSION=	8.1.0
PORTREVISION=	1
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
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymdown-extensions>0:textproc/py-pymdown-extensions@${PY_FLAVOR}

USES=		desktop-file-utils display:test pyqt:6 python qt:6
USE_PYQT=	pyqt6:run
USE_PYTHON=	autoplist noflavors pep517 pytest
USE_QT=		tools:build

NO_ARCH=	yes

.include <bsd.port.mk>
