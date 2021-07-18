PORTNAME=	resolvelib
DISTVERSION=	0.5.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	05

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Resolve abstract dependencies into concrete ones

LICENSE=	ISCL

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	py${PYTHON_SUFFIX}-${PORTNAME}

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.5\.

.include <bsd.port.mk>
