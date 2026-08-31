PORTNAME=	cucumber-expressions
PORTVERSION=	20.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cucumber_expressions-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cucumber Expressions - a simpler alternative to Regular Expressions
WWW=		https://github.com/cucumber/cucumber-expressions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.12:devel/py-flit-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	SOURCE_DATE_EPOCH=315532800 # 1980-01-01 00:00:00 UTC
NO_ARCH=	yes

.include <bsd.port.mk>
