PORTNAME=	invoke
PORTVERSION=	2.2.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python task execution tool and library
WWW=		https://www.pyinvoke.org/ \
		https://github.com/pyinvoke/invoke

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	SUDO
SUDO_DESC=	Run shell commands via sudo

SUDO_RUN_DEPENDS=	sudo:security/sudo

.include <bsd.port.mk>
