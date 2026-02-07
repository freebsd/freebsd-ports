PORTNAME=	pysol-cards
PORTVERSION=	0.18.1
CATEGORIES=	games python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysol_cards-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Deal PySol FC Cards
WWW=		https://github.com/shlomif/pysol_cards

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
