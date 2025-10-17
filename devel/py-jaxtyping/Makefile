PORTNAME=	jaxtyping
DISTVERSION=	0.3.3
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Type annotations & runtime checking for shape and dtype of JAX arrays
WWW=		https://docs.kidger.site/jaxtyping/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jax>0:math/py-jax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typeguard>=2.13.3:devel/py-typeguard@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
