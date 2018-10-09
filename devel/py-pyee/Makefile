# $FreeBSD$

PORTNAME=	pyee
PORTVERSION=	5.0.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Python EventEmitter implementation

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vcversioner>0:devel/py-vcversioner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}

.if ${PY_FLAVOR:U} == py35 || ${PY_FLAVOR:U} == py36
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR}
.endif

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
