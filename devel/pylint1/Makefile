# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	pylint
PORTVERSION=	1.9.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	1${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Analyzes python source code looking for bugs and signs of poor quality

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astroid1>=1.6:devel/py-astroid1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=4.2.5:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mccabe>=0:devel/py-mccabe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

PORTSCOUT=	limit:^1\.

USES=		python shebangfix
USE_PYTHON=	concurrent distutils py3kplist

NO_ARCH=	yes

SHEBANG_FILES=	pylint/test/data/ascript

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.functools_lru_cache>=0:devel/py-backports.functools_lru_cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configparser>=0:devel/py-configparser@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}singledispatch>=0:devel/py-singledispatch@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
