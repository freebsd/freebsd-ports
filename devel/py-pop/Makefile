PORTNAME=	pop
PORTVERSION=	20.1.1
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Plugin Oriented Programming interface for Python
WWW=		https://pop.readthedocs.io

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiofiles>=0:devel/py-aiofiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiologger>=0:devel/py-aiologger@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dict-toolbox>=0:sysutils/py-dict-toolbox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pop-config>0:devel/py-pop-config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python shebangfix

USE_GITLAB=	yes
GL_ACCOUNT=	saltstack/pop
GL_TAGNAME=	58d846bdd196b71348910aea77cd0139f70c4f12
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
