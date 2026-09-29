PORTNAME=	standard-aifc
PORTVERSION=	3.13.0
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	standard_aifc-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standard library aifc redistribution
WWW=		https://github.com/youknowone/python-deadlib/tree/main/aifc \
		https://github.com/youknowone/python-deadlib

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}audioop-lts>=0:audio/py-audioop-lts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}standard-chunk>=0:devel/py-standard-chunk@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
