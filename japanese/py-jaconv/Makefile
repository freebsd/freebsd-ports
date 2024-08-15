PORTNAME=	jaconv
PORTVERSION=	0.4.0
CATEGORIES=	japanese python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Japanese character interconverter for Hiragana, Katakana, Hankaku, Zenkaku and more
WWW=		https://ikegami-yukino.github.io/jaconv/jaconv.html \
		https://github.com/ikegami-yukino/jaconv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
