PORTNAME=	protobuf
PORTVERSION=	4.21.9
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google protobuf Python Client Library
WWW=		https://github.com/protocolbuffers/protobuf

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protoc:devel/protobuf

USES=		cpe python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CPE_VENDOR=	google

.include <bsd.port.mk>
