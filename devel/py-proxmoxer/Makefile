PORTNAME=	proxmoxer
PORTVERSION=	1.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	einar@isnic.is
COMMENT=	Wrapper around the Proxmox REST API v2
WWW=		https://github.com/proxmoxer/proxmoxer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils nose

NO_ARCH=	yes

# do-test:
# 	# openssh requires absent py-openssh_wrapper; also note that https tests fail
# 	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} -e openssh

.include <bsd.port.mk>
