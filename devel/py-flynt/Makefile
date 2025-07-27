PORTNAME=	flynt
PORTVERSION=	1.0.3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Convert Python scripts from string formatting to f-strings
WWW=		https://github.com/ikamensh/flynt

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}

USES=		python:3.9+
USE_GITHUB=	yes
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

GH_ACCOUNT=	ikamensh

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tomli>1.1.0:textproc/py-tomli@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
