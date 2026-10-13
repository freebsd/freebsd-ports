PORTNAME=	pyupgrade
DISTVERSION=	3.22.0
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool to automatically upgrade Python syntax for newer versions
WWW=		https://github.com/asottile/pyupgrade

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tokenize-rt>=6.1.0:devel/py-tokenize-rt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
