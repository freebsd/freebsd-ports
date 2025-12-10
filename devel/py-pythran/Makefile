PORTNAME=	pythran
PORTVERSION=	0.18.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Ahead of Time compiler for numeric kernels
WWW=		https://github.com/serge-sans-paille/pythran

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}ply>=3.4:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gast>=0.7.0<=0.8:devel/py-gast@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beniget>=0.4.0:devel/py-beniget@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-extract:
	${RM} ${WRKSRC}/third_party/xsimd/config/*.rej
	${RM} ${WRKSRC}/third_party/xsimd/*.rej
	${RM} ${WRKSRC}/third_party/xsimd/math/.xsimd_gamma.hpp.swp

.include <bsd.port.mk>
