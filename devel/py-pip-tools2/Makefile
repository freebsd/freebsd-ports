# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pip-tools
PORTVERSION=	2.0.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Keep your pinned dependencies fresh

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips64=		fails to compile: UnicodeDecodeError: 'ascii' codec can't decode byte 0xe2 in position 6865: ordinal not in range(128) #'
BROKEN_powerpc64=	fails to compile: UnicodeDecodeError: 'ascii' codec can't decode byte 0xe2 in position 6865: ordinal not in range(128) #'

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}first>=0:devel/py-first@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
USE_LOCALE=	en_US.UTF-8

PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>
