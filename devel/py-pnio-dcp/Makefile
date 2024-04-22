PORTNAME=	pnio-dcp
PORTVERSION=	1.2.0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Library to PROFINET Discovery and basic DCP protocol
WWW=		https://gitlab.com/pyshacks/pnio_dcp

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITLAB=     yes
GL_ACCOUNT=     pyshacks
GL_PROJECT=     ${PORTNAME:S/-/_/}
GL_COMMIT=	6156aa9c10bca35a118a58a02837b97a7e5a829e

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
