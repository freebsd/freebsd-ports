PORTNAME=	aniso8601
PORTVERSION=	6.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	6

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for parsing ISO 8601 strings
WWW=		https://bitbucket.org/nielsenb/aniso8601/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils unittest

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.

.include <bsd.port.mk>
