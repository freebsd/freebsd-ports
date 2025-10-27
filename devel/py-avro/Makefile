PORTNAME=	avro
PORTVERSION=	1.12.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data serialization system for python
WWW=		https://avro.apache.org/ \
		https://github.com/apache/avro

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/avro/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=40.8.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CPE_VENDOR=	apache

OPTIONS_DEFINE=	SNAPPY ZSTANDARD
SNAPPY_DESC=	Snappy support
ZSTANDARD_DESC=	Zstandard support

SNAPPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-snappy>=0:archivers/py-python-snappy@${PY_FLAVOR}
ZSTANDARD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zstandard>=0:archivers/py-zstandard@${PY_FLAVOR}

.include <bsd.port.mk>
