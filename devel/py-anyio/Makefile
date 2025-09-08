PORTNAME=	anyio
PORTVERSION=	4.10.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

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

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	TRIO
TRIO_DESC=	Use trio as backend

TRIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}trio>=0.26.1:net/py-trio@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}truststore>=0.9.1:security/py-truststore@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.5:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
