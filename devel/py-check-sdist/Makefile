PORTNAME=	check-sdist
PORTVERSION=	0.1.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	check_sdist-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Check the contents of an sdist vs git
WWW=		https://github.com/henryiii/check-sdist

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>=0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0:devel/py-pathspec@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=0:devel/py-importlib-resources@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
