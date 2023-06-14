PORTNAME=	iniparse
PORTVERSION=	0.5
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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
