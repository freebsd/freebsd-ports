PORTNAME=	cucumber-tag-expressions
PORTVERSION=	9.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cucumber_tag_expressions-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide a tag-expression parser and evaluation logic for cucumber/behave
WWW=		https://github.com/cucumber/tag-expressions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.12:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	SOURCE_DATE_EPOCH=315532800 # 1980-01-01 00:00:00 UTC
NO_ARCH=	yes

.include <bsd.port.mk>
