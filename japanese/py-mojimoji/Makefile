PORTNAME=	mojimoji
DISTVERSION=	0.0.13
CATEGORIES=	japanese python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast converter between Japanese hankaku and zenkaku characters
WWW=		https://github.com/studio-ousia/mojimoji

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist concurrent

.include <bsd.port.mk>
