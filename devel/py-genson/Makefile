PORTNAME=	genson
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Powerful, user-friendly JSON Schema generator

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=3.0.1:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.4+ shebangfix
SHEBANG_FILES=	bin/genson.py
USE_PYTHON=	autoplist concurrent distutils

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
