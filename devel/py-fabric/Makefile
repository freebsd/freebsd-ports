PORTNAME=	fabric
PORTVERSION=	3.1.0
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High level SSH command execution
WWW=		https://www.fabfile.org

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}invoke>=1.3:devel/py-invoke@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.4:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathlib2>0:devel/py-pathlib2@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR}

USES=		cpe python:3.7+
CPE_VENDOR=	fabfile
USE_PYTHON=	autoplist concurrent distutils pytest

CONFLICTS_INSTALL=	py*-fabric3 # bin/fab

NO_ARCH=	yes

.include <bsd.port.mk>
