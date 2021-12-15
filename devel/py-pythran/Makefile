PORTNAME=	pythran
PORTVERSION=	0.11.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Ahead of Time compiler for numeric kernels

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gast>=0.5.0<0.6:devel/py-gast@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beniget>=0.4.0:devel/py-beniget@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-extract:
	${RM} ${WRKSRC}/third_party/xsimd/config/*.rej
	${RM} ${WRKSRC}/third_party/xsimd/*.rej
	${RM} ${WRKSRC}/third_party/xsimd/math/.xsimd_gamma.hpp.swp

.include <bsd.port.mk>
