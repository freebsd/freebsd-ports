PORTNAME=	OpenCC
PORTVERSION=	1.3.2
CATEGORIES=	chinese python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	opencc-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Conversion between Traditional and Simplified Chinese
WWW=		https://github.com/BYVoid/OpenCC

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake-core>=0:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		compiler:c++17-lang python
USE_PYTHON=	autoplist concurrent pep517

.include <bsd.port.mk>
