PORTNAME=	jsonrpclib-pelix
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	JSON-RPC over HTTP that mirrors xmlrpclib syntax
WWW=		https://pypi.org/project/jsonrpclib-pelix/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0.21.1:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
