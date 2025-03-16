PORTNAME=	radian
DISTVERSION=	0.6.13
CATEGORIES=	devel math python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	21st century R console
WWW=		https://github.com/randy3k/radian

LICENSE=	MIT

DEPRECATED=	Depends on expired devel/py-pytest-runner
EXPIRATION_DATE=2025-03-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=3.0.41,<3.1:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.5.0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rchitect>=>=0.4.7,<0.5.0:devel/py-rchitect@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
