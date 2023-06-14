PORTNAME=	resolvelib
DISTVERSION=	0.7.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	07

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Resolve abstract dependencies into concrete ones
WWW=		https://github.com/sarugaku/resolvelib

LICENSE=	ISCL

USES=		python
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}-${PORTNAME} ${PYTHON_PKGNAMEPREFIX}-${PORTNAME}05

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.7\.

.include <bsd.port.mk>
