PORTNAME=	pydantic-resolve
PORTVERSION=	1.12.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pydantic_resolve-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide pair of pre and post methods around pydantic fields
WWW=		https://allmonday.github.io/pydantic-resolve/introduction/ \
		https://github.com/allmonday/pydantic-resolve

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiodataloader>=0.4.0<0.5:databases/py-aiodataloader@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
