# Created by: Florian Limberger <flo@snakeoilproductions.net>
# $FreeBSD$

PORTNAME=	mypy
PORTVERSION=	0.641
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	flo@snakeoilproductions.net
COMMENT=	Optional static typing for Python

LICENSE=	MIT PSFL
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typed-ast>=1.1.0:devel/py-typed-ast@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.4.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy_extensions>=0:devel/py-mypy_extensions@${PY_FLAVOR}

USES=		python:3.4+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
SHEBANG_FILES=	mypy/typeshed/tests/*.py

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} < 3.5
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing>=3.5.3:devel/py-typing@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
