PORTNAME=	check-wheel-contents
PORTVERSION=	0.6.3
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	check_wheel_contents-${PORTVERSION}

PATCH_SITES=	https://github.com/jwodder/check-wheel-contents/commit/
PATCHFILES=	a83be927738256ec756e9fffd319782d6e7466dd.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Check your wheels have the right contents
WWW=		https://github.com/jwodder/check-wheel-contents

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=18.1:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.2<9:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0<3:devel/py-pydantic2@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}wheel-filename>=2.0<3:devel/py-wheel-filename@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
