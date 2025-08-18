PORTNAME=	pyliblo3
DISTVERSION=	0.16.3
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/gesellkammer/pyliblo3/commit/
PATCHFILES=	6b53ac0f1768f5f2f017b7011030ef6461366639.patch:-p1

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Python wrapper for the liblo OSC library
WWW=		https://github.com/gesellkammer/pyliblo3

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	liblo.so:audio/liblo

USES=		python
USE_PYTHON=	autoplist concurrent cython3 pep517

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${LOCALBASE}|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
