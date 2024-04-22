PORTNAME=	iniparse
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Accessing and Modifying INI files
WWW=		https://github.com/candlepin/python-iniparse

LICENSE=	MIT PSFL
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_FILE_PSFL=	${WRKSRC}/LICENSE-PSF

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
