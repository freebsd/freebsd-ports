# $FreeBSD$

PORTNAME=	portalocker
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Python library that provides an easy API to file locking

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-extract:
	@${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>
