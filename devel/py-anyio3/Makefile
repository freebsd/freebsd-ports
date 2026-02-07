PORTNAME=	anyio
PORTVERSION=	3.7.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High level compatibility layer for multiple asynchronous event loop implementations
WWW=		https://github.com/agronholm/anyio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_EXCEPTIONGROUP} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.8:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>=1.1:devel/py-sniffio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.

OPTIONS_DEFINE=	TRIO
TRIO_DESC=	Use trio as backend

TRIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}trio>=0.22:net/py-trio@${PY_FLAVOR}

.include <bsd.port.mk>
