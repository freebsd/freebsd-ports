PORTNAME=	cucumber-tag-expressions
PORTVERSION=	8.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cucumber_tag_expressions-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide a tag-expression parser and evaluation logic for cucumber/behave
WWW=		https://github.com/cucumber/tag-expressions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.9.0<0.10.0:devel/py-uv-build@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
