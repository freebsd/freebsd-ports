PORTNAME=	stone
PORTVERSION=	3.3.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Interface description language (IDL) for APIs
WWW=		https://github.com/dropbox/stone

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=21.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>=3.4:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/requirements.txt ${WRKSRC}/

.include <bsd.port.mk>
