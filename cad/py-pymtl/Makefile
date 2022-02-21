PORTNAME=	pymtl
DISTVERSION=	3.1.9
CATEGORIES=	cad python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	${PORTVERSION:R:R}
DISTNAME=	${PORTNAME}${PORTVERSION:R:R}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python-based hardware generation, simulation, verification framework

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>0:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=4.18.1:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
