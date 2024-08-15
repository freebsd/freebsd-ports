PORTNAME=	opengrok-tools
DISTVERSION=		1.12.23
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	OpenGrok tools for synchronization and mirroring
WWW=		https://oracle.github.io/opengrok/

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=2.6.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}resource>=0.2.0:devel/py-resource@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR}

# According to the vendor, Python3 is required
USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	oracle
GH_PROJECT=	opengrok
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes

BUILD_WRKSRC=	${WRKSRC}/tools
INSTALL_WRKSRC=	${BUILD_WRKSRC}

.include <bsd.port.mk>
