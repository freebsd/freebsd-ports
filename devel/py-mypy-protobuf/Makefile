PORTNAME=	mypy-protobuf
PORTVERSION=	3.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate mypy stub files from protobuf specs

LICENSE=	APACHE20

RUN_DEPENDS=	protobuf>=3.19.4,1:devel/protobuf \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.19.4,1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-protobuf>=3.19.12:devel/py-types-protobuf@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
