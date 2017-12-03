# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	pylint
PORTVERSION=	1.7.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Analyzes python source code looking for bugs and signs of poor quality

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

py34_BROKEN=	Fails to package
py35_BROKEN=	Fails to package
py36_BROKEN=	Fails to package

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astroid>=1.5.1:devel/py-astroid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}editdistance>=0:devel/py-editdistance@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=4.2.5:devel/py-isort@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mccabe>=0:devel/py-mccabe@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	concurrent distutils
USES=		python shebangfix

SHEBANG_FILES=	pylint/test/data/ascript

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.functools_lru_cache>=0:devel/py-backports.functools_lru_cache@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configparser>=0:devel/py-configparser@${FLAVOR}
.endif

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}singledispatch>=0:devel/py-singledispatch@${FLAVOR}
.endif

.include <bsd.port.post.mk>
