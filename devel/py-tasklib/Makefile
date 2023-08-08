PORTNAME=	tasklib
DISTVERSION=	2.5.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry.dussuet@protonmail.com
COMMENT=	Python library for interacting with taskwarrior databases
WWW=		https://pypi.org/project/tasklib/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	task:deskutils/taskwarrior

USES=		python:run
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
.include <bsd.port.mk>
