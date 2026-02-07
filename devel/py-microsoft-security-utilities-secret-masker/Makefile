PORTNAME=	microsoft-security-utilities-secret-masker
PORTVERSION=	1.0.0b4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	microsoft_security_utilities_secret_masker-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for detecting and masking secrets
WWW=		https://pypi.org/project/microsoft-security-utilities-secret-masker/ \
		https://github.com/microsoft/security-utilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
