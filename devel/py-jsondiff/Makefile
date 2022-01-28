# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	jsondiff
PORTVERSION=	1.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Diff JSON and JSON-like structures in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS_INSTALL=	jojodiff py*-jsonpatch # bin/jdiff bin/jsondiff

NO_ARCH=	yes

.include <bsd.port.mk>
