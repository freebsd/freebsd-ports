PORTNAME=	tasklib
DISTVERSION=	2.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry.dussuet@protonmail.com
COMMENT=	Python library for interacting with taskwarrior databases

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	task:deskutils/taskwarrior

USES=		python:3.5+,run
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes
.include <bsd.port.mk>
