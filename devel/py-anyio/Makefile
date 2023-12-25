PORTNAME=	anyio
PORTVERSION=	4.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	High level compatibility layer for multiple asynchronous event loop implementations
WWW=		https://github.com/agronholm/anyio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=6.4:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}idna>=2.8:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>=1.1:devel/py-sniffio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	TRIO
TRIO_DESC=	Use trio as backend

TRIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}trio>=0.23:net/py-trio@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}exceptiongroup>=1.0.2:devel/py-exceptiongroup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.1:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
