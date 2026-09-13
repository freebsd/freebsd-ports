PORTNAME=	opengrok-tools
DISTVERSION=	1.14.1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	siva@FreeBSD.org
COMMENT=	OpenGrok tools for synchronization and mirroring
WWW=		https://oracle.github.io/opengrok/

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=2.6.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}resource>=0.2.0:devel/py-resource@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mockito>0:devel/py-mockito@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>0:devel/py-gitpython@${PY_FLAVOR} \
		git-tiny>0:devel/git@tiny

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	oracle
GH_PROJECT=	opengrok
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

BUILD_WRKSRC=	${WRKSRC}/tools
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-patch:
	@${REINPLACE_CMD} 's/0\.0\.1/${DISTVERSION}/g' \
		${BUILD_WRKSRC}/src/main/python/opengrok_tools/version.py

.include <bsd.port.mk>
