PORTNAME=	aniso8601
PORTVERSION=	6.0.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	6

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for parsing ISO 8601 strings

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m unittest -v

.include <bsd.port.mk>
