PORTNAME=	pdm-build-locked
PORTVERSION=	0.3.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pdm_build_locked-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add locked packages as additional optional dependency groups
WWW=		https://pdm-build-locked.readthedocs.io/en/stable/ \
		https://github.com/pdm-project/pdm-build-locked

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>=0:devel/py-pdm-backend@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=0:textproc/py-tomli@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
