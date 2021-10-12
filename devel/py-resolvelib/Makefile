PORTNAME=	resolvelib
DISTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Resolve abstract dependencies into concrete ones

LICENSE=	ISCL

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	py${PYTHON_SUFFIX}-${PORTNAME}05 py${PYTHON_SUFFIX}-${PORTNAME}07

NO_ARCH=	yes

.include <bsd.port.mk>
