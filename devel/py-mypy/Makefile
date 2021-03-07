# Created by: Florian Limberger <flo@snakeoilproductions.net>
# $FreeBSD$

PORTNAME=	mypy
PORTVERSION=	0.812
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Optional static typing for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mypy_extensions>=0.4.3<0.5.0:devel/py-mypy_extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typed-ast>=1.4.0<1.5.0:devel/py-typed-ast@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.5+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_FILES=	mypy/typeshed/*/*.py

OPTIONS_DEFINE=	DMYPY
OPTIONS_DEFAULT=DMYPY
DMYPY_DESC=	Daemon mode

DMYPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=4.0:sysutils/py-psutil@${PY_FLAVOR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
