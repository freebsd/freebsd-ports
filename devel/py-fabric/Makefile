PORTNAME=	fabric
DISTVERSION=	3.2.3
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High level SSH command execution
WWW=		https://www.fabfile.org

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>=5:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecated>=1.2:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}invoke>=2.0:devel/py-invoke@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.4:security/py-paramiko@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	fabfile
USE_PYTHON=	autoplist concurrent distutils pytest

CONFLICTS_INSTALL=	py*-fabric3 # bin/fab

NO_ARCH=	yes

.include <bsd.port.mk>
