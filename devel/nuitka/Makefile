PORTNAME=	nuitka
PORTVERSION=	2.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}
DISTNAME=	Nuitka-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Compatible and efficient Python compiler
WWW=		https://nuitka.net/ \
		https://github.com/Nuitka/Nuitka

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ordered-set>=4.1.0:devel/py-ordered-set@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstandard>=0.15:archivers/py-zstandard@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
