PORTNAME=	apio
DISTVERSION=	0.9.5
CATEGORIES=	cad python
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source ecosystem for open FPGA boards
WWW=		https://github.com/FPGAwars/apio/wiki

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.1.3:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=3.5:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.28.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic-version>=2.9.0:devel/py-semantic-version@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=2:devel/py-flit-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.35.0<1:devel/py-wheel@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python scons
USE_PYTHON=	pep517 concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
