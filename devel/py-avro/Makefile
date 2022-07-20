PORTNAME=	avro
PORTVERSION=	1.11.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data serialization system for python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/avro/LICENSE

USES=		cpe python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CPE_VENDOR=	apache

OPTIONS_DEFINE=	SNAPPY ZSTANDARD
SNAPPY_DESC=	Snappy support
ZSTANDARD_DESC=	Zstandard support

SNAPPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-snappy>=0:archivers/py-python-snappy@${PY_FLAVOR}
ZSTANDARD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zstandard>=0:archivers/py-zstandard@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
