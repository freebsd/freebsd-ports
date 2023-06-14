PORTNAME=	flynt
PORTVERSION=	0.78
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Convert Python scripts from string formatting to f-strings
WWW=		https://github.com/ikamensh/flynt

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astor>0:devel/py-astor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>1.1.0:textproc/py-tomli@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist pep517

GH_ACCOUNT=	ikamensh

.include <bsd.port.mk>
