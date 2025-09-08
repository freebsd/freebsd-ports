PORTNAME=	cucumber-expressions
PORTVERSION=	18.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cucumber_expressions-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cucumber Expressions - a simpler alternative to Regular Expressions
WWW=		https://github.com/cucumber/cucumber-expressions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
