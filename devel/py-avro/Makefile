# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avro
PORTVERSION=	1.9.2
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data serialization system for python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/src/avro/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isort>=0:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>=0:devel/py-pycodestyle@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	SNAPPY ZSTANDARD
SNAPPY_DESC=	Snappy support
ZSTANDARD_DESC=	Zstandard support

SNAPPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-snappy>=0:archivers/py-python-snappy@${PY_FLAVOR}
ZSTANDARD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zstandard>=0:archivers/py-zstandard@${PY_FLAVOR}

.include <bsd.port.mk>
