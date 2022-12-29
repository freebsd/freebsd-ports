PORTNAME=	retext
DISTVERSION=	8.0.0
CATEGORIES=	editors

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Markdown editor
WWW=		https://github.com/retext-project/retext

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE_GPL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>=0:textproc/py-enchant@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Markups>=3.0.0:textproc/py-markups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-markdown-math>=0.6:textproc/py-python-markdown-math@${PY_FLAVOR}

USES=		desktop-file-utils pyqt:6 python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	retext-project
USE_PYTHON=	autoplist distutils noflavors
USE_PYQT=	pyqt6:run sip:run

NO_ARCH=	yes

.include <bsd.port.mk>
