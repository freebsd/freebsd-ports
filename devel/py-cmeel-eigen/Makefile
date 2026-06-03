PORTNAME=	cmeel-eigen
DISTVERSION=	3.4.1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cmeel_eigen-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Eigen C++ linear algebra headers packaged for the cmeel ecosystem
WWW=		https://github.com/cmake-wheel/cmeel-eigen

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/eigen/COPYING.MPL2

BUILD_DEPENDS=	cmake:devel/cmake \
		${PYTHON_PKGNAMEPREFIX}cmeel>0:devel/py-cmeel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cmeel>0:devel/py-cmeel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

MAKE_ENV+=	CMEEL_RUN_TESTS=0

NO_ARCH=	yes

.include <bsd.port.mk>
