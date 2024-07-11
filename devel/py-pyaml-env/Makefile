PORTNAME=	pyaml-env
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyaml_env-${PORTVERSION}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Provides yaml file parsing with environment variable resolution
WWW=		https://github.com/mkaranasou/pyaml_env

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
