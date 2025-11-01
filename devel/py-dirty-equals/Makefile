PORTNAME=	dirty-equals
PORTVERSION=	0.10.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dirty_equals-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Do dirty (but extremely useful) things with equals
WWW=		https://dirty-equals.helpmanual.io/latest/ \
		https://github.com/samuelcolvin/dirty-equals

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
