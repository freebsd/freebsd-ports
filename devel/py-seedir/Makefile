PORTNAME=	seedir
DISTVERSION=	0.5.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Python package for creating, editing, and reading folder tree diagrams
WWW=		https://earnestt1234.github.io/seedir/seedir/ \
		https://github.com/earnestt1234/seedir

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}natsort>0:devel/py-natsort@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	EMOJI

EMOJI_DESC=	Enable emoji style

EMOJI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}emoji>0:misc/py-emoji@${PY_FLAVOR}

.include <bsd.port.mk>
