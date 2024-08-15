PORTNAME=	pycomposefile
DISTVERSION=	0.0.30
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Structured deserialization of Docker Compose files for Python
WWW=		https://pypi.org/project/pycomposefile/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${RM} -r ${WRKSRC}/tests/

.include <bsd.port.mk>
