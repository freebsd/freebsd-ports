PORTNAME=	resolvelib
DISTVERSION=	0.7.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	07

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Resolve abstract dependencies into concrete ones

LICENSE=	ISCL

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	py${PYTHON_SUFFIX}-${PORTNAME} py${PYTHON_SUFFIX}-${PORTNAME}05

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.7\.

.include <bsd.port.mk>
