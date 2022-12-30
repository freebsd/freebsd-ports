PORTNAME=	mypy-protobuf
PORTVERSION=	3.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate mypy stub files from protobuf specs
WWW=		https://github.com/nipunn1313/mypy-protobuf

LICENSE=	APACHE20

RUN_DEPENDS=	protobuf>=3.21.8,1:devel/protobuf \
		${PYTHON_PKGNAMEPREFIX}protobuf>=4.21.8,1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-protobuf>=3.20.4:devel/py-types-protobuf@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
