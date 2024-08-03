PORTNAME=	wlc
PORTVERSION=	1.14
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Command line utility for Weblate
WWW=		https://pypi.org/project/wlc/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argcomplete>0:devel/py-argcomplete@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
